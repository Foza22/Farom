// Copyright Epic Games, Inc. All Rights Reserved.

#include "FaromGameMode.h"
#include "FaromCharacter.h"
#include "UI/FaromHUD.h"
#include "UObject/ConstructorHelpers.h"

AFaromGameMode::AFaromGameMode()
{
	
	// Set our cpp character as default
	DefaultPawnClass = AFaromCharacter::StaticClass();

	// Set own hud class
	HUDClass = AFaromHUD::StaticClass();
}
