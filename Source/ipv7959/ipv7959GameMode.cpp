// Copyright Epic Games, Inc. All Rights Reserved.

#include "ipv7959GameMode.h"
#include "ipv7959Character.h"
#include "Kismet/GameplayStatics.h"
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

void Aipv7959GameMode::CompleteMision(APawn* Pawn)
{
	if (Pawn == nullptr) return;
	
	OnMisionCompleted(Pawn);
	if (SpectatorViewClass)
	{
		TArray<AActor*> ReturnActors;
		UGameplayStatics::GetAllActorsOfClass(this, SpectatorViewClass, ReturnActors);
		if (ReturnActors.Num() > 0)
		{
			AActor* NewViewTarget = ReturnActors[0];
			APlayerController* PC = Cast<APlayerController>(Pawn->GetController());

			if (PC )
			{
				PC->SetViewTargetWithBlend(NewViewTarget, 1.0f, VTBlend_Cubic);
			}
		}
	}
	Pawn->DisableInput(nullptr);
}
