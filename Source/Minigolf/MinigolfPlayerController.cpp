#include "MinigolfPlayerController.h"
#include "GameFramework/Pawn.h"
#include "Blueprint/AIBlueprintHelperLibrary.h"
#include "NiagaraSystem.h"
#include "NiagaraFunctionLibrary.h"
#include "MinigolfCharacter.h"
#include "Engine/World.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "GolfBallPawn.h"

AMinigolfPlayerController::AMinigolfPlayerController()
{
}

void AMinigolfPlayerController::BeginPlay()
{
    // Call the base class
    Super::BeginPlay();

    playerState = GetPlayerState<AMinigolfPlayerState>();

    // Add Input Mapping Context
    if (UEnhancedInputLocalPlayerSubsystem *Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
    {
        Subsystem->AddMappingContext(DefaultMappingContext, 0);
    }
}

void AMinigolfPlayerController::SetupInputComponent()
{
    // set up gameplay key bindings
    Super::SetupInputComponent();

    // Set up action bindings
    if (UEnhancedInputComponent *EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(InputComponent))
    {
        EnhancedInputComponent->BindAction(LaunchBallPressedAction, ETriggerEvent::Triggered, this, &AMinigolfPlayerController::OnLaunchBallPressed);
        EnhancedInputComponent->BindAction(LaunchBallReleasedAction, ETriggerEvent::Triggered, this, &AMinigolfPlayerController::OnLaunchBallReleased);
        EnhancedInputComponent->BindAction(SetBallAngleAction, ETriggerEvent::Triggered, this, &AMinigolfPlayerController::OnSetBallAngle);
    }
}

void AMinigolfPlayerController::OnLaunchBallPressed()
{
    if (!playerState->GetIsMoving())
    {
        GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Launch Pressed!"));
        isHoldingLaunch = true;
    }
}

void AMinigolfPlayerController::OnLaunchBallReleased()
{
    if (!playerState->GetIsMoving())
    {
        AGolfBallPawn* pawn = GetPawn<AGolfBallPawn>();

        if (pawn != nullptr)
        {
            FVector2D swappedPos = FVector2D(mousePos.Y, mousePos.X);
            pawn->Launch(swappedPos * 1000);
        }

        if (playerState != nullptr)
            playerState->AddStroke();

        GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Launch Released!"));

        isHoldingLaunch = false;
        mousePos = FVector2D(0);
    }
}

void AMinigolfPlayerController::OnSetBallAngle(const FInputActionValue &value)
{
    if (isHoldingLaunch)
    {
        mousePos = value.Get<FVector2D>();
        GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Mouse Position: " + mousePos.ToString()));
    }
}
