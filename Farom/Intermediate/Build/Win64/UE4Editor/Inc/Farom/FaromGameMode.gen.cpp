// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Farom/FaromGameMode.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeFaromGameMode() {}
// Cross Module References
	FAROM_API UClass* Z_Construct_UClass_AFaromGameMode_NoRegister();
	FAROM_API UClass* Z_Construct_UClass_AFaromGameMode();
	ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
	UPackage* Z_Construct_UPackage__Script_Farom();
// End Cross Module References
	void AFaromGameMode::StaticRegisterNativesAFaromGameMode()
	{
	}
	UClass* Z_Construct_UClass_AFaromGameMode_NoRegister()
	{
		return AFaromGameMode::StaticClass();
	}
	struct Z_Construct_UClass_AFaromGameMode_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AFaromGameMode_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AGameModeBase,
		(UObject* (*)())Z_Construct_UPackage__Script_Farom,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AFaromGameMode_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering Utilities|Transformation" },
		{ "IncludePath", "FaromGameMode.h" },
		{ "ModuleRelativePath", "FaromGameMode.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_AFaromGameMode_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AFaromGameMode>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AFaromGameMode_Statics::ClassParams = {
		&AFaromGameMode::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x008802ACu,
		METADATA_PARAMS(Z_Construct_UClass_AFaromGameMode_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AFaromGameMode_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AFaromGameMode()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AFaromGameMode_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AFaromGameMode, 722819771);
	template<> FAROM_API UClass* StaticClass<AFaromGameMode>()
	{
		return AFaromGameMode::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AFaromGameMode(Z_Construct_UClass_AFaromGameMode, &AFaromGameMode::StaticClass, TEXT("/Script/Farom"), TEXT("AFaromGameMode"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AFaromGameMode);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
