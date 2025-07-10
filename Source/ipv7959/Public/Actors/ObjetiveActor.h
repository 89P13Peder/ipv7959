// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ObjetiveActor.generated.h"

class USphereComponent;
class UParticleSystem;

UCLASS()
class IPV7959_API AObjetiveActor : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AObjetiveActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	UPROPERTY(VisibleAnywhere, Category="Components")
	UStaticMeshComponent* MeshComp;
	
	UPROPERTY(VisibleAnywhere, Category="Components")
	USphereComponent* SphereComp;

	UPROPERTY(EditDefaultsOnly, Category="VFX")
	UParticleSystem* PickUpVFX;

	void PlayEffects();

public:

	virtual void NotifyActorBeginOverlap(AActor* OtherActor) override;
	
};
