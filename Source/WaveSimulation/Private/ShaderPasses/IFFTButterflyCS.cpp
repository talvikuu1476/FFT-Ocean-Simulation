// Fill out your copyright notice in the Description page of Project Settings.

#include "ShaderPasses/IFFTButterflyCS.h"
#include "EngineSubsystem/WaveEngineSubsystem.h"
#include "HelperFunctions.h"
#include "ShaderCompilerCore.h"
#include "RenderGraphUtils.h"
#include "Engine/TextureRenderTarget2D.h"

void FIFFTButterflyCS::IFFTButterflyPass(FRDGBuilder& GraphBuilder, UWaveEngineSubsystem* Subsystem)
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

    UTextureRenderTarget2D* TwiddleFactor_RenderTarget = Subsystem->GetRenderTargetByName("TwiddleFactor");
    if (!TwiddleFactor_RenderTarget)
    {
        UE_LOG(LogTemp, Error, TEXT("Failed to get TwiddleFactor_RenderTarget render target."));
        return;
    }

    FRDGTextureRef TwiddleFactorTexture = Helper.RegisterExternalRenderTarget(
        GraphBuilder, TwiddleFactor_RenderTarget, TEXT("TwiddleFactor"));

    // create SRV for twiddle texture
    FRDGTextureSRVRef TwiddleSRV = Helper.CreateSRVIfValid(GraphBuilder, TwiddleFactorTexture);
    
    FRDGTextureDesc BufferDesc = FRDGTextureDesc::Create2D(
        FIntPoint(256, 256),
        PF_G32R32F,
        FClearValueBinding::None,
        ETextureCreateFlags::ShaderResource | ETextureCreateFlags::UAV
    );
    
    FRDGTextureRef Buffer0 = GraphBuilder.CreateTexture(BufferDesc, TEXT("Buffer0IFFT"));
    FRDGTextureRef Buffer1 = GraphBuilder.CreateTexture(BufferDesc, TEXT("Buffer1IFFT"));

    // get output textures
    FRDGTextureRef DxDz_I = Helper.RegisterExternalRenderTarget(
        GraphBuilder, Subsystem->GetRenderTargetByName("DxDz_I"), TEXT("DxDzIFFT"));
    FRDGTextureRef DyDxz_I = Helper.RegisterExternalRenderTarget(
        GraphBuilder, Subsystem->GetRenderTargetByName("DyDxz_I"), TEXT("DyDxzIFFT"));
    FRDGTextureRef DyxDyz_I = Helper.RegisterExternalRenderTarget(
        GraphBuilder, Subsystem->GetRenderTargetByName("DyxDyz_I"), TEXT("DyxDyzIFFT"));
    FRDGTextureRef DxxDzz_I = Helper.RegisterExternalRenderTarget(
        GraphBuilder, Subsystem->GetRenderTargetByName("DxxDzz_I"), TEXT("DxxDzzIFFT"));

    // get input textures
    FRDGTextureRef DxDz = Helper.RegisterExternalRenderTarget(
        GraphBuilder, Subsystem->GetRenderTargetByName("DxDz"), TEXT("DxDz"));
    FRDGTextureRef DyDxz = Helper.RegisterExternalRenderTarget(
        GraphBuilder, Subsystem->GetRenderTargetByName("DyDxz"), TEXT("DyDxz"));
    FRDGTextureRef DyxDyz = Helper.RegisterExternalRenderTarget(
        GraphBuilder, Subsystem->GetRenderTargetByName("DyxDyz"), TEXT("DyxDyz"));
    FRDGTextureRef DxxDzz = Helper.RegisterExternalRenderTarget(
        GraphBuilder, Subsystem->GetRenderTargetByName("DxxDzz"), TEXT("DxxDzz"));

    // create SRV and UAV for pingpong buffers
    FRDGTextureSRVRef Buffer0SRV = GraphBuilder.CreateSRV(FRDGTextureSRVDesc::Create(Buffer0));
    FRDGTextureUAVRef Buffer0UAV = GraphBuilder.CreateUAV(FRDGTextureUAVDesc(Buffer0));
    FRDGTextureSRVRef Buffer1SRV = GraphBuilder.CreateSRV(FRDGTextureSRVDesc::Create(Buffer1));
    FRDGTextureUAVRef Buffer1UAV = GraphBuilder.CreateUAV(FRDGTextureUAVDesc(Buffer1));

    // define input-output pairs for IFFT processing
    struct IFFTProcessPair
    {
        FRDGTextureRef InputTexture;
        FRDGTextureRef OutputTexture;
        const TCHAR* Name;
    };

    TArray<IFFTProcessPair> ProcessPairs = {
        {DxDz, DxDz_I, TEXT("DxDz")},
        {DyDxz, DyDxz_I, TEXT("DyDxz")},
        {DyxDyz, DyxDyz_I, TEXT("DyxDyz")},
        {DxxDzz, DxxDzz_I, TEXT("DxxDzz")}
    };

    uint32 Size = 256; // texture size
    uint32 LogSize = FMath::FloorLog2(Size);

    // process each frequency data through IFFT butterfly
    for (const auto& Pair : ProcessPairs)
    {
        if (!Pair.InputTexture || !Pair.OutputTexture)
        {
            UE_LOG(LogTemp, Warning, TEXT("Skipping IFFT for %s - missing textures"), Pair.Name);
            continue;
        }

        UE_LOG(LogTemp, Log, TEXT("Processing IFFT for %s"), Pair.Name);

        // copy input data to buffer0 to start the process
        AddCopyTexturePass(GraphBuilder, Pair.InputTexture, Buffer0);

        // process 2 directions separately
        FRDGTextureRef CurrentInput = Buffer0;
        FRDGTextureRef CurrentOutput = Buffer1;

        // horizontal IFFT
        for (uint32 Step = 0; Step < LogSize; ++Step)
        {
            FRDGTextureSRVRef InputSRV = GraphBuilder.CreateSRV(FRDGTextureSRVDesc::Create(CurrentInput));
            FRDGTextureUAVRef OutputUAV = GraphBuilder.CreateUAV(FRDGTextureUAVDesc(CurrentOutput));

            IFFTButterflyProcess(
                GraphBuilder,
                TwiddleSRV,
                InputSRV,
                OutputUAV,
                Step,
                0
            );

            // swap buffers
            FRDGTextureRef Temp = CurrentInput;
            CurrentInput = CurrentOutput;
            CurrentOutput = Temp;
        }

        // vertical IFFT
        for (uint32 Step = 0; Step < LogSize; ++Step)
        {
            FRDGTextureSRVRef InputSRV = GraphBuilder.CreateSRV(FRDGTextureSRVDesc::Create(CurrentInput));
            FRDGTextureUAVRef OutputUAV = GraphBuilder.CreateUAV(FRDGTextureUAVDesc(CurrentOutput));

            IFFTButterflyProcess(
                GraphBuilder,
                TwiddleSRV,
                InputSRV,
                OutputUAV,
                Step,
                1
            );

            // swap buffers
            FRDGTextureRef Temp = CurrentInput;
            CurrentInput = CurrentOutput;
            CurrentOutput = Temp;
        }

        // copy the result to the output texture
        AddCopyTexturePass(GraphBuilder, CurrentInput, Pair.OutputTexture);
        
        UE_LOG(LogTemp, Log, TEXT("Completed IFFT for %s"), Pair.Name);
    }
}

void FIFFTButterflyCS::IFFTButterflyProcess(
    FRDGBuilder& GraphBuilder,
    FRDGTextureSRV* TwiddleSRV,
    FRDGTextureSRV* InputSRV,
    FRDGTextureUAV* OutputUAV,
    uint32 Step,
    uint32 Dir
)
{
    check(TwiddleSRV);
    check(InputSRV);
    check(OutputUAV);

    // get shader references
    const FGlobalShaderMap* GlobalShaderMap = GetGlobalShaderMap(GMaxRHIFeatureLevel);
    TShaderMapRef<FIFFTButterflyCS> ButterflyCS(GlobalShaderMap);

    // set up shader parameters
    FIFFTButterflyCS::FParameters* Parameters = GraphBuilder.AllocParameters<FIFFTButterflyCS::FParameters>();
    Parameters->PrecomputedTwiddle = TwiddleSRV;
    Parameters->InputData = InputSRV;
    Parameters->OutputData = OutputUAV;
    Parameters->Step = Step;
    Parameters->Dir = Dir;

    UE_LOG(LogTemp, VeryVerbose, TEXT("IFFT Butterfly - Step: %d, Dir: %d"), Step, Dir);

    // run the compute shader
    FComputeShaderUtils::AddPass(
        GraphBuilder,
        RDG_EVENT_NAME("IFFTButterflyCS_Step_%d_Dir_%d", Step, Dir),
        ButterflyCS,
        Parameters,
        FComputeShaderUtils::GetGroupCount(FIntPoint(256, 256), FIntPoint(8, 8))
    );
}


IMPLEMENT_GLOBAL_SHADER(FIFFTButterflyCS, "/WaveSimulation/IFFTButterfly.usf", "IFFTButterfly", SF_Compute);