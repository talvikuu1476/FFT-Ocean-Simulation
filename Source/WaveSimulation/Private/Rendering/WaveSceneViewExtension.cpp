// Fill out your copyright notice in the Description page of Project Settings.


#include "Rendering/WaveSceneViewExtension.h"
#include "SceneViewExtension.h"
#include "ShaderPasses/InitialCS.h"
#include "ShaderPasses/FrequencyCS.h"
#include "ShaderPasses/TwiddleFactorCS.h"
#include "ShaderPasses/IFFTButterflyCS.h"
#include "ShaderPasses/WaveIntegrationCS.h"
#include "Engine/Texture2D.h"

FWaveSceneViewExtension::FWaveSceneViewExtension(const FAutoRegister& AutoRegister) : FSceneViewExtensionBase(AutoRegister)
{


}

FWaveSceneViewExtension::~FWaveSceneViewExtension()
{


}

void FWaveSceneViewExtension::SetupViewFamily(FSceneViewFamily& InViewFamily)
{


}

void FWaveSceneViewExtension::SetupView(FSceneViewFamily& InViewFamily, FSceneView& InView)
{


}

void FWaveSceneViewExtension::BeginRenderViewFamily(FSceneViewFamily& InViewFamily)
{


}

DECLARE_GPU_DRAWCALL_STAT(Wave);
void FWaveSceneViewExtension::PrePostProcessPass_RenderThread(
	FRDGBuilder& GraphBuilder,
	const FSceneView& View,
	const FPostProcessingInputs& Inputs)
{
	FSceneViewExtensionBase::PrePostProcessPass_RenderThread(GraphBuilder, View, Inputs);
	float time = View.Family->Time.GetWorldTimeSeconds(); // current time in seconds

	// H0 pass
	FConjugateCS H0Pass;
	H0Pass.H0Pass(GraphBuilder, Subsystem);

	// FrequencyXYZ, H(k, t) and derivatives pass
	FFrequencyCS FrequencyPass;
	FrequencyPass.FrequencyPass(GraphBuilder, Subsystem, time);

	// Twiddle Factor pass
	FTwiddleFactorCS TwiddleFactorPass;
	TwiddleFactorPass.TwiddleFactorPass(GraphBuilder, Subsystem);

	// IFFT Butterfly pass
	FIFFTButterflyCS IFFTButterflyPass;
	IFFTButterflyPass.IFFTButterflyPass(GraphBuilder, Subsystem);

	// Wave Integration pass
	FWaveIntegrationCS WaveIntegrationPass;
	WaveIntegrationPass.WaveIntegrationPass(GraphBuilder, Subsystem);



}

