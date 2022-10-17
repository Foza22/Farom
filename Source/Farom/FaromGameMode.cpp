// Copyright Epic Games, Inc. All Rights Reserved.

#include "FaromGameMode.h"
#include "FaromCharacter.h"
#include "UObject/ConstructorHelpers.h"

AFaromGameMode::AFaromGameMode()
{
	// set default pawn class to our Blueprinted character
	/*static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}*/

	// Set our cpp character as default
	DefaultPawnClass = AFaromCharacter::StaticClass();
}
