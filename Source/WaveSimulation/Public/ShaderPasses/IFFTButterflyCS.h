// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ShaderParameterStruct.h"

BEGIN_SHADER_PARAMETER_STRUCT(FIFFTButterflyCSParameters, )
    // inputs
    SHADER_PARAMETER_RDG_TEXTURE_SRV(Texture2D<float4>, PrecomputedTwiddle)
    SHADER_PARAMETER_RDG_TEXTURE_SRV(Texture2D<float2>, InputData)

    // outputs
    SHADER_PARAMETER_RDG_TEXTURE_UAV(RWTexture2D<float4>, OutputData)

    // uniforms
    SHADER_PARAMETER(uint32, Step)
    SHADER_PARAMETER(uint32, Dir)
END_SHADER_PARAMETER_STRUCT()

class UWaveEngineSubsystem;

/**
 * IFFT Butterfly Compute Shader
 */
class WAVESIMULATION_API FIFFTButterflyCS : public FGlobalShader
{
    DECLARE_GLOBAL_SHADER(FIFFTButterflyCS);
    SHADER_USE_PARAMETER_STRUCT(FIFFTButterflyCS, FGlobalShader);
public:
    using FParameters = FIFFTButterflyCSParameters;

    static bool ShouldCompilePermutation(const FGlobalShaderPermutationParameters& Parameters)
    {
        return IsFeatureLevelSupported(Parameters.Platform, ERHIFeatureLevel::SM5);
    }

    static void ModifyCompilationEnvironment(const FGlobalShaderPermutationParameters& Parameters, FShaderCompilerEnvironment& OutEnvironment)
    {
        FGlobalShader::ModifyCompilationEnvironment(Parameters, OutEnvironment);
    }

    void IFFTButterflyPass(FRDGBuilder& GraphBuilder, UWaveEngineSubsystem* Subsystem);

private:
    void IFFTButterflyProcess(
        FRDGBuilder& GraphBuilder,
        FRDGTextureSRV* TwiddleSRV,
        FRDGTextureSRV* InputSRV,
        FRDGTextureUAV* OutputUAV,
        uint32 Step,
        uint32 Dir);

    
};