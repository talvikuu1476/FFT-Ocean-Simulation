// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "EngineSubsystem/WaveEngineSubsystem.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

void EmptyLinkFunctionForGeneratedCodeWaveEngineSubsystem() {}

// ********** Begin Cross Module References ********************************************************
ENGINE_API UClass* Z_Construct_UClass_UEngineSubsystem();
ENGINE_API UClass* Z_Construct_UClass_UTexture2D_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UTextureRenderTarget2D_NoRegister();
UPackage* Z_Construct_UPackage__Script_WaveSimulation();
WAVESIMULATION_API UClass* Z_Construct_UClass_UWaveEngineSubsystem();
WAVESIMULATION_API UClass* Z_Construct_UClass_UWaveEngineSubsystem_NoRegister();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UWaveEngineSubsystem *****************************************************
void UWaveEngineSubsystem::StaticRegisterNativesUWaveEngineSubsystem()
{
}
FClassRegistrationInfo Z_Registration_Info_UClass_UWaveEngineSubsystem;
UClass* UWaveEngineSubsystem::GetPrivateStaticClass()
{
	using TClass = UWaveEngineSubsystem;
	if (!Z_Registration_Info_UClass_UWaveEngineSubsystem.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			StaticPackage(),
			TEXT("WaveEngineSubsystem"),
			Z_Registration_Info_UClass_UWaveEngineSubsystem.InnerSingleton,
			StaticRegisterNativesUWaveEngineSubsystem,
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
	return Z_Registration_Info_UClass_UWaveEngineSubsystem.InnerSingleton;
}
UClass* Z_Construct_UClass_UWaveEngineSubsystem_NoRegister()
{
	return UWaveEngineSubsystem::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UWaveEngineSubsystem_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n *\n */" },
#endif
		{ "IncludePath", "EngineSubsystem/WaveEngineSubsystem.h" },
		{ "ModuleRelativePath", "Public/EngineSubsystem/WaveEngineSubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_WaveRenderTarget_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n\x09\x09============================FWaveSceneViewExtension============================\n\x09*/" },
#endif
		{ "ModuleRelativePath", "Public/EngineSubsystem/WaveEngineSubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "============================FWaveSceneViewExtension============================" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_H0KTexture_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n\x09\x09============================Initial Spectrum Pass============================\n\x09*/" },
#endif
		{ "ModuleRelativePath", "Public/EngineSubsystem/WaveEngineSubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "============================Initial Spectrum Pass============================" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_NoiseTexture_MetaData[] = {
		{ "ModuleRelativePath", "Public/EngineSubsystem/WaveEngineSubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RenderTarget_H0K_MetaData[] = {
		{ "ModuleRelativePath", "Public/EngineSubsystem/WaveEngineSubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RenderTarget_WavesData_MetaData[] = {
		{ "ModuleRelativePath", "Public/EngineSubsystem/WaveEngineSubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RenderTarget_H0_MetaData[] = {
		{ "ModuleRelativePath", "Public/EngineSubsystem/WaveEngineSubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TwiddleFactorRenderTarget_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n\x09\x09============================FTwiddleFactorSceneViewExtension============================\n\x09*/" },
#endif
		{ "ModuleRelativePath", "Public/EngineSubsystem/WaveEngineSubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "============================FTwiddleFactorSceneViewExtension============================" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_H0Texture_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n\x09\x09============================Frequency Pass============================\n\x09*/" },
#endif
		{ "ModuleRelativePath", "Public/EngineSubsystem/WaveEngineSubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "============================Frequency Pass============================" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RenderTarget_DxDz_MetaData[] = {
		{ "ModuleRelativePath", "Public/EngineSubsystem/WaveEngineSubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RenderTarget_DyDxz_MetaData[] = {
		{ "ModuleRelativePath", "Public/EngineSubsystem/WaveEngineSubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RenderTarget_DyxDyz_MetaData[] = {
		{ "ModuleRelativePath", "Public/EngineSubsystem/WaveEngineSubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RenderTarget_DxxDzz_MetaData[] = {
		{ "ModuleRelativePath", "Public/EngineSubsystem/WaveEngineSubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TwiddleFactorTexture_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n\x09\x09============================IFFT Butterfly Pass============================\n\x09*/" },
#endif
		{ "ModuleRelativePath", "Public/EngineSubsystem/WaveEngineSubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "============================IFFT Butterfly Pass============================" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RenderTarget_Buffer0_MetaData[] = {
		{ "ModuleRelativePath", "Public/EngineSubsystem/WaveEngineSubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RenderTarget_Buffer1_MetaData[] = {
		{ "ModuleRelativePath", "Public/EngineSubsystem/WaveEngineSubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RenderTarget_DxDz_I_MetaData[] = {
		{ "ModuleRelativePath", "Public/EngineSubsystem/WaveEngineSubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RenderTarget_DyDxz_I_MetaData[] = {
		{ "ModuleRelativePath", "Public/EngineSubsystem/WaveEngineSubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RenderTarget_DyxDyz_I_MetaData[] = {
		{ "ModuleRelativePath", "Public/EngineSubsystem/WaveEngineSubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RenderTarget_DxxDzz_I_MetaData[] = {
		{ "ModuleRelativePath", "Public/EngineSubsystem/WaveEngineSubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CurrentStep_MetaData[] = {
		{ "ModuleRelativePath", "Public/EngineSubsystem/WaveEngineSubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PingPong_MetaData[] = {
		{ "ModuleRelativePath", "Public/EngineSubsystem/WaveEngineSubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Size_MetaData[] = {
		{ "ModuleRelativePath", "Public/EngineSubsystem/WaveEngineSubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Step_MetaData[] = {
		{ "ModuleRelativePath", "Public/EngineSubsystem/WaveEngineSubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RenderTarget_Displacement_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n\x09\x09============================Wave Integration Pass============================\n\x09*/" },
#endif
		{ "ModuleRelativePath", "Public/EngineSubsystem/WaveEngineSubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "============================Wave Integration Pass============================" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RenderTarget_Derivatives_MetaData[] = {
		{ "ModuleRelativePath", "Public/EngineSubsystem/WaveEngineSubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RenderTarget_Turbulence_MetaData[] = {
		{ "ModuleRelativePath", "Public/EngineSubsystem/WaveEngineSubsystem.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_WaveRenderTarget;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_H0KTexture;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_NoiseTexture;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_RenderTarget_H0K;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_RenderTarget_WavesData;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_RenderTarget_H0;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_TwiddleFactorRenderTarget;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_H0Texture;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_RenderTarget_DxDz;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_RenderTarget_DyDxz;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_RenderTarget_DyxDyz;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_RenderTarget_DxxDzz;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_TwiddleFactorTexture;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_RenderTarget_Buffer0;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_RenderTarget_Buffer1;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_RenderTarget_DxDz_I;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_RenderTarget_DyDxz_I;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_RenderTarget_DyxDyz_I;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_RenderTarget_DxxDzz_I;
	static const UECodeGen_Private::FUInt32PropertyParams NewProp_CurrentStep;
	static void NewProp_PingPong_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_PingPong;
	static const UECodeGen_Private::FUInt32PropertyParams NewProp_Size;
	static const UECodeGen_Private::FUInt32PropertyParams NewProp_Step;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_RenderTarget_Displacement;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_RenderTarget_Derivatives;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_RenderTarget_Turbulence;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UWaveEngineSubsystem>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UWaveEngineSubsystem_Statics::NewProp_WaveRenderTarget = { "WaveRenderTarget", nullptr, (EPropertyFlags)0x0144000000000000, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UWaveEngineSubsystem, WaveRenderTarget), Z_Construct_UClass_UTextureRenderTarget2D_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_WaveRenderTarget_MetaData), NewProp_WaveRenderTarget_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UWaveEngineSubsystem_Statics::NewProp_H0KTexture = { "H0KTexture", nullptr, (EPropertyFlags)0x0144000000000000, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UWaveEngineSubsystem, H0KTexture), Z_Construct_UClass_UTexture2D_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_H0KTexture_MetaData), NewProp_H0KTexture_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UWaveEngineSubsystem_Statics::NewProp_NoiseTexture = { "NoiseTexture", nullptr, (EPropertyFlags)0x0144000000000000, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UWaveEngineSubsystem, NoiseTexture), Z_Construct_UClass_UTexture2D_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_NoiseTexture_MetaData), NewProp_NoiseTexture_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UWaveEngineSubsystem_Statics::NewProp_RenderTarget_H0K = { "RenderTarget_H0K", nullptr, (EPropertyFlags)0x0144000000000000, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UWaveEngineSubsystem, RenderTarget_H0K), Z_Construct_UClass_UTextureRenderTarget2D_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RenderTarget_H0K_MetaData), NewProp_RenderTarget_H0K_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UWaveEngineSubsystem_Statics::NewProp_RenderTarget_WavesData = { "RenderTarget_WavesData", nullptr, (EPropertyFlags)0x0144000000000000, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UWaveEngineSubsystem, RenderTarget_WavesData), Z_Construct_UClass_UTextureRenderTarget2D_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RenderTarget_WavesData_MetaData), NewProp_RenderTarget_WavesData_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UWaveEngineSubsystem_Statics::NewProp_RenderTarget_H0 = { "RenderTarget_H0", nullptr, (EPropertyFlags)0x0144000000000000, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UWaveEngineSubsystem, RenderTarget_H0), Z_Construct_UClass_UTextureRenderTarget2D_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RenderTarget_H0_MetaData), NewProp_RenderTarget_H0_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UWaveEngineSubsystem_Statics::NewProp_TwiddleFactorRenderTarget = { "TwiddleFactorRenderTarget", nullptr, (EPropertyFlags)0x0144000000000000, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UWaveEngineSubsystem, TwiddleFactorRenderTarget), Z_Construct_UClass_UTextureRenderTarget2D_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TwiddleFactorRenderTarget_MetaData), NewProp_TwiddleFactorRenderTarget_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UWaveEngineSubsystem_Statics::NewProp_H0Texture = { "H0Texture", nullptr, (EPropertyFlags)0x0144000000000000, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UWaveEngineSubsystem, H0Texture), Z_Construct_UClass_UTexture2D_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_H0Texture_MetaData), NewProp_H0Texture_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UWaveEngineSubsystem_Statics::NewProp_RenderTarget_DxDz = { "RenderTarget_DxDz", nullptr, (EPropertyFlags)0x0144000000000000, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UWaveEngineSubsystem, RenderTarget_DxDz), Z_Construct_UClass_UTextureRenderTarget2D_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RenderTarget_DxDz_MetaData), NewProp_RenderTarget_DxDz_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UWaveEngineSubsystem_Statics::NewProp_RenderTarget_DyDxz = { "RenderTarget_DyDxz", nullptr, (EPropertyFlags)0x0144000000000000, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UWaveEngineSubsystem, RenderTarget_DyDxz), Z_Construct_UClass_UTextureRenderTarget2D_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RenderTarget_DyDxz_MetaData), NewProp_RenderTarget_DyDxz_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UWaveEngineSubsystem_Statics::NewProp_RenderTarget_DyxDyz = { "RenderTarget_DyxDyz", nullptr, (EPropertyFlags)0x0144000000000000, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UWaveEngineSubsystem, RenderTarget_DyxDyz), Z_Construct_UClass_UTextureRenderTarget2D_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RenderTarget_DyxDyz_MetaData), NewProp_RenderTarget_DyxDyz_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UWaveEngineSubsystem_Statics::NewProp_RenderTarget_DxxDzz = { "RenderTarget_DxxDzz", nullptr, (EPropertyFlags)0x0144000000000000, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UWaveEngineSubsystem, RenderTarget_DxxDzz), Z_Construct_UClass_UTextureRenderTarget2D_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RenderTarget_DxxDzz_MetaData), NewProp_RenderTarget_DxxDzz_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UWaveEngineSubsystem_Statics::NewProp_TwiddleFactorTexture = { "TwiddleFactorTexture", nullptr, (EPropertyFlags)0x0144000000000000, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UWaveEngineSubsystem, TwiddleFactorTexture), Z_Construct_UClass_UTexture2D_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TwiddleFactorTexture_MetaData), NewProp_TwiddleFactorTexture_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UWaveEngineSubsystem_Statics::NewProp_RenderTarget_Buffer0 = { "RenderTarget_Buffer0", nullptr, (EPropertyFlags)0x0144000000000000, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UWaveEngineSubsystem, RenderTarget_Buffer0), Z_Construct_UClass_UTextureRenderTarget2D_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RenderTarget_Buffer0_MetaData), NewProp_RenderTarget_Buffer0_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UWaveEngineSubsystem_Statics::NewProp_RenderTarget_Buffer1 = { "RenderTarget_Buffer1", nullptr, (EPropertyFlags)0x0144000000000000, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UWaveEngineSubsystem, RenderTarget_Buffer1), Z_Construct_UClass_UTextureRenderTarget2D_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RenderTarget_Buffer1_MetaData), NewProp_RenderTarget_Buffer1_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UWaveEngineSubsystem_Statics::NewProp_RenderTarget_DxDz_I = { "RenderTarget_DxDz_I", nullptr, (EPropertyFlags)0x0144000000000000, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UWaveEngineSubsystem, RenderTarget_DxDz_I), Z_Construct_UClass_UTextureRenderTarget2D_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RenderTarget_DxDz_I_MetaData), NewProp_RenderTarget_DxDz_I_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UWaveEngineSubsystem_Statics::NewProp_RenderTarget_DyDxz_I = { "RenderTarget_DyDxz_I", nullptr, (EPropertyFlags)0x0144000000000000, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UWaveEngineSubsystem, RenderTarget_DyDxz_I), Z_Construct_UClass_UTextureRenderTarget2D_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RenderTarget_DyDxz_I_MetaData), NewProp_RenderTarget_DyDxz_I_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UWaveEngineSubsystem_Statics::NewProp_RenderTarget_DyxDyz_I = { "RenderTarget_DyxDyz_I", nullptr, (EPropertyFlags)0x0144000000000000, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UWaveEngineSubsystem, RenderTarget_DyxDyz_I), Z_Construct_UClass_UTextureRenderTarget2D_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RenderTarget_DyxDyz_I_MetaData), NewProp_RenderTarget_DyxDyz_I_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UWaveEngineSubsystem_Statics::NewProp_RenderTarget_DxxDzz_I = { "RenderTarget_DxxDzz_I", nullptr, (EPropertyFlags)0x0144000000000000, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UWaveEngineSubsystem, RenderTarget_DxxDzz_I), Z_Construct_UClass_UTextureRenderTarget2D_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RenderTarget_DxxDzz_I_MetaData), NewProp_RenderTarget_DxxDzz_I_MetaData) };
const UECodeGen_Private::FUInt32PropertyParams Z_Construct_UClass_UWaveEngineSubsystem_Statics::NewProp_CurrentStep = { "CurrentStep", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::UInt32, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UWaveEngineSubsystem, CurrentStep), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CurrentStep_MetaData), NewProp_CurrentStep_MetaData) };
void Z_Construct_UClass_UWaveEngineSubsystem_Statics::NewProp_PingPong_SetBit(void* Obj)
{
	((UWaveEngineSubsystem*)Obj)->PingPong = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UWaveEngineSubsystem_Statics::NewProp_PingPong = { "PingPong", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UWaveEngineSubsystem), &Z_Construct_UClass_UWaveEngineSubsystem_Statics::NewProp_PingPong_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PingPong_MetaData), NewProp_PingPong_MetaData) };
const UECodeGen_Private::FUInt32PropertyParams Z_Construct_UClass_UWaveEngineSubsystem_Statics::NewProp_Size = { "Size", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::UInt32, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UWaveEngineSubsystem, Size), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Size_MetaData), NewProp_Size_MetaData) };
const UECodeGen_Private::FUInt32PropertyParams Z_Construct_UClass_UWaveEngineSubsystem_Statics::NewProp_Step = { "Step", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::UInt32, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UWaveEngineSubsystem, Step), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Step_MetaData), NewProp_Step_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UWaveEngineSubsystem_Statics::NewProp_RenderTarget_Displacement = { "RenderTarget_Displacement", nullptr, (EPropertyFlags)0x0144000000000000, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UWaveEngineSubsystem, RenderTarget_Displacement), Z_Construct_UClass_UTextureRenderTarget2D_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RenderTarget_Displacement_MetaData), NewProp_RenderTarget_Displacement_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UWaveEngineSubsystem_Statics::NewProp_RenderTarget_Derivatives = { "RenderTarget_Derivatives", nullptr, (EPropertyFlags)0x0144000000000000, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UWaveEngineSubsystem, RenderTarget_Derivatives), Z_Construct_UClass_UTextureRenderTarget2D_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RenderTarget_Derivatives_MetaData), NewProp_RenderTarget_Derivatives_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UWaveEngineSubsystem_Statics::NewProp_RenderTarget_Turbulence = { "RenderTarget_Turbulence", nullptr, (EPropertyFlags)0x0144000000000000, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UWaveEngineSubsystem, RenderTarget_Turbulence), Z_Construct_UClass_UTextureRenderTarget2D_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RenderTarget_Turbulence_MetaData), NewProp_RenderTarget_Turbulence_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UWaveEngineSubsystem_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UWaveEngineSubsystem_Statics::NewProp_WaveRenderTarget,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UWaveEngineSubsystem_Statics::NewProp_H0KTexture,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UWaveEngineSubsystem_Statics::NewProp_NoiseTexture,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UWaveEngineSubsystem_Statics::NewProp_RenderTarget_H0K,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UWaveEngineSubsystem_Statics::NewProp_RenderTarget_WavesData,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UWaveEngineSubsystem_Statics::NewProp_RenderTarget_H0,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UWaveEngineSubsystem_Statics::NewProp_TwiddleFactorRenderTarget,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UWaveEngineSubsystem_Statics::NewProp_H0Texture,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UWaveEngineSubsystem_Statics::NewProp_RenderTarget_DxDz,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UWaveEngineSubsystem_Statics::NewProp_RenderTarget_DyDxz,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UWaveEngineSubsystem_Statics::NewProp_RenderTarget_DyxDyz,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UWaveEngineSubsystem_Statics::NewProp_RenderTarget_DxxDzz,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UWaveEngineSubsystem_Statics::NewProp_TwiddleFactorTexture,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UWaveEngineSubsystem_Statics::NewProp_RenderTarget_Buffer0,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UWaveEngineSubsystem_Statics::NewProp_RenderTarget_Buffer1,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UWaveEngineSubsystem_Statics::NewProp_RenderTarget_DxDz_I,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UWaveEngineSubsystem_Statics::NewProp_RenderTarget_DyDxz_I,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UWaveEngineSubsystem_Statics::NewProp_RenderTarget_DyxDyz_I,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UWaveEngineSubsystem_Statics::NewProp_RenderTarget_DxxDzz_I,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UWaveEngineSubsystem_Statics::NewProp_CurrentStep,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UWaveEngineSubsystem_Statics::NewProp_PingPong,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UWaveEngineSubsystem_Statics::NewProp_Size,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UWaveEngineSubsystem_Statics::NewProp_Step,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UWaveEngineSubsystem_Statics::NewProp_RenderTarget_Displacement,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UWaveEngineSubsystem_Statics::NewProp_RenderTarget_Derivatives,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UWaveEngineSubsystem_Statics::NewProp_RenderTarget_Turbulence,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UWaveEngineSubsystem_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UWaveEngineSubsystem_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UEngineSubsystem,
	(UObject* (*)())Z_Construct_UPackage__Script_WaveSimulation,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UWaveEngineSubsystem_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UWaveEngineSubsystem_Statics::ClassParams = {
	&UWaveEngineSubsystem::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_UWaveEngineSubsystem_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_UWaveEngineSubsystem_Statics::PropPointers),
	0,
	0x001000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UWaveEngineSubsystem_Statics::Class_MetaDataParams), Z_Construct_UClass_UWaveEngineSubsystem_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UWaveEngineSubsystem()
{
	if (!Z_Registration_Info_UClass_UWaveEngineSubsystem.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UWaveEngineSubsystem.OuterSingleton, Z_Construct_UClass_UWaveEngineSubsystem_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UWaveEngineSubsystem.OuterSingleton;
}
UWaveEngineSubsystem::UWaveEngineSubsystem() {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UWaveEngineSubsystem);
UWaveEngineSubsystem::~UWaveEngineSubsystem() {}
// ********** End Class UWaveEngineSubsystem *******************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_11_TA_UEProjects_Seaside_Plugins_WaveSimulation_Source_WaveSimulation_Public_EngineSubsystem_WaveEngineSubsystem_h__Script_WaveSimulation_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UWaveEngineSubsystem, UWaveEngineSubsystem::StaticClass, TEXT("UWaveEngineSubsystem"), &Z_Registration_Info_UClass_UWaveEngineSubsystem, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UWaveEngineSubsystem), 2051873986U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_11_TA_UEProjects_Seaside_Plugins_WaveSimulation_Source_WaveSimulation_Public_EngineSubsystem_WaveEngineSubsystem_h__Script_WaveSimulation_3293229919(TEXT("/Script/WaveSimulation"),
	Z_CompiledInDeferFile_FID_11_TA_UEProjects_Seaside_Plugins_WaveSimulation_Source_WaveSimulation_Public_EngineSubsystem_WaveEngineSubsystem_h__Script_WaveSimulation_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_11_TA_UEProjects_Seaside_Plugins_WaveSimulation_Source_WaveSimulation_Public_EngineSubsystem_WaveEngineSubsystem_h__Script_WaveSimulation_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
