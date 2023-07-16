// Fill out your copyright notice in the Description page of Project Settings.


#include "HoleActor.h"

// Sets default values
AHoleActor::AHoleActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AHoleActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AHoleActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AHoleActor::BallEnter()
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Ball In Hole Pog"));
}
