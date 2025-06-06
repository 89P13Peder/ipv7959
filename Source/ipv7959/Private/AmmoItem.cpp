// Fill out your copyright notice in the Description page of Project Settings.


#include "AmmoItem.h"
#include "ipv7959Character.generated.h"
#include "Components/SphereComponent.h"


// Sets default values
AAmmoItem::AAmmoItem()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	
	CollisionSphere = CreateDefaultSubobject<USphereComponent>(TEXT("CollisionSphere"));
	CollisionSphere->SetSphereRadius(50.0f);
	CollisionSphere->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	CollisionSphere->SetCollisionObjectType(ECollisionChannel::ECC_WorldDynamic);
	CollisionSphere->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Overlap);

	RootComponent = CollisionSphere;
}

// Called when the game starts or when spawned
void AAmmoItem::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AAmmoItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AAmmoItem::NotifyActorBeginOverlap(AActor* OtherActor)
{
	Super::NotifyActorBeginOverlap(OtherActor);
	
	Aipv7959Character* MyCharacter = Cast<Aipv7959Character>(OtherActor);
	if (MyCharacter)
	{
		// Llamamos a la función para recargar la munición
		MyCharacter->ReloadAmmo();

		// Destruir el pickup para que desaparezca del nivel
		Destroy();
	}
}

