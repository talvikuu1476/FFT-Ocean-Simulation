// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "InitialBlueprintFunctionLibrary.generated.h"

USTRUCT(BlueprintType)
struct FSpectrumParameters
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Wave Spectrum")
    float scale = 1.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Wave Spectrum")
    float angle = 0.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Wave Spectrum")
    float spreadBlend = 0.5f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Wave Spectrum")
    float swell = 0.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Wave Spectrum")
    float alpha = 0.0081f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Wave Spectrum")
    float peakOmega = 0.855f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Wave Spectrum")
    float gamma = 3.3f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Wave Spectrum")
    float shortWavesFade = 0.01f;
};


/**
 * Calculate H0K and WavesData (kx, kz, omega)
 */
UCLASS()
class WAVESIMULATION_API UInitialBlueprintFunctionLibrary : public UBlueprintFunctionLibrary
{
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintCallable, Category = "Wave Simulation")
    static void CalculateTMASpectrum(
        UObject* WorldContextObject,
        UTextureRenderTarget2D* RenderTarget_H0K,
        UTextureRenderTarget2D* RenderTarget_WavesData,
        TArray<FSpectrumParameters> SpectrumData,
        UTexture2D* NoiseTexture,
        int32 WaveSize = 256,
        float WaveLengthScale = 1000.0f,
        float WaveCutoffHigh = 10000.0f,
        float WaveCutoffLow = 0.0001f,
        float WaveGravityAcceleration = 981.0f,
        float WaveDepth = 50.0f);


};