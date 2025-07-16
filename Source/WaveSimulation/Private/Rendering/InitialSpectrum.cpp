#include "Rendering/InitialSpectrum.h"
#include "ShaderPasses/InitialCS.h"
#include "EngineSubsystem/WaveEngineSubsystem.h"
#include "PixelShaderUtils.h"
#include "SceneTexturesConfig.h"
#include "Engine/TextureRenderTarget2D.h"
#include "Engine/Texture2D.h"
#include "Rendering/Texture2DResource.h" // for converting UTexture2D to FTexture2DResource
#include "Runtime/Renderer/Private/SceneRendering.h"
#include "Runtime/Renderer/Private/SceneTextureParameters.h"
#include "Runtime/Renderer/Internal/PostProcess/PostProcessInputs.h"


void FInitialSpectrum::DrawToRenderTargetWithParams(
	UTextureRenderTarget2D* RenderTarget_H0K,
	UTextureRenderTarget2D* RenderTarget_WavesData,
	UTexture2D* NoiseTexture,
	TArray<FSpectrumParameters>& SpectrumData,
	uint32 Size,
	float WaveLengthScale,
	float WaveCutoffHigh,
	float WaveCutoffLow,
	float WaveGravityAcceleration,
	float WaveDepth)
{
	check(IsInGameThread());

	if (!RenderTarget_H0K || !RenderTarget_WavesData)
	{
		UE_LOG(LogTemp, Warning, TEXT("RenderTarget_H0K or RenderTarget_WavesData is null"));
		return;
	}

	// check if the SpectrumData is configured in the blueprint
	if (SpectrumData.Num() == 0)
	{
		UE_LOG(LogTemp, Warning, TEXT("SpectrumData is empty, using default parameters."));
		return;
	}

	// get RT resources
	FTextureRenderTargetResource* RenderTarget_H0K_Resource = RenderTarget_H0K->GameThread_GetRenderTargetResource();
	FTextureRenderTargetResource* RenderTarget_WavesData_Resource = RenderTarget_WavesData->GameThread_GetRenderTargetResource();
	if (!RenderTarget_H0K_Resource || !RenderTarget_WavesData_Resource)
	{
		UE_LOG(LogTemp, Warning, TEXT("RenderTarget_H0K_Resource or RenderTarget_WavesData_Resource is null"));
		return;
	}

	// get noise texture resource
	FTexture2DResource* NoiseTextureResource = nullptr;
	if (NoiseTexture && NoiseTexture->IsValidLowLevel())
	{
		FTextureResource* NoiseResource = NoiseTexture->GetResource();
		NoiseTextureResource = static_cast<FTexture2DResource*>(NoiseResource);
		if (!NoiseTextureResource)
		{
			UE_LOG(LogTemp, Warning, TEXT("Failed to cast FTextureResource to FTexture2DResource."));
		}
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Noise is null, invalid, or not a UTexture2D."));
	}

	// convert SpectrumData in blueprint to the render thread
	TArray<FSpectrumParameters> RenderThreadSpectrumData;
	RenderThreadSpectrumData.Reserve(SpectrumData.Num());
	for (const FSpectrumParameters& BlueprintParam : SpectrumData)
	{
		FSpectrumParameters RenderParam;
		RenderParam.scale = BlueprintParam.scale;
		RenderParam.angle = BlueprintParam.angle;
		RenderParam.spreadBlend = BlueprintParam.spreadBlend;
		RenderParam.swell = BlueprintParam.swell;
		RenderParam.alpha = BlueprintParam.alpha;
		RenderParam.peakOmega = BlueprintParam.peakOmega;
		RenderParam.gamma = BlueprintParam.gamma;
		RenderParam.shortWavesFade = BlueprintParam.shortWavesFade;

		RenderThreadSpectrumData.Add(RenderParam);
	}

	// enqueue render command to render thread with parameters
	ENQUEUE_RENDER_COMMAND(DrawComputeShaderToRenderTargetWithParams)(
		[this,
		RenderTarget_H0K_Resource,
		RenderTarget_WavesData_Resource,
		NoiseTextureResource,
		Size,
		WaveLengthScale,
		WaveCutoffHigh,
		WaveCutoffLow,
		WaveGravityAcceleration,
		WaveDepth,
		RenderThreadSpectrumData = MoveTemp(RenderThreadSpectrumData)](FRHICommandListImmediate& RHICmdList) mutable
		{
			this->DrawToRenderTargetWithParams_RenderThread(
				RHICmdList,
				RenderTarget_H0K_Resource,
				RenderTarget_WavesData_Resource,
				NoiseTextureResource,
				RenderThreadSpectrumData,
				Size,
				WaveLengthScale,
				WaveCutoffHigh,
				WaveCutoffLow,
				WaveGravityAcceleration,
				WaveDepth);
		});

}


void FInitialSpectrum::DrawToRenderTargetWithParams_RenderThread(
	FRHICommandListImmediate& RHICmdList,
	FTextureRenderTargetResource* RenderTarget_H0K_Resource,
	FTextureRenderTargetResource* RenderTarget_WavesData_Resource,
	FTexture2DResource* NoiseTextureResource,
	TArray<FSpectrumParameters>& SpectrumData,
	uint32 Size,
	float WaveLengthScale,
	float WaveCutoffHigh,
	float WaveCutoffLow,
	float WaveGravityAcceleration,
	float WaveDepth)
{
	check(IsInRenderingThread());

	if (!RenderTarget_H0K_Resource || !RenderTarget_WavesData_Resource)
	{
		UE_LOG(LogTemp, Warning, TEXT("RenderTarget_H0K_Resource or RenderTarget_WavesData_Resource is null."));
		return;
	}

	// create RDG builder
	FRDGBuilder GraphBuilder(RHICmdList);

	// register the render target texture
	FRDGTextureRef H0KTexture = GraphBuilder.RegisterExternalTexture(
		CreateRenderTarget(RenderTarget_H0K_Resource->GetRenderTargetTexture(), TEXT("H0K_Texture")));
	FRDGTextureRef WavesDataTexture = GraphBuilder.RegisterExternalTexture(
		CreateRenderTarget(RenderTarget_WavesData_Resource->GetRenderTargetTexture(), TEXT("WavesData_Texture")));

	// register noise texture if available
	FRDGTextureRef NoiseTexture = nullptr;
	if (NoiseTextureResource)
	{
		NoiseTexture = GraphBuilder.RegisterExternalTexture(
			CreateRenderTarget(NoiseTextureResource->GetTexture2DRHI(), TEXT("NoiseTexture")));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("NoiseTextureResource is null or invalid."));
	}

	const FGlobalShaderMap* GlobalShaderMap = GetGlobalShaderMap(GMaxRHIFeatureLevel);
	if (!GlobalShaderMap)
	{
		UE_LOG(LogTemp, Warning, TEXT("GlobalShaderMap is null."));
		return;
	}

	// recreate the compute shader textures and run the compute pass
	FRDGTextureDesc H0KDesc = FRDGTextureDesc::Create2D(
		FIntPoint(Size, Size),
		PF_G32R32F,
		FClearValueBinding::Black,
		TexCreate_ShaderResource | TexCreate_UAV);
	FRDGTextureDesc WavesDataDesc = FRDGTextureDesc::Create2D(
		FIntPoint(Size, Size),
		PF_A32B32G32R32F,
		FClearValueBinding::Black,
		TexCreate_ShaderResource | TexCreate_UAV);

	FRDGTextureRef H0KTextureTemp = GraphBuilder.CreateTexture(H0KDesc, TEXT("H0KTexture"));
	FRDGTextureUAVRef H0KUAV = GraphBuilder.CreateUAV(FRDGTextureUAVDesc(H0KTextureTemp));

	FRDGTextureRef WavesDataTextureTemp = GraphBuilder.CreateTexture(WavesDataDesc, TEXT("WavesDataTexture"));
	FRDGTextureUAVRef WavesDataUAV = GraphBuilder.CreateUAV(FRDGTextureUAVDesc(WavesDataTextureTemp));

	// create SRV for noise texture
	FRDGTextureSRVRef NoiseTextureSRV = nullptr;
	if (NoiseTexture)
	{
		NoiseTextureSRV = GraphBuilder.CreateSRV(FRDGTextureSRVDesc(NoiseTexture));
	}

	FRDGBufferRef SpectrumBuffer = CreateStructuredBuffer(
		GraphBuilder,
		TEXT("SpectrumBuffer"),
		sizeof(FSpectrumParameters),
		SpectrumData.Num(),
		SpectrumData.GetData(),
		sizeof(FSpectrumParameters) * SpectrumData.Num());

	FRDGBufferSRVRef SpectrumBufferSRV = GraphBuilder.CreateSRV(SpectrumBuffer);

	const FIntPoint WaveThreadCount = FIntPoint(Size, Size);
	const FIntVector WaveGroupCount = FComputeShaderUtils::GetGroupCount(WaveThreadCount, FIntPoint(16, 16));

	// run the compute shader
	FInitialSpectrum::FParameters* Parameters = GraphBuilder.AllocParameters<FInitialSpectrum::FParameters>();
	Parameters->NoiseTexture = NoiseTextureSRV;
	Parameters->WavesData = WavesDataUAV;
	Parameters->H0K = H0KUAV;
	Parameters->Size = Size;
	Parameters->LengthScale = WaveLengthScale;
	Parameters->CutoffHigh = WaveCutoffHigh;
	Parameters->CutoffLow = WaveCutoffLow;
	Parameters->GravityAcceleration = WaveGravityAcceleration;
	Parameters->Depth = WaveDepth;
	Parameters->Spectrums = SpectrumBufferSRV;

	TShaderMapRef<FInitialSpectrum> ComputeShader(GlobalShaderMap);
	FComputeShaderUtils::AddPass(
		GraphBuilder,
		RDG_EVENT_NAME("Initial Spectrum Compute Pass"),
		ERDGPassFlags::Compute,
		ComputeShader,
		Parameters,
		WaveGroupCount);


	// copy the computed result to the render target
	AddCopyTexturePass(GraphBuilder, WavesDataTextureTemp, WavesDataTexture, FRHICopyTextureInfo());
	AddCopyTexturePass(GraphBuilder, H0KTextureTemp, H0KTexture, FRHICopyTextureInfo());

	// execute the graph
	GraphBuilder.Execute();
}


IMPLEMENT_GLOBAL_SHADER(FInitialSpectrum, "/WaveSimulation/InitialSpectrum.usf", "CalculateInitialSpectrum", SF_Compute);

