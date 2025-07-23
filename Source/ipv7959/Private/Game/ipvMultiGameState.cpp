// Fill out your copyright notice in the Description page of Project Settings.


#include "Game/ipvMultiGameState.h"
#include "EngineUtils.h"
#include "Player/IpvMultiplayerController.h"

void AipvMultiGameState::MulticastOnMisionCompleted_Implementation(APawn* InstigatorPawn, bool bWasSuccesful)
{
	// if (APlayerController* PC = GetWorld()->GetFirstPlayerController())
	// 	if (APawn* Pawn = PC->GetPawn())
	// 		Pawn->DisableInput(nullptr);

	for (FConstPlayerControllerIterator It = GetWorld()->GetPlayerControllerIterator(); It; It++)
	{
		AIpvMultiplayerController* PC = Cast<AIpvMultiplayerController>(It->Get());
		if (PC)
		{
			PC->OnMissionCompleted(InstigatorPawn, bWasSuccesful);
			APawn* Pawn = PC->GetPawn();
			if(Pawn)
			{
				Pawn->DisableInput(nullptr);			
			}
		}
	}
}

