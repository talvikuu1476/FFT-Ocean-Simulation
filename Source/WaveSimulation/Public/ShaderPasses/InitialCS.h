// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DataDrivenShaderPlatformInfo.h"
#include "PostProcess/PostProcessInputs.h"
#include "GlobalShader.h"
#include "ShaderParameterUtils.h"
#include "RHIStaticStates.h"
#include "RenderGraphDefinitions.h"
#include "ShaderParameterStruct.h"



// parameter struct for conjugate spectrum computation
BEGIN_SHADER_PARAMETER_STRUCT(FConjugateCSParameters, )
    // inputs
    SHADER_PARAMETER_RDG_TEXTURE_SRV(Texture2D<float2>, H0KTexture)

    // outputs (conjugate spectrum)
    SHADER_PARAMETER_RDG_TEXTURE_UAV(RWTexture2D<float4>, H0)
    SHADER_PARAMETER(uint32, Size)
END_SHADER_PARAMETER_STRUCT()

/**
 * Conjugate Spectrum Compute Shader
 */
class UWaveEngineSubsystem;
class WAVESIMULATION_API FConjugateCS : public FGlobalShader
{
    DECLARE_GLOBAL_SHADER(FConjugateCS);
    SHADER_USE_PARAMETER_STRUCT(FConjugateCS, FGlobalShader);

public:
    using FParameters = FConjugateCSParameters;
    
    static bool ShouldCompilePermutation(const FGlobalShaderPermutationParameters& Parameters)
    {
        return IsFeatureLevelSupported(Parameters.Platform, ERHIFeatureLevel::SM5);
    }
    
    static void ModifyCompilationEnvironment(const FGlobalShaderPermutationParameters& Parameters, FShaderCompilerEnvironment& OutEnvironment)
    {
        FGlobalShader::ModifyCompilationEnvironment(Parameters, OutEnvironment);
    }

    void H0Pass(FRDGBuilder& GraphBuilder, UWaveEngineSubsystem* Subsystem);
};