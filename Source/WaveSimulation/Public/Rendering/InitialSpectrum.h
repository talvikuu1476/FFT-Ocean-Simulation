// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GlobalShader.h"
#include "ShaderParameterStruct.h"
#include "BlueprintFunctionLibrary/InitialBlueprintFunctionLibrary.h"


// parameter struct for initial spectrum generation
BEGIN_SHADER_PARAMETER_STRUCT(FInitialSpectrumCSParameters, )
	// inputs
	SHADER_PARAMETER_RDG_TEXTURE_SRV(Texture2D<float2>, NoiseTexture)

	// outputs
	SHADER_PARAMETER_RDG_TEXTURE_UAV(RWTexture2D<float2>, H0K)
	SHADER_PARAMETER_RDG_TEXTURE_UAV(RWTexture2D<float4>, WavesData)

	// uniforms
	SHADER_PARAMETER(uint32, Size)
	SHADER_PARAMETER(float, LengthScale)
	SHADER_PARAMETER(float, CutoffHigh)
	SHADER_PARAMETER(float, CutoffLow)
	SHADER_PARAMETER(float, GravityAcceleration)
	SHADER_PARAMETER(float, Depth)

	// structured buffer
	SHADER_PARAMETER_RDG_BUFFER_SRV(StructuredBuffer<FSpectrumParameters>, Spectrums)
END_SHADER_PARAMETER_STRUCT()

/**
 *
 */
class WAVESIMULATION_API FInitialSpectrum : public FGlobalShader
{
	DECLARE_GLOBAL_SHADER(FInitialSpectrum);
	SHADER_USE_PARAMETER_STRUCT(FInitialSpectrum, FGlobalShader);

public:
	using FParameters = FInitialSpectrumCSParameters;

	static bool ShouldCompilePermutation(const FGlobalShaderPermutationParameters& Parameters)
	{
		return IsFeatureLevelSupported(Parameters.Platform, ERHIFeatureLevel::SM5);
	}

	static void ModifyCompilationEnvironment(const FGlobalShaderPermutationParameters& Parameters, FShaderCompilerEnvironment& OutEnvironment)
	{
		FGlobalShader::ModifyCompilationEnvironment(Parameters, OutEnvironment);
		OutEnvironment.CompilerFlags.Add(CFLAG_AllowTypedUAVLoads);
	}

	void DrawToRenderTargetWithParams(
		UTextureRenderTarget2D* RenderTarget_H0K,
		UTextureRenderTarget2D* RenderTarget_WavesData,
		UTexture2D* NoiseTexture,
		TArray<FSpectrumParameters>& SpectrumData,
		uint32 Size,
		float WaveLengthScale,
		float WaveCutoffHigh,
		float WaveCutoffLow,
		float WaveGravityAcceleration,
		float WaveDepth); // game thread

private:
	void DrawToRenderTargetWithParams_RenderThread(
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
		float WaveDepth);


};
