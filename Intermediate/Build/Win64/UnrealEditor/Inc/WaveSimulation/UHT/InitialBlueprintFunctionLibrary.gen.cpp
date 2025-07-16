// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "BlueprintFunctionLibrary/InitialBlueprintFunctionLibrary.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

void EmptyLinkFunctionForGeneratedCodeInitialBlueprintFunctionLibrary() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UClass* Z_Construct_UClass_UObject_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UBlueprintFunctionLibrary();
ENGINE_API UClass* Z_Construct_UClass_UTexture2D_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UTextureRenderTarget2D_NoRegister();
UPackage* Z_Construct_UPackage__Script_WaveSimulation();
WAVESIMULATION_API UClass* Z_Construct_UClass_UInitialBlueprintFunctionLibrary();
WAVESIMULATION_API UClass* Z_Construct_UClass_UInitialBlueprintFunctionLibrary_NoRegister();
WAVESIMULATION_API UScriptStruct* Z_Construct_UScriptStruct_FSpectrumParameters();
// ********** End Cross Module References **********************************************************

// ********** Begin ScriptStruct FSpectrumParameters ***********************************************
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FSpectrumParameters;
class UScriptStruct* FSpectrumParameters::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FSpectrumParameters.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FSpectrumParameters.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FSpectrumParameters, (UObject*)Z_Construct_UPackage__Script_WaveSimulation(), TEXT("SpectrumParameters"));
	}
	return Z_Registration_Info_UScriptStruct_FSpectrumParameters.OuterSingleton;
}
struct Z_Construct_UScriptStruct_FSpectrumParameters_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/BlueprintFunctionLibrary/InitialBlueprintFunctionLibrary.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_scale_MetaData[] = {
		{ "Category", "Wave Spectrum" },
		{ "ModuleRelativePath", "Public/BlueprintFunctionLibrary/InitialBlueprintFunctionLibrary.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_angle_MetaData[] = {
		{ "Category", "Wave Spectrum" },
		{ "ModuleRelativePath", "Public/BlueprintFunctionLibrary/InitialBlueprintFunctionLibrary.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_spreadBlend_MetaData[] = {
		{ "Category", "Wave Spectrum" },
		{ "ModuleRelativePath", "Public/BlueprintFunctionLibrary/InitialBlueprintFunctionLibrary.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_swell_MetaData[] = {
		{ "Category", "Wave Spectrum" },
		{ "ModuleRelativePath", "Public/BlueprintFunctionLibrary/InitialBlueprintFunctionLibrary.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_alpha_MetaData[] = {
		{ "Category", "Wave Spectrum" },
		{ "ModuleRelativePath", "Public/BlueprintFunctionLibrary/InitialBlueprintFunctionLibrary.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_peakOmega_MetaData[] = {
		{ "Category", "Wave Spectrum" },
		{ "ModuleRelativePath", "Public/BlueprintFunctionLibrary/InitialBlueprintFunctionLibrary.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_gamma_MetaData[] = {
		{ "Category", "Wave Spectrum" },
		{ "ModuleRelativePath", "Public/BlueprintFunctionLibrary/InitialBlueprintFunctionLibrary.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_shortWavesFade_MetaData[] = {
		{ "Category", "Wave Spectrum" },
		{ "ModuleRelativePath", "Public/BlueprintFunctionLibrary/InitialBlueprintFunctionLibrary.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFloatPropertyParams NewProp_scale;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_angle;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_spreadBlend;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_swell;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_alpha;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_peakOmega;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_gamma;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_shortWavesFade;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FSpectrumParameters>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FSpectrumParameters_Statics::NewProp_scale = { "scale", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FSpectrumParameters, scale), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_scale_MetaData), NewProp_scale_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FSpectrumParameters_Statics::NewProp_angle = { "angle", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FSpectrumParameters, angle), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_angle_MetaData), NewProp_angle_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FSpectrumParameters_Statics::NewProp_spreadBlend = { "spreadBlend", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FSpectrumParameters, spreadBlend), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_spreadBlend_MetaData), NewProp_spreadBlend_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FSpectrumParameters_Statics::NewProp_swell = { "swell", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FSpectrumParameters, swell), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_swell_MetaData), NewProp_swell_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FSpectrumParameters_Statics::NewProp_alpha = { "alpha", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FSpectrumParameters, alpha), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_alpha_MetaData), NewProp_alpha_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FSpectrumParameters_Statics::NewProp_peakOmega = { "peakOmega", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FSpectrumParameters, peakOmega), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_peakOmega_MetaData), NewProp_peakOmega_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FSpectrumParameters_Statics::NewProp_gamma = { "gamma", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FSpectrumParameters, gamma), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_gamma_MetaData), NewProp_gamma_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FSpectrumParameters_Statics::NewProp_shortWavesFade = { "shortWavesFade", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FSpectrumParameters, shortWavesFade), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_shortWavesFade_MetaData), NewProp_shortWavesFade_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FSpectrumParameters_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSpectrumParameters_Statics::NewProp_scale,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSpectrumParameters_Statics::NewProp_angle,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSpectrumParameters_Statics::NewProp_spreadBlend,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSpectrumParameters_Statics::NewProp_swell,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSpectrumParameters_Statics::NewProp_alpha,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSpectrumParameters_Statics::NewProp_peakOmega,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSpectrumParameters_Statics::NewProp_gamma,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSpectrumParameters_Statics::NewProp_shortWavesFade,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSpectrumParameters_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FSpectrumParameters_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_WaveSimulation,
	nullptr,
	&NewStructOps,
	"SpectrumParameters",
	Z_Construct_UScriptStruct_FSpectrumParameters_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSpectrumParameters_Statics::PropPointers),
	sizeof(FSpectrumParameters),
	alignof(FSpectrumParameters),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSpectrumParameters_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FSpectrumParameters_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FSpectrumParameters()
{
	if (!Z_Registration_Info_UScriptStruct_FSpectrumParameters.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FSpectrumParameters.InnerSingleton, Z_Construct_UScriptStruct_FSpectrumParameters_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_FSpectrumParameters.InnerSingleton;
}
// ********** End ScriptStruct FSpectrumParameters *************************************************

// ********** Begin Class UInitialBlueprintFunctionLibrary Function CalculateTMASpectrum ***********
struct Z_Construct_UFunction_UInitialBlueprintFunctionLibrary_CalculateTMASpectrum_Statics
{
	struct InitialBlueprintFunctionLibrary_eventCalculateTMASpectrum_Parms
	{
		UObject* WorldContextObject;
		UTextureRenderTarget2D* RenderTarget_H0K;
		UTextureRenderTarget2D* RenderTarget_WavesData;
		TArray<FSpectrumParameters> SpectrumData;
		UTexture2D* NoiseTexture;
		int32 WaveSize;
		float WaveLengthScale;
		float WaveCutoffHigh;
		float WaveCutoffLow;
		float WaveGravityAcceleration;
		float WaveDepth;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Wave Simulation" },
		{ "CPP_Default_WaveCutoffHigh", "10000.000000" },
		{ "CPP_Default_WaveCutoffLow", "0.000100" },
		{ "CPP_Default_WaveDepth", "50.000000" },
		{ "CPP_Default_WaveGravityAcceleration", "981.000000" },
		{ "CPP_Default_WaveLengthScale", "1000.000000" },
		{ "CPP_Default_WaveSize", "256" },
		{ "ModuleRelativePath", "Public/BlueprintFunctionLibrary/InitialBlueprintFunctionLibrary.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_WorldContextObject;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_RenderTarget_H0K;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_RenderTarget_WavesData;
	static const UECodeGen_Private::FStructPropertyParams NewProp_SpectrumData_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_SpectrumData;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_NoiseTexture;
	static const UECodeGen_Private::FIntPropertyParams NewProp_WaveSize;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_WaveLengthScale;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_WaveCutoffHigh;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_WaveCutoffLow;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_WaveGravityAcceleration;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_WaveDepth;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UInitialBlueprintFunctionLibrary_CalculateTMASpectrum_Statics::NewProp_WorldContextObject = { "WorldContextObject", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(InitialBlueprintFunctionLibrary_eventCalculateTMASpectrum_Parms, WorldContextObject), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UInitialBlueprintFunctionLibrary_CalculateTMASpectrum_Statics::NewProp_RenderTarget_H0K = { "RenderTarget_H0K", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(InitialBlueprintFunctionLibrary_eventCalculateTMASpectrum_Parms, RenderTarget_H0K), Z_Construct_UClass_UTextureRenderTarget2D_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UInitialBlueprintFunctionLibrary_CalculateTMASpectrum_Statics::NewProp_RenderTarget_WavesData = { "RenderTarget_WavesData", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(InitialBlueprintFunctionLibrary_eventCalculateTMASpectrum_Parms, RenderTarget_WavesData), Z_Construct_UClass_UTextureRenderTarget2D_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UInitialBlueprintFunctionLibrary_CalculateTMASpectrum_Statics::NewProp_SpectrumData_Inner = { "SpectrumData", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FSpectrumParameters, METADATA_PARAMS(0, nullptr) }; // 3890701358
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UInitialBlueprintFunctionLibrary_CalculateTMASpectrum_Statics::NewProp_SpectrumData = { "SpectrumData", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(InitialBlueprintFunctionLibrary_eventCalculateTMASpectrum_Parms, SpectrumData), EArrayPropertyFlags::None, METADATA_PARAMS(0, nullptr) }; // 3890701358
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UInitialBlueprintFunctionLibrary_CalculateTMASpectrum_Statics::NewProp_NoiseTexture = { "NoiseTexture", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(InitialBlueprintFunctionLibrary_eventCalculateTMASpectrum_Parms, NoiseTexture), Z_Construct_UClass_UTexture2D_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UInitialBlueprintFunctionLibrary_CalculateTMASpectrum_Statics::NewProp_WaveSize = { "WaveSize", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(InitialBlueprintFunctionLibrary_eventCalculateTMASpectrum_Parms, WaveSize), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UInitialBlueprintFunctionLibrary_CalculateTMASpectrum_Statics::NewProp_WaveLengthScale = { "WaveLengthScale", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(InitialBlueprintFunctionLibrary_eventCalculateTMASpectrum_Parms, WaveLengthScale), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UInitialBlueprintFunctionLibrary_CalculateTMASpectrum_Statics::NewProp_WaveCutoffHigh = { "WaveCutoffHigh", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(InitialBlueprintFunctionLibrary_eventCalculateTMASpectrum_Parms, WaveCutoffHigh), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UInitialBlueprintFunctionLibrary_CalculateTMASpectrum_Statics::NewProp_WaveCutoffLow = { "WaveCutoffLow", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(InitialBlueprintFunctionLibrary_eventCalculateTMASpectrum_Parms, WaveCutoffLow), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UInitialBlueprintFunctionLibrary_CalculateTMASpectrum_Statics::NewProp_WaveGravityAcceleration = { "WaveGravityAcceleration", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(InitialBlueprintFunctionLibrary_eventCalculateTMASpectrum_Parms, WaveGravityAcceleration), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UInitialBlueprintFunctionLibrary_CalculateTMASpectrum_Statics::NewProp_WaveDepth = { "WaveDepth", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(InitialBlueprintFunctionLibrary_eventCalculateTMASpectrum_Parms, WaveDepth), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UInitialBlueprintFunctionLibrary_CalculateTMASpectrum_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInitialBlueprintFunctionLibrary_CalculateTMASpectrum_Statics::NewProp_WorldContextObject,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInitialBlueprintFunctionLibrary_CalculateTMASpectrum_Statics::NewProp_RenderTarget_H0K,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInitialBlueprintFunctionLibrary_CalculateTMASpectrum_Statics::NewProp_RenderTarget_WavesData,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInitialBlueprintFunctionLibrary_CalculateTMASpectrum_Statics::NewProp_SpectrumData_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInitialBlueprintFunctionLibrary_CalculateTMASpectrum_Statics::NewProp_SpectrumData,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInitialBlueprintFunctionLibrary_CalculateTMASpectrum_Statics::NewProp_NoiseTexture,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInitialBlueprintFunctionLibrary_CalculateTMASpectrum_Statics::NewProp_WaveSize,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInitialBlueprintFunctionLibrary_CalculateTMASpectrum_Statics::NewProp_WaveLengthScale,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInitialBlueprintFunctionLibrary_CalculateTMASpectrum_Statics::NewProp_WaveCutoffHigh,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInitialBlueprintFunctionLibrary_CalculateTMASpectrum_Statics::NewProp_WaveCutoffLow,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInitialBlueprintFunctionLibrary_CalculateTMASpectrum_Statics::NewProp_WaveGravityAcceleration,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInitialBlueprintFunctionLibrary_CalculateTMASpectrum_Statics::NewProp_WaveDepth,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UInitialBlueprintFunctionLibrary_CalculateTMASpectrum_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UInitialBlueprintFunctionLibrary_CalculateTMASpectrum_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UInitialBlueprintFunctionLibrary, nullptr, "CalculateTMASpectrum", Z_Construct_UFunction_UInitialBlueprintFunctionLibrary_CalculateTMASpectrum_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UInitialBlueprintFunctionLibrary_CalculateTMASpectrum_Statics::PropPointers), sizeof(Z_Construct_UFunction_UInitialBlueprintFunctionLibrary_CalculateTMASpectrum_Statics::InitialBlueprintFunctionLibrary_eventCalculateTMASpectrum_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UInitialBlueprintFunctionLibrary_CalculateTMASpectrum_Statics::Function_MetaDataParams), Z_Construct_UFunction_UInitialBlueprintFunctionLibrary_CalculateTMASpectrum_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UInitialBlueprintFunctionLibrary_CalculateTMASpectrum_Statics::InitialBlueprintFunctionLibrary_eventCalculateTMASpectrum_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UInitialBlueprintFunctionLibrary_CalculateTMASpectrum()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UInitialBlueprintFunctionLibrary_CalculateTMASpectrum_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UInitialBlueprintFunctionLibrary::execCalculateTMASpectrum)
{
	P_GET_OBJECT(UObject,Z_Param_WorldContextObject);
	P_GET_OBJECT(UTextureRenderTarget2D,Z_Param_RenderTarget_H0K);
	P_GET_OBJECT(UTextureRenderTarget2D,Z_Param_RenderTarget_WavesData);
	P_GET_TARRAY(FSpectrumParameters,Z_Param_SpectrumData);
	P_GET_OBJECT(UTexture2D,Z_Param_NoiseTexture);
	P_GET_PROPERTY(FIntProperty,Z_Param_WaveSize);
	P_GET_PROPERTY(FFloatProperty,Z_Param_WaveLengthScale);
	P_GET_PROPERTY(FFloatProperty,Z_Param_WaveCutoffHigh);
	P_GET_PROPERTY(FFloatProperty,Z_Param_WaveCutoffLow);
	P_GET_PROPERTY(FFloatProperty,Z_Param_WaveGravityAcceleration);
	P_GET_PROPERTY(FFloatProperty,Z_Param_WaveDepth);
	P_FINISH;
	P_NATIVE_BEGIN;
	UInitialBlueprintFunctionLibrary::CalculateTMASpectrum(Z_Param_WorldContextObject,Z_Param_RenderTarget_H0K,Z_Param_RenderTarget_WavesData,Z_Param_SpectrumData,Z_Param_NoiseTexture,Z_Param_WaveSize,Z_Param_WaveLengthScale,Z_Param_WaveCutoffHigh,Z_Param_WaveCutoffLow,Z_Param_WaveGravityAcceleration,Z_Param_WaveDepth);
	P_NATIVE_END;
}
// ********** End Class UInitialBlueprintFunctionLibrary Function CalculateTMASpectrum *************

// ********** Begin Class UInitialBlueprintFunctionLibrary *****************************************
void UInitialBlueprintFunctionLibrary::StaticRegisterNativesUInitialBlueprintFunctionLibrary()
{
	UClass* Class = UInitialBlueprintFunctionLibrary::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "CalculateTMASpectrum", &UInitialBlueprintFunctionLibrary::execCalculateTMASpectrum },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
FClassRegistrationInfo Z_Registration_Info_UClass_UInitialBlueprintFunctionLibrary;
UClass* UInitialBlueprintFunctionLibrary::GetPrivateStaticClass()
{
	using TClass = UInitialBlueprintFunctionLibrary;
	if (!Z_Registration_Info_UClass_UInitialBlueprintFunctionLibrary.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			StaticPackage(),
			TEXT("InitialBlueprintFunctionLibrary"),
			Z_Registration_Info_UClass_UInitialBlueprintFunctionLibrary.InnerSingleton,
			StaticRegisterNativesUInitialBlueprintFunctionLibrary,
			sizeof(TClass),
			alignof(TClass),
			TClass::StaticClassFlags,
			TClass::StaticClassCastFlags(),
			TClass::StaticConfigName(),
			(UClass::ClassConstructorType)InternalConstructor<TClass>,
			(UClass::ClassVTableHelperCtorCallerType)InternalVTableHelperCtorCaller<TClass>,
			UOBJECT_CPPCLASS_STATICFUNCTIONS_FORCLASS(TClass),
			&TClass::Super::StaticClass,
			&TClass::WithinClass::StaticClass
		);
	}
	return Z_Registration_Info_UClass_UInitialBlueprintFunctionLibrary.InnerSingleton;
}
UClass* Z_Construct_UClass_UInitialBlueprintFunctionLibrary_NoRegister()
{
	return UInitialBlueprintFunctionLibrary::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UInitialBlueprintFunctionLibrary_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * Calculate H0K and WavesData (kx, kz, omega)\n */" },
#endif
		{ "IncludePath", "BlueprintFunctionLibrary/InitialBlueprintFunctionLibrary.h" },
		{ "ModuleRelativePath", "Public/BlueprintFunctionLibrary/InitialBlueprintFunctionLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Calculate H0K and WavesData (kx, kz, omega)" },
#endif
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UInitialBlueprintFunctionLibrary_CalculateTMASpectrum, "CalculateTMASpectrum" }, // 3928173406
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UInitialBlueprintFunctionLibrary>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_UInitialBlueprintFunctionLibrary_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UBlueprintFunctionLibrary,
	(UObject* (*)())Z_Construct_UPackage__Script_WaveSimulation,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UInitialBlueprintFunctionLibrary_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UInitialBlueprintFunctionLibrary_Statics::ClassParams = {
	&UInitialBlueprintFunctionLibrary::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	0,
	0,
	0x001000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UInitialBlueprintFunctionLibrary_Statics::Class_MetaDataParams), Z_Construct_UClass_UInitialBlueprintFunctionLibrary_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UInitialBlueprintFunctionLibrary()
{
	if (!Z_Registration_Info_UClass_UInitialBlueprintFunctionLibrary.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UInitialBlueprintFunctionLibrary.OuterSingleton, Z_Construct_UClass_UInitialBlueprintFunctionLibrary_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UInitialBlueprintFunctionLibrary.OuterSingleton;
}
UInitialBlueprintFunctionLibrary::UInitialBlueprintFunctionLibrary(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UInitialBlueprintFunctionLibrary);
UInitialBlueprintFunctionLibrary::~UInitialBlueprintFunctionLibrary() {}
// ********** End Class UInitialBlueprintFunctionLibrary *******************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_11_TA_UEProjects_Seaside_Plugins_WaveSimulation_Source_WaveSimulation_Public_BlueprintFunctionLibrary_InitialBlueprintFunctionLibrary_h__Script_WaveSimulation_Statics
{
	static constexpr FStructRegisterCompiledInInfo ScriptStructInfo[] = {
		{ FSpectrumParameters::StaticStruct, Z_Construct_UScriptStruct_FSpectrumParameters_Statics::NewStructOps, TEXT("SpectrumParameters"), &Z_Registration_Info_UScriptStruct_FSpectrumParameters, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FSpectrumParameters), 3890701358U) },
	};
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UInitialBlueprintFunctionLibrary, UInitialBlueprintFunctionLibrary::StaticClass, TEXT("UInitialBlueprintFunctionLibrary"), &Z_Registration_Info_UClass_UInitialBlueprintFunctionLibrary, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UInitialBlueprintFunctionLibrary), 61933767U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_11_TA_UEProjects_Seaside_Plugins_WaveSimulation_Source_WaveSimulation_Public_BlueprintFunctionLibrary_InitialBlueprintFunctionLibrary_h__Script_WaveSimulation_2678730494(TEXT("/Script/WaveSimulation"),
	Z_CompiledInDeferFile_FID_11_TA_UEProjects_Seaside_Plugins_WaveSimulation_Source_WaveSimulation_Public_BlueprintFunctionLibrary_InitialBlueprintFunctionLibrary_h__Script_WaveSimulation_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_11_TA_UEProjects_Seaside_Plugins_WaveSimulation_Source_WaveSimulation_Public_BlueprintFunctionLibrary_InitialBlueprintFunctionLibrary_h__Script_WaveSimulation_Statics::ClassInfo),
	Z_CompiledInDeferFile_FID_11_TA_UEProjects_Seaside_Plugins_WaveSimulation_Source_WaveSimulation_Public_BlueprintFunctionLibrary_InitialBlueprintFunctionLibrary_h__Script_WaveSimulation_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_11_TA_UEProjects_Seaside_Plugins_WaveSimulation_Source_WaveSimulation_Public_BlueprintFunctionLibrary_InitialBlueprintFunctionLibrary_h__Script_WaveSimulation_Statics::ScriptStructInfo),
	nullptr, 0);
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
