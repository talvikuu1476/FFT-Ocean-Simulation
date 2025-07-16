// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "BlueprintFunctionLibrary/InitialBlueprintFunctionLibrary.h"

#ifdef WAVESIMULATION_InitialBlueprintFunctionLibrary_generated_h
#error "InitialBlueprintFunctionLibrary.generated.h already included, missing '#pragma once' in InitialBlueprintFunctionLibrary.h"
#endif
#define WAVESIMULATION_InitialBlueprintFunctionLibrary_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

class UObject;
class UTexture2D;
class UTextureRenderTarget2D;
struct FSpectrumParameters;

// ********** Begin ScriptStruct FSpectrumParameters ***********************************************
#define FID_11_TA_UEProjects_Seaside_Plugins_WaveSimulation_Source_WaveSimulation_Public_BlueprintFunctionLibrary_InitialBlueprintFunctionLibrary_h_12_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FSpectrumParameters_Statics; \
	WAVESIMULATION_API static class UScriptStruct* StaticStruct();


struct FSpectrumParameters;
// ********** End ScriptStruct FSpectrumParameters *************************************************

// ********** Begin Class UInitialBlueprintFunctionLibrary *****************************************
#define FID_11_TA_UEProjects_Seaside_Plugins_WaveSimulation_Source_WaveSimulation_Public_BlueprintFunctionLibrary_InitialBlueprintFunctionLibrary_h_46_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execCalculateTMASpectrum);


WAVESIMULATION_API UClass* Z_Construct_UClass_UInitialBlueprintFunctionLibrary_NoRegister();

#define FID_11_TA_UEProjects_Seaside_Plugins_WaveSimulation_Source_WaveSimulation_Public_BlueprintFunctionLibrary_InitialBlueprintFunctionLibrary_h_46_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUInitialBlueprintFunctionLibrary(); \
	friend struct Z_Construct_UClass_UInitialBlueprintFunctionLibrary_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend WAVESIMULATION_API UClass* Z_Construct_UClass_UInitialBlueprintFunctionLibrary_NoRegister(); \
public: \
	DECLARE_CLASS2(UInitialBlueprintFunctionLibrary, UBlueprintFunctionLibrary, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/WaveSimulation"), Z_Construct_UClass_UInitialBlueprintFunctionLibrary_NoRegister) \
	DECLARE_SERIALIZER(UInitialBlueprintFunctionLibrary)


#define FID_11_TA_UEProjects_Seaside_Plugins_WaveSimulation_Source_WaveSimulation_Public_BlueprintFunctionLibrary_InitialBlueprintFunctionLibrary_h_46_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UInitialBlueprintFunctionLibrary(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UInitialBlueprintFunctionLibrary(UInitialBlueprintFunctionLibrary&&) = delete; \
	UInitialBlueprintFunctionLibrary(const UInitialBlueprintFunctionLibrary&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UInitialBlueprintFunctionLibrary); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UInitialBlueprintFunctionLibrary); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UInitialBlueprintFunctionLibrary) \
	NO_API virtual ~UInitialBlueprintFunctionLibrary();


#define FID_11_TA_UEProjects_Seaside_Plugins_WaveSimulation_Source_WaveSimulation_Public_BlueprintFunctionLibrary_InitialBlueprintFunctionLibrary_h_43_PROLOG
#define FID_11_TA_UEProjects_Seaside_Plugins_WaveSimulation_Source_WaveSimulation_Public_BlueprintFunctionLibrary_InitialBlueprintFunctionLibrary_h_46_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_11_TA_UEProjects_Seaside_Plugins_WaveSimulation_Source_WaveSimulation_Public_BlueprintFunctionLibrary_InitialBlueprintFunctionLibrary_h_46_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_11_TA_UEProjects_Seaside_Plugins_WaveSimulation_Source_WaveSimulation_Public_BlueprintFunctionLibrary_InitialBlueprintFunctionLibrary_h_46_INCLASS_NO_PURE_DECLS \
	FID_11_TA_UEProjects_Seaside_Plugins_WaveSimulation_Source_WaveSimulation_Public_BlueprintFunctionLibrary_InitialBlueprintFunctionLibrary_h_46_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UInitialBlueprintFunctionLibrary;

// ********** End Class UInitialBlueprintFunctionLibrary *******************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_11_TA_UEProjects_Seaside_Plugins_WaveSimulation_Source_WaveSimulation_Public_BlueprintFunctionLibrary_InitialBlueprintFunctionLibrary_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
