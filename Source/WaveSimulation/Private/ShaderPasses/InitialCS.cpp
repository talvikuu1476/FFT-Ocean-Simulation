// Fill out your copyright notice in the Description page of Project Settings.


#include "ShaderPasses/InitialCS.h"
#include "EngineSubsystem/WaveEngineSubsystem.h"
#include "HelperFunctions.h"
#include "ShaderCompilerCore.h"
#include "RenderGraphUtils.h"
#include "Engine/TextureRenderTarget2D.h"

void FConjugateCS::H0Pass(
	FRDGBuilder& GraphBuilder,
	UWaveEngineSubsystem* Subsystem)
{

	TObjectPtr<UTextureRenderTarget2D> RenderTarget_H0 = Subsystem->GetRenderTargetByName("H0");
	if (RenderTarget_H0 == nullptr)
	{
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

	/*
	// test if the textures are valid
	TObjectPtr<UTexture2D> H0KTextureOrigin = Subsystem->GetTextureByName("H0K");
	if (!H0KTextureOrigin)
	{
		UE_LOG(LogTemp, Error, TEXT("Failed to load H0KTextureOrigin."));
		return;
	}

	FRHITexture* H0KTextureRHI = H0KTextureOrigin->GetResource()->GetTexture2DRHI();
	FRDGTextureRef H0KTexture = nullptr;
	if (H0KTextureRHI)
	{
		H0KTexture = GraphBuilder.RegisterExternalTexture(
			CreateRenderTarget(H0KTextureRHI, TEXT("H0KTextureRT"))
		);
	}
	*/
	
	HelperFunctions Helper;

	// get H0K_RenderTarget
	UTextureRenderTarget2D* RenderTarget_H0K = Subsystem->GetRenderTargetByName("H0K");
	if (!RenderTarget_H0K)
	{
		UE_LOG(LogTemp, Error, TEXT("Failed to get RenderTarget_H0K render target."));
		return;
	}

	// register RenderTarget_H0K as RDG texture
	FRDGTextureRef H0KTexture = Helper.RegisterExternalRenderTarget(
		GraphBuilder, RenderTarget_H0K, TEXT("RenderTarget_H0K"));
	

	FRDGTextureSRVRef H0KTextureSRV = GraphBuilder.CreateSRV(FRDGTextureSRVDesc::Create(H0KTexture));

	uint32 Size = 256;

	FRDGTextureDesc H0Desc = FRDGTextureDesc::Create2D(
		FIntPoint(Size, Size),
		PF_A32B32G32R32F,
		FClearValueBinding::Black,
		TexCreate_ShaderResource | TexCreate_UAV);

	FRDGTextureRef H0Texture = GraphBuilder.CreateTexture(H0Desc, TEXT("H0Output"));

	FRDGTextureUAVRef H0UAV = GraphBuilder.CreateUAV(FRDGTextureUAVDesc(H0Texture));

	FConjugateCS::FParameters* Parameters = GraphBuilder.AllocParameters<FConjugateCS::FParameters>();
	Parameters->H0KTexture = H0KTextureSRV;
	Parameters->H0 = H0UAV;
	Parameters->Size = Size;

	FRDGTextureRef H0Target = nullptr;
	if (RenderTarget_H0 && RenderTarget_H0->GetResource())
	{
		H0Target = GraphBuilder.RegisterExternalTexture(
			CreateRenderTarget(RenderTarget_H0->GetRenderTargetResource()->GetRenderTargetTexture(), TEXT("RT_H0")));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("RenderTarget_H0 is null or has no resource."));
		return;
	}

	TShaderMapRef<FConjugateCS> ConjugateCS(GlobalShaderMap);
	FComputeShaderUtils::AddPass(
		GraphBuilder,
		RDG_EVENT_NAME("ConjugateCS"),
		ConjugateCS,
		Parameters,
		FComputeShaderUtils::GetGroupCount(FIntPoint(Size, Size), FIntPoint(16, 16))
	);

	AddCopyTexturePass(GraphBuilder, H0Texture, H0Target);
}


IMPLEMENT_GLOBAL_SHADER(FConjugateCS, "/WaveSimulation/InitialSpectrum.usf", "CalculateConjugatedSpectrum", SF_Compute);