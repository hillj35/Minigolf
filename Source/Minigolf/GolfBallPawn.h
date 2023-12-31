#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "MinigolfPlayerState.h"
#include "GolfBallPawn.generated.h"

UCLASS()
class MINIGOLF_API AGolfBallPawn : public APawn
{
    GENERATED_BODY()

public:
    // Sets default values for this pawn's properties
    AGolfBallPawn();

protected:
    // Called when the game starts or when spawned
    virtual void BeginPlay() override;

public:
    // Called every frame
    virtual void Tick(float DeltaTime) override;

    void Launch(FVector2D force);

    // Called to bind functionality to input
    virtual void SetupPlayerInputComponent(class UInputComponent *PlayerInputComponent) override;

private:
    UStaticMeshComponent *mesh;
    AMinigolfPlayerState *playerState;
};
