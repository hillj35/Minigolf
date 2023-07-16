#include "GolfBallPawn.h"

// Sets default values
AGolfBallPawn::AGolfBallPawn()
{
    // Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AGolfBallPawn::BeginPlay()
{
    Super::BeginPlay();

    // Set reference to the mesh.
    mesh = GetComponentByClass<UStaticMeshComponent>();
}

// Called every frame
void AGolfBallPawn::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}

void AGolfBallPawn::Launch(FVector2D force)
{
    if (mesh != nullptr)
        mesh->AddImpulse(FVector(force, 0));
}

// Called to bind functionality to input
void AGolfBallPawn::SetupPlayerInputComponent(UInputComponent *PlayerInputComponent)
{
    Super::SetupPlayerInputComponent(PlayerInputComponent);
}
