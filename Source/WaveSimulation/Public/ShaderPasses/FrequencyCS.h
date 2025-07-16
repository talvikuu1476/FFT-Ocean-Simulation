// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ShaderParameterStruct.h"


BEGIN_SHADER_PARAMETER_STRUCT(FFrequencyCSParameters, )
    // inputs
    SHADER_PARAMETER_RDG_TEXTURE_SRV(Texture2D<float4>, H0)
    SHADER_PARAMETER_RDG_TEXTURE_SRV(Texture2D<float4>, WavesData)

    // outputs
    SHADER_PARAMETER_RDG_TEXTURE_UAV(RWTexture2D<float2>, Dx_Dz)
    SHADER_PARAMETER_RDG_TEXTURE_UAV(RWTexture2D<float2>, Dy_Dxz)
    SHADER_PARAMETER_RDG_TEXTURE_UAV(RWTexture2D<float2>, Dyx_Dyz)
    SHADER_PARAMETER_RDG_TEXTURE_UAV(RWTexture2D<float2>, Dxx_Dzz)

    SHADER_PARAMETER(float, Time)
END_SHADER_PARAMETER_STRUCT()


/**
 *
 */
class UWaveEngineSubsystem;
class WAVESIMULATION_API FFrequencyCS : public FGlobalShader
{
    DECLARE_GLOBAL_SHADER(FFrequencyCS);
    SHADER_USE_PARAMETER_STRUCT(FFrequencyCS, FGlobalShader);
public:
    using FParameters = FFrequencyCSParameters;
    static bool ShouldCompilePermutation(const FGlobalShaderPermutationParameters& Parameters)
    {
        return IsFeatureLevelSupported(Parameters.Platform, ERHIFeatureLevel::SM5);
    }

    static void ModifyCompilationEnvironment(const FGlobalShaderPermutationParameters& Parameters, FShaderCompilerEnvironment& OutEnvironment)
    {
        FGlobalShader::ModifyCompilationEnvironment(Parameters, OutEnvironment);
    }

    void FrequencyPass(FRDGBuilder& GraphBuilder, UWaveEngineSubsystem* Subsystem, float time);

private:
    void FrequencyProcess(
        FRDGBuilder& GraphBuilder,
        FRDGTextureSRV* H0SRV,
        FRDGTextureSRV* WavesDataSRV,
        FRDGTextureRef Dx_DzTarget,
        FRDGTextureRef Dy_DxzTarget,
        FRDGTextureRef Dyx_DyzTarget,
        FRDGTextureRef Dxx_DzzTarget,
        float Time
    );

};