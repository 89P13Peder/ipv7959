// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameState.h"
#include "ipvMultiGameState.generated.h"

/**
 * 
 */
UCLASS()
class IPV7959_API AipvMultiGameState : public AGameStateBase
{
	GENERATED_BODY()

public:
	UFUNCTION(NetMulticast, Reliable)
	void MulticastOnMisionCompleted(APawn* InstigatorPawn, bool bWasSuccesful); //instigator es el responsable de haber hecho una acción

};
