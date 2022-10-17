// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef FAROM_FaromCharacter_generated_h
#error "FaromCharacter.generated.h already included, missing '#pragma once' in FaromCharacter.h"
#endif
#define FAROM_FaromCharacter_generated_h

#define Farom_Source_Farom_FaromCharacter_h_12_SPARSE_DATA
#define Farom_Source_Farom_FaromCharacter_h_12_RPC_WRAPPERS
#define Farom_Source_Farom_FaromCharacter_h_12_RPC_WRAPPERS_NO_PURE_DECLS
#define Farom_Source_Farom_FaromCharacter_h_12_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAFaromCharacter(); \
	friend struct Z_Construct_UClass_AFaromCharacter_Statics; \
public: \
	DECLARE_CLASS(AFaromCharacter, ACharacter, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Farom"), NO_API) \
	DECLARE_SERIALIZER(AFaromCharacter)


#define Farom_Source_Farom_FaromCharacter_h_12_INCLASS \
private: \
	static void StaticRegisterNativesAFaromCharacter(); \
	friend struct Z_Construct_UClass_AFaromCharacter_Statics; \
public: \
	DECLARE_CLASS(AFaromCharacter, ACharacter, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Farom"), NO_API) \
	DECLARE_SERIALIZER(AFaromCharacter)


#define Farom_Source_Farom_FaromCharacter_h_12_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AFaromCharacter(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AFaromCharacter) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AFaromCharacter); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AFaromCharacter); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AFaromCharacter(AFaromCharacter&&); \
	NO_API AFaromCharacter(const AFaromCharacter&); \
public:


#define Farom_Source_Farom_FaromCharacter_h_12_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AFaromCharacter(AFaromCharacter&&); \
	NO_API AFaromCharacter(const AFaromCharacter&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AFaromCharacter); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AFaromCharacter); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AFaromCharacter)


#define Farom_Source_Farom_FaromCharacter_h_12_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__CameraBoom() { return STRUCT_OFFSET(AFaromCharacter, CameraBoom); } \
	FORCEINLINE static uint32 __PPO__FollowCamera() { return STRUCT_OFFSET(AFaromCharacter, FollowCamera); }


#define Farom_Source_Farom_FaromCharacter_h_9_PROLOG
#define Farom_Source_Farom_FaromCharacter_h_12_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Farom_Source_Farom_FaromCharacter_h_12_PRIVATE_PROPERTY_OFFSET \
	Farom_Source_Farom_FaromCharacter_h_12_SPARSE_DATA \
	Farom_Source_Farom_FaromCharacter_h_12_RPC_WRAPPERS \
	Farom_Source_Farom_FaromCharacter_h_12_INCLASS \
	Farom_Source_Farom_FaromCharacter_h_12_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define Farom_Source_Farom_FaromCharacter_h_12_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Farom_Source_Farom_FaromCharacter_h_12_PRIVATE_PROPERTY_OFFSET \
	Farom_Source_Farom_FaromCharacter_h_12_SPARSE_DATA \
	Farom_Source_Farom_FaromCharacter_h_12_RPC_WRAPPERS_NO_PURE_DECLS \
	Farom_Source_Farom_FaromCharacter_h_12_INCLASS_NO_PURE_DECLS \
	Farom_Source_Farom_FaromCharacter_h_12_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> FAROM_API UClass* StaticClass<class AFaromCharacter>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID Farom_Source_Farom_FaromCharacter_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
