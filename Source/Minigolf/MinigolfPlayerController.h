#pragma once

#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "GameFramework/PlayerController.h"
#include "InputActionValue.h"
#include "MinigolfPlayerController.generated.h"

/** Forward declaration to improve compiling times */
class UNiagaraSystem;

UCLASS()
class AMinigolfPlayerController : public APlayerController
{
    GENERATED_BODY()

public:
    AMinigolfPlayerController();

    /** MappingContext */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
    class UInputMappingContext *DefaultMappingContext;

    /** SetBallAngle Input Action */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
    class UInputAction *SetBallAngleAction;

    /** LaunchBall */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
    class UInputAction *LaunchBallPressedAction;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
    class UInputAction *LaunchBallReleasedAction;

protected:
    virtual void SetupInputComponent() override;

    // To add mapping context
    virtual void BeginPlay();

    /** Input handlers for LaunchBall action. */
    void OnLaunchBallPressed();
    void OnLaunchBallReleased();

    /** Input handlers for SetBallAngle action. */
    void OnSetBallAngle(const FInputActionValue &value);

private:
    bool isHoldingLaunch = false;
    FVector2D mousePos;
};
