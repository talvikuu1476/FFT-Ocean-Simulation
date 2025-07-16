// Fill out your copyright notice in the Description page of Project Settings.

#include "ShaderPasses/FrequencyCS.h"
#include "EngineSubsystem/WaveEngineSubsystem.h"
#include "HelperFunctions.h"
#include "ShaderCompilerCore.h"
#include "RenderGraphUtils.h"
#include "Engine/TextureRenderTarget2D.h"

void FFrequencyCS::FrequencyProcess(
	FRDGBuilder& GraphBuilder,
	FRDGTextureSRV* H0SRV,
	FRDGTextureSRV* WavesDataSRV,
	FRDGTextureRef Dx_DzTarget,
	FRDGTextureRef Dy_DxzTarget,
	FRDGTextureRef Dyx_DyzTarget,
	FRDGTextureRef Dxx_DzzTarget,
	float Time
)
{
	HelperFunctions Helper;
	check(H0SRV);

	// get shader references
	const FGlobalShaderMap* GlobalShaderMap = GetGlobalShaderMap(GMaxRHIFeatureLevel);
	TShaderMapRef<FFrequencyCS> FrequencyCS(GlobalShaderMap);

	// create temp textures
	FRDGTextureDesc Desc = FRDGTextureDesc::Create2D(
		FIntPoint(256, 256),
		PF_G32R32F,
		FClearValueBinding::Black,
		TexCreate_ShaderResource | TexCreate_UAV
	);

	FRDGTextureRef DxDzTexture = GraphBuilder.CreateTexture(Desc, TEXT("DxDzTexture"));
	FRDGTextureRef DyDxzTexture = GraphBuilder.CreateTexture(Desc, TEXT("DyDxzTexture"));
	FRDGTextureRef DyxDyzTexture = GraphBuilder.CreateTexture(Desc, TEXT("DyxDyzTexture"));
	FRDGTextureRef DxxDzzTexture = GraphBuilder.CreateTexture(Desc, TEXT("DxxDzzTexture"));

	// create UAVs for output textures
	FRDGTextureUAVRef DxDzUAV = Helper.CreateUAVIfValid(GraphBuilder, DxDzTexture);
	FRDGTextureUAVRef DyDxzUAV = Helper.CreateUAVIfValid(GraphBuilder, DyDxzTexture);
	FRDGTextureUAVRef DyxDyzUAV = Helper.CreateUAVIfValid(GraphBuilder, DyxDyzTexture);
	FRDGTextureUAVRef DxxDzzUAV = Helper.CreateUAVIfValid(GraphBuilder, DxxDzzTexture);

	// set up shader parameters
	FFrequencyCS::FParameters* Parameters = GraphBuilder.AllocParameters<FFrequencyCS::FParameters>();
	Parameters->H0 = H0SRV;
	Parameters->WavesData = WavesDataSRV;
	Parameters->Dx_Dz = DxDzUAV;
	Parameters->Dy_Dxz = DyDxzUAV;
	Parameters->Dyx_Dyz = DyxDyzUAV;
	Parameters->Dxx_Dzz = DxxDzzUAV;
	Parameters->Time = Time;

	// run the compute shader
	FComputeShaderUtils::AddPass(
		GraphBuilder,
		RDG_EVENT_NAME("FrequencyCS"),
		FrequencyCS,
		Parameters,
		FComputeShaderUtils::GetGroupCount(FIntPoint(256, 256), FIntPoint(8, 8))
	);

	// copy results to output render targets
	if (Dx_DzTarget)
		AddCopyTexturePass(GraphBuilder, DxDzTexture, Dx_DzTarget);
	if (Dy_DxzTarget)
		AddCopyTexturePass(GraphBuilder, DyDxzTexture, Dy_DxzTarget);
	if (Dyx_DyzTarget)
		AddCopyTexturePass(GraphBuilder, DyxDyzTexture, Dyx_DyzTarget);
	if (Dxx_DzzTarget)
		AddCopyTexturePass(GraphBuilder, DxxDzzTexture, Dxx_DzzTarget);
	
}

void FFrequencyCS::FrequencyPass(FRDGBuilder& GraphBuilder, UWaveEngineSubsystem* Subsystem, float time)
{
	HelperFunctions Helper;
	if (!Subsystem)
	{
		UE_LOG(LogTemp, Warning, TEXT("WaveEngineSubsystem is null."));
		return;
	}

	checkf(IsInRenderingThread() || IsInRHIThread(), TEXT("Cannot create from outside the rendering thread"));

	// get the global shader map
	const FGlobalShaderMap* GlobalShaderMap = GetGlobalShaderMap(GMaxRHIFeatureLevel);
	if (!GlobalShaderMap)
	{
		UE_LOG(LogTemp, Warning, TEXT("GlobalShaderMap is ull."));
		return;
	}
	
	// get RTs
	UTextureRenderTarget2D* H0_RenderTarget = Subsystem->GetRenderTargetByName("H0");
	if (!H0_RenderTarget)
	{
		UE_LOG(LogTemp, Error, TEXT("Failed to get H0_RenderTarget render target."));
		return;
	}
	UTextureRenderTarget2D* WavesData_RenderTarget = Subsystem->GetRenderTargetByName("WavesData");
	if (!WavesData_RenderTarget)
	{
		UE_LOG(LogTemp, Error, TEXT("Failed to get WavesData_RenderTarget render target."));
		return;
	}

	// register RTs as RDG textures
	FRDGTextureRef H0Texture = Helper.RegisterExternalRenderTarget(
		GraphBuilder, H0_RenderTarget, TEXT("H0_RT"));
	FRDGTextureRef WavesDataTexture = Helper.RegisterExternalRenderTarget(
		GraphBuilder, WavesData_RenderTarget, TEXT("WavesData_RT"));

	// create SRV for H0 texture
	FRDGTextureSRVRef H0SRV = Helper.CreateSRVIfValid(GraphBuilder, H0Texture);
	FRDGTextureSRVRef WavesDataSRV = Helper.CreateSRVIfValid(GraphBuilder, WavesDataTexture);

	// get the render targets for writing results
	FRDGTextureRef Dx_DzTarget = Helper.RegisterExternalRenderTarget(
		GraphBuilder, Subsystem->GetRenderTargetByName("DxDz"), TEXT("Dx_DzTarget"));
	FRDGTextureRef Dy_DxzTarget = Helper.RegisterExternalRenderTarget(
		GraphBuilder, Subsystem->GetRenderTargetByName("DyDxz"), TEXT("Dy_DxzTarget"));
	FRDGTextureRef Dyx_DyzTarget = Helper.RegisterExternalRenderTarget(
		GraphBuilder, Subsystem->GetRenderTargetByName("DyxDyz"), TEXT("Dyx_DyzTarget"));
	FRDGTextureRef Dxx_DzzTarget = Helper.RegisterExternalRenderTarget(
		GraphBuilder, Subsystem->GetRenderTargetByName("DxxDzz"), TEXT("Dxx_DzzTarget"));


	FrequencyProcess(
		GraphBuilder,
		H0SRV,
		WavesDataSRV,
		Dx_DzTarget,
		Dy_DxzTarget,
		Dyx_DyzTarget,
		Dxx_DzzTarget,
		time
	);
}

IMPLEMENT_GLOBAL_SHADER(FFrequencyCS, "/WaveSimulation/IFFTFrequency.usf", "CalculateFrequency", SF_Compute);