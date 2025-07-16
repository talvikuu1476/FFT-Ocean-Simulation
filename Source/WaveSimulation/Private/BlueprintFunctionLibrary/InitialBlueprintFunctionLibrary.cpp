// Fill out your copyright notice in the Description page of Project Settings.


#include "BlueprintFunctionLibrary/InitialBlueprintFunctionLibrary.h"
#include "Rendering/InitialSpectrum.h"
#include "Engine/World.h"
#include "Engine/Engine.h"

void UInitialBlueprintFunctionLibrary::CalculateTMASpectrum(
    UObject* WorldContextObject,
    UTextureRenderTarget2D* RenderTarget_H0K,
    UTextureRenderTarget2D* RenderTarget_WavesData,
    TArray<FSpectrumParameters> SpectrumData,
    UTexture2D* NoiseTexture,
    int32 WaveSize,
    float WaveLengthScale,
    float WaveCutoffHigh,
    float WaveCutoffLow,
    float WaveGravityAcceleration,
    float WaveDepth)
{
    if (!RenderTarget_H0K || !RenderTarget_WavesData)
    {
        UE_LOG(LogTemp, Warning, TEXT("RenderTarget_H0K or RenderTarget_WavesData is null while calling from BP."));
        return;
    }

    UWorld* World = GEngine->GetWorldFromContextObjectChecked(WorldContextObject);

    FInitialSpectrum H0KPass;
    H0KPass.DrawToRenderTargetWithParams(
        RenderTarget_H0K,
        RenderTarget_WavesData,
        NoiseTexture,
        SpectrumData,
        WaveSize,
        WaveLengthScale,
        WaveCutoffHigh,
        WaveCutoffLow,
        WaveGravityAcceleration,
        WaveDepth);
}
