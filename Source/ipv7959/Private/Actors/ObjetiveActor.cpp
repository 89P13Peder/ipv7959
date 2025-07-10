

#include "Actors/ObjetiveActor.h"

#include "Components/SphereComponent.h"
#include "ipv7959/ipv7959Character.h"
#include "Kismet/GameplayStatics.h"


// Sets default values
AObjetiveActor::AObjetiveActor()
{
	PrimaryActorTick.bCanEverTick = true;

	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComp"));
	MeshComp->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	RootComponent = MeshComp;

	SphereComp = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComp"));
	SphereComp->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	SphereComp->SetCollisionResponseToChannels(ECR_Ignore);
	SphereComp->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap);
	SphereComp->SetupAttachment(RootComponent);
}

void AObjetiveActor::BeginPlay()
{
	Super::BeginPlay();
	
}

void AObjetiveActor::PlayEffects()
{
	UGameplayStatics::SpawnEmitterAtLocation(this, PickUpVFX,GetActorLocation());
}

void AObjetiveActor::NotifyActorBeginOverlap(AActor* OtherActor)
{
	Super::NotifyActorBeginOverlap(OtherActor);
	PlayEffects();

	Aipv7959Character* myCharacter = Cast<Aipv7959Character>(OtherActor);
	if (myCharacter)
	{
		myCharacter->bIsCarringObjective = true;
		Destroy();
	}
}

