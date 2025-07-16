// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/EngineSubsystem.h"
#include "WaveEngineSubsystem.generated.h"

class FWaveSceneViewExtension;
class FTwiddleFactorSceneViewExtension;

/**
 *
 */

UCLASS()
class WAVESIMULATION_API UWaveEngineSubsystem : public UEngineSubsystem
{
	GENERATED_BODY()

private:
	TSharedPtr<FWaveSceneViewExtension, ESPMode::ThreadSafe> WaveSceneViewExtension;
	TSharedPtr<FTwiddleFactorSceneViewExtension, ESPMode::ThreadSafe> TwiddleFactorSceneViewExtension;

	/*
		============================FWaveSceneViewExtension============================
	*/
	UPROPERTY()
	TObjectPtr<UTextureRenderTarget2D> WaveRenderTarget = nullptr;

	/*
		============================Initial Spectrum Pass============================
	*/
	UPROPERTY()
	TObjectPtr<UTexture2D> H0KTexture = nullptr;

	UPROPERTY()
	TObjectPtr<UTexture2D> NoiseTexture = nullptr;

	UPROPERTY()
	TObjectPtr<UTextureRenderTarget2D> RenderTarget_H0K = nullptr;

	UPROPERTY()
	TObjectPtr<UTextureRenderTarget2D> RenderTarget_WavesData = nullptr;

	UPROPERTY()
	TObjectPtr<UTextureRenderTarget2D> RenderTarget_H0 = nullptr;

	/*
		============================FTwiddleFactorSceneViewExtension============================
	*/
	UPROPERTY()
	TObjectPtr<UTextureRenderTarget2D> TwiddleFactorRenderTarget = nullptr;

	/*
		============================Frequency Pass============================
	*/
	UPROPERTY()
	TObjectPtr<UTexture2D> H0Texture = nullptr;

	
	UPROPERTY()
	TObjectPtr<UTextureRenderTarget2D> RenderTarget_DxDz = nullptr;

	UPROPERTY()
	TObjectPtr<UTextureRenderTarget2D> RenderTarget_DyDxz = nullptr;

	UPROPERTY()
	TObjectPtr<UTextureRenderTarget2D> RenderTarget_DyxDyz = nullptr;

	UPROPERTY()
	TObjectPtr<UTextureRenderTarget2D> RenderTarget_DxxDzz = nullptr;

	/*
		============================IFFT Butterfly Pass============================
	*/
	UPROPERTY()
	TObjectPtr<UTexture2D> TwiddleFactorTexture = nullptr;

	UPROPERTY()
	TObjectPtr<UTextureRenderTarget2D> RenderTarget_Buffer0 = nullptr;

	UPROPERTY()
	TObjectPtr<UTextureRenderTarget2D> RenderTarget_Buffer1 = nullptr;

	UPROPERTY()
	TObjectPtr<UTextureRenderTarget2D> RenderTarget_DxDz_I = nullptr;

	UPROPERTY()
	TObjectPtr<UTextureRenderTarget2D> RenderTarget_DyDxz_I = nullptr;

	UPROPERTY()
	TObjectPtr<UTextureRenderTarget2D> RenderTarget_DyxDyz_I = nullptr;

	UPROPERTY()
	TObjectPtr<UTextureRenderTarget2D> RenderTarget_DxxDzz_I = nullptr;

	UPROPERTY()
	uint32 CurrentStep = 0;

	UPROPERTY()
	bool PingPong = true;

	UPROPERTY()
	uint32 Size = 256;

	UPROPERTY()
	uint32 Step = 8; // log2(Size)

	/*
		============================Wave Integration Pass============================
	*/
	UPROPERTY()
	TObjectPtr<UTextureRenderTarget2D> RenderTarget_Displacement = nullptr;

	UPROPERTY()
	TObjectPtr<UTextureRenderTarget2D> RenderTarget_Derivatives = nullptr;

	UPROPERTY()
	TObjectPtr<UTextureRenderTarget2D> RenderTarget_Turbulence = nullptr;

	

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	// called when the engine is shutting down
	virtual void Deinitialize() override;



	TObjectPtr<UTexture2D> GetTextureByName(FName Name) const;
	TObjectPtr<UTextureRenderTarget2D> GetRenderTargetByName(FName Name) const;
};
