// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "IpvMultiplayerController.generated.h"

/**
 * 
 */
UCLASS()
class IPV7959_API AIpvMultiplayerController : public APlayerController
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent)
		void OnMissionCompleted(APawn* InstigatorPawn, bool bIsMissionCompleted);
};
