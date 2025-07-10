// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "ipv7959GameMode.generated.h"

UCLASS(minimalapi)
class Aipv7959GameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	Aipv7959GameMode();

	void CompleteMision(APawn* Pawn);

	UFUNCTION(BlueprintImplementableEvent, Category="GameMode")
	void OnMisionCompleted(APawn* Pawn);
};



