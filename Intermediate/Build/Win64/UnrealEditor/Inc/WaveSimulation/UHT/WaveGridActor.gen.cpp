// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "WaveGridActor.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

void EmptyLinkFunctionForGeneratedCodeWaveGridActor() {}

// ********** Begin Cross Module References ********************************************************
ENGINE_API UClass* Z_Construct_UClass_AActor();
ENGINE_API UClass* Z_Construct_UClass_UMaterialInterface_NoRegister();
PROCEDURALMESHCOMPONENT_API UClass* Z_Construct_UClass_UProceduralMeshComponent_NoRegister();
UPackage* Z_Construct_UPackage__Script_WaveSimulation();
WAVESIMULATION_API UClass* Z_Construct_UClass_AWaveGridActor();
WAVESIMULATION_API UClass* Z_Construct_UClass_AWaveGridActor_NoRegister();
// ********** End Cross Module References **********************************************************

// ********** Begin Class AWaveGridActor ***********************************************************
void AWaveGridActor::StaticRegisterNativesAWaveGridActor()
{
}
FClassRegistrationInfo Z_Registration_Info_UClass_AWaveGridActor;
UClass* AWaveGridActor::GetPrivateStaticClass()
{
	using TClass = AWaveGridActor;
	if (!Z_Registration_Info_UClass_AWaveGridActor.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			StaticPackage(),
			TEXT("WaveGridActor"),
			Z_Registration_Info_UClass_AWaveGridActor.InnerSingleton,
			StaticRegisterNativesAWaveGridActor,
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
	return Z_Registration_Info_UClass_AWaveGridActor.InnerSingleton;
}
UClass* Z_Construct_UClass_AWaveGridActor_NoRegister()
{
	return AWaveGridActor::GetPrivateStaticClass();
}
struct Z_Construct_UClass_AWaveGridActor_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "IncludePath", "WaveGridActor.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/WaveGridActor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_WaveMaterial_MetaData[] = {
		{ "Category", "Wave Grid" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// User-editable material for the wave grid\n" },
#endif
		{ "ModuleRelativePath", "Public/WaveGridActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "User-editable material for the wave grid" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ProcMesh_MetaData[] = {
		{ "Category", "WaveGridActor" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Procedural Mesh Component\n" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/WaveGridActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Procedural Mesh Component" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_NumVerts_MetaData[] = {
		{ "Category", "Wave Grid" },
		{ "ClampMax", "512" },
		{ "ClampMin", "2" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Number of vertices per side of the grid\n" },
#endif
		{ "ModuleRelativePath", "Public/WaveGridActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Number of vertices per side of the grid" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_GridSpacing_MetaData[] = {
		{ "Category", "Wave Grid" },
		{ "ClampMax", "1000.0" },
		{ "ClampMin", "1.0" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Distance between vertices\n" },
#endif
		{ "ModuleRelativePath", "Public/WaveGridActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Distance between vertices" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_WaveMaterial;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ProcMesh;
	static const UECodeGen_Private::FIntPropertyParams NewProp_NumVerts;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_GridSpacing;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AWaveGridActor>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AWaveGridActor_Statics::NewProp_WaveMaterial = { "WaveMaterial", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AWaveGridActor, WaveMaterial), Z_Construct_UClass_UMaterialInterface_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_WaveMaterial_MetaData), NewProp_WaveMaterial_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AWaveGridActor_Statics::NewProp_ProcMesh = { "ProcMesh", nullptr, (EPropertyFlags)0x00100000000a0009, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AWaveGridActor, ProcMesh), Z_Construct_UClass_UProceduralMeshComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ProcMesh_MetaData), NewProp_ProcMesh_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_AWaveGridActor_Statics::NewProp_NumVerts = { "NumVerts", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AWaveGridActor, NumVerts), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_NumVerts_MetaData), NewProp_NumVerts_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AWaveGridActor_Statics::NewProp_GridSpacing = { "GridSpacing", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AWaveGridActor, GridSpacing), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_GridSpacing_MetaData), NewProp_GridSpacing_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AWaveGridActor_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AWaveGridActor_Statics::NewProp_WaveMaterial,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AWaveGridActor_Statics::NewProp_ProcMesh,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AWaveGridActor_Statics::NewProp_NumVerts,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AWaveGridActor_Statics::NewProp_GridSpacing,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AWaveGridActor_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_AWaveGridActor_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AActor,
	(UObject* (*)())Z_Construct_UPackage__Script_WaveSimulation,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AWaveGridActor_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AWaveGridActor_Statics::ClassParams = {
	&AWaveGridActor::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_AWaveGridActor_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_AWaveGridActor_Statics::PropPointers),
	0,
	0x009001A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AWaveGridActor_Statics::Class_MetaDataParams), Z_Construct_UClass_AWaveGridActor_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_AWaveGridActor()
{
	if (!Z_Registration_Info_UClass_AWaveGridActor.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AWaveGridActor.OuterSingleton, Z_Construct_UClass_AWaveGridActor_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AWaveGridActor.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR(AWaveGridActor);
AWaveGridActor::~AWaveGridActor() {}
// ********** End Class AWaveGridActor *************************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_11_TA_UEProjects_Seaside_Plugins_WaveSimulation_Source_WaveSimulation_Public_WaveGridActor_h__Script_WaveSimulation_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AWaveGridActor, AWaveGridActor::StaticClass, TEXT("AWaveGridActor"), &Z_Registration_Info_UClass_AWaveGridActor, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AWaveGridActor), 830517515U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_11_TA_UEProjects_Seaside_Plugins_WaveSimulation_Source_WaveSimulation_Public_WaveGridActor_h__Script_WaveSimulation_4126874758(TEXT("/Script/WaveSimulation"),
	Z_CompiledInDeferFile_FID_11_TA_UEProjects_Seaside_Plugins_WaveSimulation_Source_WaveSimulation_Public_WaveGridActor_h__Script_WaveSimulation_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_11_TA_UEProjects_Seaside_Plugins_WaveSimulation_Source_WaveSimulation_Public_WaveGridActor_h__Script_WaveSimulation_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
