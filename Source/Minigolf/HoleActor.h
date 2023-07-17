// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "HoleActor.generated.h"

UCLASS()
class MINIGOLF_API AHoleActor : public AActor
{
    GENERATED_BODY()

public:
    // Sets default values for this actor's properties
    AHoleActor();

    UFUNCTION(BlueprintCallable, category = "Trigger")
    void BallEnter();

    UPROPERTY(EditAnywhere)
    FString LevelToLoad;

protected:
    // Called when the game starts or when spawned
    virtual void BeginPlay() override;

public:
    // Called every frame
    virtual void Tick(float DeltaTime) override;
};
