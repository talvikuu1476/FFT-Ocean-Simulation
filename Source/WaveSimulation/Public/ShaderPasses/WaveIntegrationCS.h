// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ShaderParameterStruct.h"


BEGIN_SHADER_PARAMETER_STRUCT(FWaveIntegrationCSParameters, )
	// inputs
	SHADER_PARAMETER_RDG_TEXTURE_SRV(Texture2D<float2>, Dx_Dz)
	SHADER_PARAMETER_RDG_TEXTURE_SRV(Texture2D<float2>, Dy_Dxz)
	SHADER_PARAMETER_RDG_TEXTURE_SRV(Texture2D<float2>, Dyx_Dyz)
	SHADER_PARAMETER_RDG_TEXTURE_SRV(Texture2D<float2>, Dxx_Dzz)

	// outputs
	SHADER_PARAMETER_RDG_TEXTURE_UAV(RWTexture2D<float4>, Displacement)
	SHADER_PARAMETER_RDG_TEXTURE_UAV(RWTexture2D<float4>, Derivatives)
	// SHADER_PARAMETER_RDG_TEXTURE_UAV(RWTexture2D<float4>, Turbulence)

	// uniforms
	SHADER_PARAMETER(float, Choppiness)
	// SHADER_PARAMETER(float, DeltaTime)
END_SHADER_PARAMETER_STRUCT()

/**
 *
 */
class UWaveEngineSubsystem;
class WAVESIMULATION_API FWaveIntegrationCS : public FGlobalShader
{
	DECLARE_GLOBAL_SHADER(FWaveIntegrationCS);
	SHADER_USE_PARAMETER_STRUCT(FWaveIntegrationCS, FGlobalShader);
public:
	using FParameters = FWaveIntegrationCSParameters;

	static bool ShouldCompilePermutation(const FGlobalShaderPermutationParameters& Parameters)
	{
		return IsFeatureLevelSupported(Parameters.Platform, ERHIFeatureLevel::SM5);
	}

	static void ModifyCompilationEnvironment(const FGlobalShaderPermutationParameters& Parameters, FShaderCompilerEnvironment& OutEnvironment)
	{
		FGlobalShader::ModifyCompilationEnvironment(Parameters, OutEnvironment);
	}

	void WaveIntegrationPass(FRDGBuilder& GraphBuilder, UWaveEngineSubsystem* Subsystem);

private:

	void WaveIntegrationProcess(
		FRDGBuilder& GraphBuilder,
		FRDGTextureSRVRef DxDzSRV,
		FRDGTextureSRVRef DyDxzSRV,
		FRDGTextureSRVRef DyxDyzSRV,
		FRDGTextureSRVRef DxxDzzSRV,
		float Choppiness,
		FRDGTextureRef DisplacementTarget,
		FRDGTextureRef DerivativesTarget
	);
};
