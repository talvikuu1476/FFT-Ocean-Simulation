// Fill out your copyright notice in the Description page of Project Settings.


#include "EngineSubsystem/WaveEngineSubsystem.h"
#include "Rendering/WaveSceneViewExtension.h"
#include "SceneViewExtension.h"
#include "Engine/TextureRenderTarget2D.h"

// setup RT
template<typename ExtensionType>
void SetupExtensionWithRenderTarget(
	TSharedPtr<ExtensionType, ESPMode::ThreadSafe> Extension,
	const FString& RenderTargetPath,
	const FString& ExtensionName)
{
	if (UTextureRenderTarget2D* RenderTarget = LoadObject<UTextureRenderTarget2D>(nullptr, *RenderTargetPath))
	{
		if (Extension.IsValid())
		{
			Extension->SetRenderTargets(RenderTarget);
			UE_LOG(LogTemp, Log, TEXT("Successfully set RenderTarget for %s"), *ExtensionName);
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("Extension is not valid for %s"), *ExtensionName);
		}
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Failed to load RenderTarget for %s: %s"), *ExtensionName, *RenderTargetPath);
	}
}

// setup texture
template<typename ExtensionType>
void SetupExtensionWithTexture(
	TSharedPtr<ExtensionType, ESPMode::ThreadSafe> Extension,
	const FString& TexturePath,
	const FString& ExtensionName)
{
	if (UTexture2D* Texture = LoadObject<UTexture2D>(nullptr, *TexturePath))
	{
		if (Extension.IsValid())
		{
			Extension->SetResources(Texture);
			UE_LOG(LogTemp, Log, TEXT("Successfully set Texture for %s"), *ExtensionName);
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("Extension is not valid for %s"), *ExtensionName);
		}
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Failed to load Texture for %s: %s"), *ExtensionName, *TexturePath);
	}
}

// load RT
UTextureRenderTarget2D* LoadRenderTarget(const FString& RenderTargetPath, const FString& ResourceName)
{
	UTextureRenderTarget2D* RenderTarget = LoadObject<UTextureRenderTarget2D>(nullptr, *RenderTargetPath);
	if (!RenderTarget)
	{
		UE_LOG(LogTemp, Warning, TEXT("Failed to load %s RenderTarget: %s"), *ResourceName, *RenderTargetPath);
	}
	return RenderTarget;
}

// load texture
UTexture2D* LoadTexture(const FString& TexturePath, const FString& ResourceName)
{
	UTexture2D* Texture = LoadObject<UTexture2D>(nullptr, *TexturePath);
	if (!Texture)
	{
		UE_LOG(LogTemp, Warning, TEXT("Failed to load %s Texture: %s"), *ResourceName, *TexturePath);
	}
	return Texture;
}

// setup scene view extension
template<typename ExtensionType>
TSharedPtr<ExtensionType, ESPMode::ThreadSafe> CreateExtension()
{
	return FSceneViewExtensions::NewExtension<ExtensionType>();
}

void UWaveEngineSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);

	/*
		============================FWaveSceneViewExtension============================
	*/
	WaveSceneViewExtension = CreateExtension<FWaveSceneViewExtension>();
	WaveSceneViewExtension->SetSubsystem(this);

	/*
		============================Initial Spectrum Pass============================
	*/
	H0KTexture = LoadObject<UTexture2D>(nullptr,
		TEXT("/WaveSimulation/Assets/Textures/T_H0K.T_H0K"));

	NoiseTexture = LoadObject<UTexture2D>(nullptr,
		TEXT("/WaveSimulation/Assets/Textures/T_GaussianNoiseTex.T_GaussianNoiseTex"));

	RenderTarget_H0K = LoadObject<UTextureRenderTarget2D>(nullptr,
		TEXT("/WaveSimulation/Assets/RT/RT_H0K.RT_H0K"));
	RenderTarget_H0 = LoadObject<UTextureRenderTarget2D>(nullptr,
		TEXT("/WaveSimulation/Assets/RT/RT_H0.RT_H0"));


	/*
		============================Twiddle Factor Pass============================
	*/

	TwiddleFactorRenderTarget = LoadRenderTarget(
		TEXT("/WaveSimulation/Assets/RT/RT_TwiddleFactor.RT_TwiddleFactor"),
		TEXT("TwiddleFactor"));

	/*
		============================Frequency Pass============================
	*/

	H0Texture = LoadObject<UTexture2D>(nullptr,
		TEXT("/WaveSimulation/Assets/Textures/T_H0.T_H0"));

	RenderTarget_WavesData = LoadObject<UTextureRenderTarget2D>(nullptr,
		TEXT("/WaveSimulation/Assets/RT/RT_WavesData.RT_WavesData"));
	RenderTarget_DxDz = LoadObject<UTextureRenderTarget2D>(nullptr,
		TEXT("/WaveSimulation/Assets/RT/RT_DxDz.RT_DxDz"));
	RenderTarget_DyDxz = LoadObject<UTextureRenderTarget2D>(nullptr,
		TEXT("/WaveSimulation/Assets/RT/RT_DyDxz.RT_DyDxz"));
	RenderTarget_DyxDyz = LoadObject<UTextureRenderTarget2D>(nullptr,
		TEXT("/WaveSimulation/Assets/RT/RT_DyxDyz.RT_DyxDyz"));
	RenderTarget_DxxDzz = LoadObject<UTextureRenderTarget2D>(nullptr,
		TEXT("/WaveSimulation/Assets/RT/RT_DxxDzz.RT_DxxDzz"));
	


	/*
		============================IFFT Butterfly Pass============================
	*/

	TwiddleFactorTexture = LoadObject<UTexture2D>(nullptr,
		TEXT("/WaveSimulation/Assets/Textures/T_TwiddleFactor.T_TwiddleFactor"));

	RenderTarget_Buffer0 = LoadObject<UTextureRenderTarget2D>(nullptr,
		TEXT("/WaveSimulation/Assets/RT/RT_Butterfly.RT_Butterfly"));
	RenderTarget_Buffer1 = LoadObject<UTextureRenderTarget2D>(nullptr,
		TEXT("/WaveSimulation/Assets/RT/RT_Buffer1.RT_Buffer1"));
	RenderTarget_DxDz_I = LoadObject<UTextureRenderTarget2D>(nullptr,
		TEXT("/WaveSimulation/Assets/RT/RT_DxDz_I.RT_DxDz_I"));
	RenderTarget_DyDxz_I = LoadObject<UTextureRenderTarget2D>(nullptr,
		TEXT("/WaveSimulation/Assets/RT/RT_DyDxz_I.RT_DyDxz_I"));
	RenderTarget_DyxDyz_I = LoadObject<UTextureRenderTarget2D>(nullptr,
		TEXT("/WaveSimulation/Assets/RT/RT_DyxDyz_I.RT_DyxDyz_I"));
	RenderTarget_DxxDzz_I = LoadObject<UTextureRenderTarget2D>(nullptr,
		TEXT("/WaveSimulation/Assets/RT/RT_DxxDzz_I.RT_DxxDzz_I"));

	/*
		============================Wave Integration Pass============================
	*/

	RenderTarget_Displacement = LoadObject<UTextureRenderTarget2D>(nullptr,
		TEXT("/WaveSimulation/Assets/RT/RT_Displacement.RT_Displacement"));
	RenderTarget_Derivatives = LoadObject<UTextureRenderTarget2D>(nullptr,
		TEXT("/WaveSimulation/Assets/RT/RT_Derivatives.RT_Derivatives"));
	RenderTarget_Turbulence = LoadObject<UTextureRenderTarget2D>(nullptr,
		TEXT("/WaveSimulation/Assets/RT/RT_Turbulence.RT_Turbulence"));


}

void UWaveEngineSubsystem::Deinitialize()
{
	// unregister scene view extensions
	Super::Deinitialize();

	WaveSceneViewExtension.Reset();
	WaveSceneViewExtension = nullptr;

	WaveRenderTarget = nullptr;
	NoiseTexture = nullptr;
	RenderTarget_H0K = nullptr;
	RenderTarget_WavesData = nullptr;
	RenderTarget_H0 = nullptr;

	TwiddleFactorRenderTarget = nullptr;
	RenderTarget_DxDz = nullptr;
	RenderTarget_DyDxz = nullptr;
	RenderTarget_DyxDyz = nullptr;
	RenderTarget_DxxDzz = nullptr;

	TwiddleFactorTexture = nullptr;
	
	RenderTarget_Buffer0 = nullptr;
	RenderTarget_Buffer1 = nullptr;
	RenderTarget_DxDz_I = nullptr;
	RenderTarget_DyDxz_I = nullptr;
	RenderTarget_DyxDyz_I = nullptr;
	RenderTarget_DxxDzz_I = nullptr;
	

	RenderTarget_Displacement = nullptr;
	RenderTarget_Derivatives = nullptr;
	RenderTarget_Turbulence = nullptr;



}




TObjectPtr<UTexture2D> UWaveEngineSubsystem::GetTextureByName(FName Name) const
{
	if (Name == "H0K")
		return H0KTexture;
	else if (Name == "NoiseTexture")
		return NoiseTexture;
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Unknown Texture Name: %s"), *Name.ToString());
		return nullptr;
	}
}

TObjectPtr<UTextureRenderTarget2D> UWaveEngineSubsystem::GetRenderTargetByName(FName Name) const
{
	TObjectPtr<UTextureRenderTarget2D> Result;
	if (Name == "H0")
		Result = RenderTarget_H0;
	else if (Name == "H0K")
		Result = RenderTarget_H0K;
	else if (Name == "WavesData")
		Result = RenderTarget_WavesData;
	else if (Name == "TwiddleFactor")
		Result = TwiddleFactorRenderTarget;
	else if (Name == "DxDz")
		Result = RenderTarget_DxDz;
	else if (Name == "DyDxz")
		Result = RenderTarget_DyDxz;
	else if (Name == "DyxDyz")
		Result = RenderTarget_DyxDyz;
	else if (Name == "DxxDzz")
		Result = RenderTarget_DxxDzz;
	else if (Name == "Buffer0")
		Result = RenderTarget_Buffer0;
	else if (Name == "Buffer1")
		Result = RenderTarget_Buffer1;
	else if (Name == "DxDz_I")
		Result = RenderTarget_DxDz_I;
	else if (Name == "DyDxz_I")
		Result = RenderTarget_DyDxz_I;
	else if (Name == "DyxDyz_I")
		Result = RenderTarget_DyxDyz_I;
	else if (Name == "DxxDzz_I")
		Result = RenderTarget_DxxDzz_I;
	else if (Name == "Displacement")
		Result = RenderTarget_Displacement;
	else if (Name == "Derivatives")
		Result = RenderTarget_Derivatives;
	else if (Name == "Turbulence")
		Result = RenderTarget_Turbulence;

	if (!IsValid(Result))
	{
		UE_LOG(LogTemp, Error, TEXT("GetRenderTargetByName: RenderTarget '%s' is invalid or null."), *Name.ToString());
	}

	return Result;
}









