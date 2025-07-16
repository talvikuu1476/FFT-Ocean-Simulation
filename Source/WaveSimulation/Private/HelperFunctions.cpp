// Fill out your copyright notice in the Description page of Project Settings.


#include "HelperFunctions.h"
#include "ShaderCompilerCore.h"
#include "RenderGraphUtils.h"
#include "Engine/TextureRenderTarget2D.h"


FRDGTextureRef HelperFunctions::RegisterExternalRenderTarget(
	FRDGBuilder& GraphBuilder,
	UTextureRenderTarget2D* RenderTarget,
	const FString& DebugName
)
{
	if (!RenderTarget || !RenderTarget->GetResource())
		return nullptr;

	FRHITexture* RHITexture = RenderTarget->GetRenderTargetResource()->GetRenderTargetTexture();
	if (!RHITexture)
		return nullptr;

	return GraphBuilder.RegisterExternalTexture(
		CreateRenderTarget(RHITexture, *DebugName)
	);
}

FRDGTextureSRVRef HelperFunctions::CreateSRVIfValid(FRDGBuilder& GraphBuilder, FRDGTextureRef Texture)
{
	return Texture ? GraphBuilder.CreateSRV(FRDGTextureSRVDesc::Create(Texture)) : nullptr;
}

FRDGTextureUAVRef HelperFunctions::CreateUAVIfValid(FRDGBuilder& GraphBuilder, FRDGTextureRef Texture)
{
	return Texture ? GraphBuilder.CreateUAV(FRDGTextureUAVDesc(Texture)) : nullptr;
}
