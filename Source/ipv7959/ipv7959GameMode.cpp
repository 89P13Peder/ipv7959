// Copyright Epic Games, Inc. All Rights Reserved.

#include "ipv7959GameMode.h"
#include "ipv7959Character.h"
#include "UObject/ConstructorHelpers.h"

Aipv7959GameMode::Aipv7959GameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
