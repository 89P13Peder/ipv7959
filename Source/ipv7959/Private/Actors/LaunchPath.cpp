// Fill out your copyright notice in the Description page of Project Settings.


#include "ipv7959/Public/Actors/LaunchPath.h"


// Sets default values
ALaunchPath::ALaunchPath()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ALaunchPath::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ALaunchPath::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

