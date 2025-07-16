// Fill out your copyright notice in the Description page of Project Settings.


#include "ShaderPasses/WaveIntegrationCS.h"
#include "EngineSubsystem/WaveEngineSubsystem.h"
#include "HelperFunctions.h"
#include "ShaderCompilerCore.h"
#include "RenderGraphUtils.h"

void FWaveIntegrationCS::WaveIntegrationProcess(
	FRDGBuilder& GraphBuilder,
	FRDGTextureSRVRef DxDzSRV,
	FRDGTextureSRVRef DyDxzSRV,
	FRDGTextureSRVRef DyxDyzSRV,
	FRDGTextureSRVRef DxxDzzSRV,
	float Choppiness,
	FRDGTextureRef DisplacementTarget,
	FRDGTextureRef DerivativesTarget
)
{
	HelperFunctions Helper;

	check(DxDzSRV && DyDxzSRV && DyxDyzSRV && DxxDzzSRV);

	// get shader references
	const FGlobalShaderMap* GlobalShaderMap = GetGlobalShaderMap(GMaxRHIFeatureLevel);
	TShaderMapRef<FWaveIntegrationCS> WaveIntegrationCS(GlobalShaderMap);

	// create temp textures
	FRDGTextureDesc OutputDesc = FRDGTextureDesc::Create2D(
		FIntPoint(256, 256),
		PF_A32B32G32R32F,
		FClearValueBinding::Black,
		TexCreate_ShaderResource | TexCreate_UAV
	);

	FRDGTextureRef DisplacementTexture = GraphBuilder.CreateTexture(OutputDesc, TEXT("WaveIntegration_Displacement"));
	FRDGTextureRef DerivativesTexture = GraphBuilder.CreateTexture(OutputDesc, TEXT("WaveIntegration_Derivatives"));
	// FRDGTextureRef TurbulenceTexture = GraphBuilder.CreateTexture(OutputDesc, TEXT("WaveIntegration_Turbulence"));

	// create UAVs 
	FRDGTextureUAVRef DisplacementUAV = Helper.CreateUAVIfValid(GraphBuilder, DisplacementTexture);
	FRDGTextureUAVRef DerivativesUAV = Helper.CreateUAVIfValid(GraphBuilder, DerivativesTexture);
	// FRDGTextureUAVRef TurbulenceUAV = Helper.CreateUAVIfValid(GraphBuilder, TurbulenceTexture);

	// create parameters
	FWaveIntegrationCS::FParameters* Parameters = GraphBuilder.AllocParameters<FWaveIntegrationCS::FParameters>();
	Parameters->Dx_Dz = DxDzSRV;
	Parameters->Dy_Dxz = DyDxzSRV;
	Parameters->Dyx_Dyz = DyxDyzSRV;
	Parameters->Dxx_Dzz = DxxDzzSRV;
	Parameters->Displacement = DisplacementUAV;
	Parameters->Derivatives = DerivativesUAV;
	Parameters->Choppiness = Choppiness;

	// run the compute shader
	FComputeShaderUtils::AddPass(
		GraphBuilder,
		RDG_EVENT_NAME("WaveIntegration"),
		WaveIntegrationCS,
		Parameters,
		FComputeShaderUtils::GetGroupCount(FIntPoint(256, 256), FIntPoint(8, 8))
	);

	// copy results to external render targets
	if (DisplacementTarget)
		AddCopyTexturePass(GraphBuilder, DisplacementTexture, DisplacementTarget);
	if (DerivativesTarget)
		AddCopyTexturePass(GraphBuilder, DerivativesTexture, DerivativesTarget);
	// if (TurbulenceTarget)
		// AddCopyTexturePass(GraphBuilder, TurbulenceTexture, TurbulenceTarget);


}

void FWaveIntegrationCS::WaveIntegrationPass(FRDGBuilder& GraphBuilder, UWaveEngineSubsystem* Subsystem)
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
		UE_LOG(LogTemp, Warning, TEXT("GlobalShaderMap is null."));
		return;
	}

	// get the render targets for input textures
	FRDGTextureRef DxDzTexture = Helper.RegisterExternalRenderTarget(
		GraphBuilder, Subsystem->GetRenderTargetByName("DxDz_I"), TEXT("DxDz_I"));
	FRDGTextureRef DyDxzTexture = Helper.RegisterExternalRenderTarget(
		GraphBuilder, Subsystem->GetRenderTargetByName("DyDxz_I"), TEXT("DyDxz_I"));
	FRDGTextureRef DyxDyzTexture = Helper.RegisterExternalRenderTarget(
		GraphBuilder, Subsystem->GetRenderTargetByName("DyxDyz_I"), TEXT("DyxDyz_I"));
	FRDGTextureRef DxxDzzTexture = Helper.RegisterExternalRenderTarget(
		GraphBuilder, Subsystem->GetRenderTargetByName("DxxDzz_I"), TEXT("DxxDzz_I"));

	// create SRVs for input textures
	FRDGTextureSRVRef DxDzSRV = Helper.CreateSRVIfValid(GraphBuilder, DxDzTexture);
	FRDGTextureSRVRef DyDxzSRV = Helper.CreateSRVIfValid(GraphBuilder, DyDxzTexture);
	FRDGTextureSRVRef DyxDyzSRV = Helper.CreateSRVIfValid(GraphBuilder, DyxDyzTexture);
	FRDGTextureSRVRef DxxDzzSRV = Helper.CreateSRVIfValid(GraphBuilder, DxxDzzTexture);

	// get the render targets for writing results
	FRDGTextureRef DisplacementTarget = Helper.RegisterExternalRenderTarget(
		GraphBuilder, Subsystem->GetRenderTargetByName("Displacement"), TEXT("Displacement"));
	FRDGTextureRef DerivativesTarget = Helper.RegisterExternalRenderTarget(
		GraphBuilder, Subsystem->GetRenderTargetByName("Derivatives"), TEXT("Derivatives"));
	// FRDGTextureRef TurbulenceTarget = Helper.RegisterExternalRenderTarget(
		// GraphBuilder, Subsystem->GetRenderTargetByName("Turbulence"), TEXT("Turbulence"));

	float Choppiness = 1.0f; // wave choppiness factor

	WaveIntegrationProcess(
		GraphBuilder,
		DxDzSRV,
		DyDxzSRV,
		DyxDyzSRV,
		DxxDzzSRV,
		Choppiness,
		DisplacementTarget,
		DerivativesTarget
	);



}

IMPLEMENT_GLOBAL_SHADER(FWaveIntegrationCS, "/WaveSimulation/WaveIntegration.usf", "WaveIntegration", SF_Compute);

