#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "GolfHUD.h"
#include "MinigolfGameMode.generated.h"

UCLASS(minimalapi)
class AMinigolfGameMode : public AGameModeBase
{
    GENERATED_BODY()

public:
    AMinigolfGameMode();

    UPROPERTY(EditAnywhere)
        TSubclassOf<APawn> PlayerPawnBPClass;

    UPROPERTY(EditAnywhere)
        TSubclassOf<APlayerController> PlayerControllerBPClass;

    UPROPERTY(EditAnywhere)
        TSubclassOf<AGolfHUD> GolfHUDBPClass;
};
