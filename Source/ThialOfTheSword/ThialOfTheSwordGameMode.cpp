// Copyright Epic Games, Inc. All Rights Reserved.

#include "ThialOfTheSwordGameMode.h"
#include "ThialOfTheSwordCharacter.h"
#include "UObject/ConstructorHelpers.h"

AThialOfTheSwordGameMode::AThialOfTheSwordGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
