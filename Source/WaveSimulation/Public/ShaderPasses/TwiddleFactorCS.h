// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DataDrivenShaderPlatformInfo.h"
#include "PostProcess/PostProcessInputs.h"

/**
 * 
 */
BEGIN_SHADER_PARAMETER_STRUCT(TwiddleFactorCS, )
	// inputs
	SHADER_PARAMETER(uint32, Size)

	// outputs
	SHADER_PARAMETER_RDG_TEXTURE_UAV(RWTexture2D<float4>, OutputSurface0)

END_SHADER_PARAMETER_STRUCT()

class UWaveEngineSubsystem;

class WAVESIMULATION_API FTwiddleFactorCS : public FGlobalShader
{
	DECLARE_EXPORTED_SHADER_TYPE(FTwiddleFactorCS, Global, );
	SHADER_USE_PARAMETER_STRUCT(FTwiddleFactorCS, FGlobalShader);

public:
	using FParameters = TwiddleFactorCS;

	static bool ShouldCompilePermutation(const FGlobalShaderPermutationParameters& Parameters)
	{
		return IsFeatureLevelSupported(Parameters.Platform, ERHIFeatureLevel::SM5);
	}
	static void ModifyCompilationEnvironment(
		const FGlobalShaderPermutationParameters& Parameters,
		FShaderCompilerEnvironment& OutEnvironment)
	{
		FGlobalShader::ModifyCompilationEnvironment(Parameters, OutEnvironment);
		OutEnvironment.CompilerFlags.Add(CFLAG_AllowTypedUAVLoads);
	}

	void TwiddleFactorPass(
		FRDGBuilder& GraphBuilder,
		UWaveEngineSubsystem* Subsystem);
};

