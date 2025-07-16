// Copyright Epic Games, Inc. All Rights Reserved.

#include "WaveSimulation.h"
#include "Interfaces/IPluginManager.h"

#define LOCTEXT_NAMESPACE "FWaveSimulationModule"

void FWaveSimulationModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
	const FString PluginShaderDir = FPaths::Combine
	(
		IPluginManager::Get().
		FindPlugin(TEXT("WaveSimulation"))->GetBaseDir(),
		TEXT("Shaders")
	);

	// map the actual dir to virtual dir
	if (!AllShaderSourceDirectoryMappings().Contains(TEXT("/WaveSimulation")))
	{
		AddShaderSourceDirectoryMapping(TEXT("/WaveSimulation"), PluginShaderDir);
	}
}

void FWaveSimulationModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FWaveSimulationModule, WaveSimulation)