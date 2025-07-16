

#include "Actors/ObjectiveZone.h"

#include "Components/BoxComponent.h"
#include "Components/DecalComponent.h"
#include "ipv7959/ipv7959Character.h"
#include "ipv7959/ipv7959GameMode.h"


AObjectiveZone::AObjectiveZone()
{
	OverlapComp = CreateDefaultSubobject<UBoxComponent>(TEXT("OverlapComponent"));
	OverlapComp->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	OverlapComp->SetCollisionResponseToChannels(ECR_Ignore);
	OverlapComp->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap);
	RootComponent = OverlapComp;
	OverlapComp->SetHiddenInGame(false);

	DecalComp = CreateDefaultSubobject<UDecalComponent>(TEXT("DecalComp"));
	DecalComp->DecalSize = FVector(200);
	DecalComp->SetupAttachment(RootComponent);
}

void AObjectiveZone::BeginPlay()
{
	Super::BeginPlay();
	
}
//Post initialize components solo para vincular delegates.
void AObjectiveZone::PostInitializeComponents()
{
	Super::PostInitializeComponents();
	OverlapComp->OnComponentBeginOverlap.AddDynamic(this, &ThisClass::HandleOverlap);
}

void AObjectiveZone::HandleOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
                                   UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(
					-1,
					10.f,
					FColor::Green,
					FString::Printf(TEXT("Overlapped"))
				);
	}

	Aipv7959Character* MyPawn = Cast<Aipv7959Character>(OtherActor);
	if (MyPawn == nullptr) return;

	if (MyPawn->bIsCarringObjective)
	{
		Aipv7959GameMode* GM = Cast<Aipv7959GameMode>(GetWorld()->GetAuthGameMode());
		 if (GM)
		 {
			 GM->CompleteMision(MyPawn);
		 }
	}
}



