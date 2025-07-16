// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */
class WAVESIMULATION_API HelperFunctions
{
public:

	static FRDGTextureSRVRef CreateSRVIfValid(FRDGBuilder& GraphBuilder, FRDGTextureRef Texture);
	static FRDGTextureRef RegisterExternalRenderTarget(FRDGBuilder& GraphBuilder, UTextureRenderTarget2D* RT, const FString& Name);
	static FRDGTextureUAVRef CreateUAVIfValid(FRDGBuilder& GraphBuilder, FRDGTextureRef Texture);
};
