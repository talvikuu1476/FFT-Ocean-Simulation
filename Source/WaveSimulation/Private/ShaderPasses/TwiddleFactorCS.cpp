// Fill out your copyright notice in the Description page of Project Settings.


#include "ShaderPasses/TwiddleFactorCS.h"
#include "EngineSubsystem/WaveEngineSubsystem.h"
#include "ShaderCompilerCore.h"
#include "RenderGraphUtils.h"
#include "Engine/TextureRenderTarget2D.h"

void FTwiddleFactorCS::TwiddleFactorPass(
	FRDGBuilder& GraphBuilder,
	UWaveEngineSubsystem* Subsystem)
{
	TObjectPtr<UTextureRenderTarget2D> RenderTarget_Twiddle = Subsystem->GetRenderTargetByName("TwiddleFactor");
	if (RenderTarget_Twiddle == nullptr)
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

	// create RDG texture for output
	uint32 Size = 256;
	FRDGTextureDesc TwiddleDesc = FRDGTextureDesc::Create2D(
		FIntPoint(8, Size),
		PF_A32B32G32R32F,
		FClearValueBinding::Black,
		TexCreate_ShaderResource | TexCreate_UAV);
	FRDGTextureRef TwiddleTexture = GraphBuilder.CreateTexture(TwiddleDesc, TEXT("TwiddleOutput"));
	FRDGTextureUAVRef TwiddleUAV = GraphBuilder.CreateUAV(FRDGTextureUAVDesc(TwiddleTexture));

	// set up shader parameters
	FTwiddleFactorCS::FParameters* Parameters = GraphBuilder.AllocParameters<FTwiddleFactorCS::FParameters>();
	Parameters->OutputSurface0 = TwiddleUAV;
	Parameters->Size = Size;

	// register render target for final output
	FRDGTextureRef TwiddleTarget = nullptr;
	if (RenderTarget_Twiddle && RenderTarget_Twiddle->GetResource())
	{
		TwiddleTarget = GraphBuilder.RegisterExternalTexture(
			CreateRenderTarget(RenderTarget_Twiddle->GetRenderTargetResource()->GetRenderTargetTexture(), TEXT("RT_Twiddle")));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("RenderTarget_Twiddle is null or has no resource."));
		return;
	}

	int SizeInt = Size;
	// execute compute shader
	TShaderMapRef<FTwiddleFactorCS> TwiddleFactorCS(GlobalShaderMap);
	FComputeShaderUtils::AddPass(
		GraphBuilder,
		RDG_EVENT_NAME("TwiddleFactorCS"),
		TwiddleFactorCS,
		Parameters,
		FComputeShaderUtils::GetGroupCount(FIntPoint(8, 256), FIntPoint(8, 8))
	);

	// copy result to final render target
	AddCopyTexturePass(GraphBuilder, TwiddleTexture, TwiddleTarget);
}

IMPLEMENT_SHADER_TYPE(, FTwiddleFactorCS, TEXT("/WaveSimulation/TwiddleFactor.usf"), TEXT("CalculateTwiddleFactor"), SF_Compute);

