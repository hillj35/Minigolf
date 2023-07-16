#include "MinigolfGameMode.h"
#include "MinigolfPlayerController.h"
#include "MinigolfCharacter.h"
#include "UObject/ConstructorHelpers.h"

AMinigolfGameMode::AMinigolfGameMode()
{
    // use our custom PlayerController class
    PlayerControllerClass = AMinigolfPlayerController::StaticClass();

    // set default pawn class to our Blueprinted character
    static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/Blueprints/BP_GolfBallPawn"));
    if (PlayerPawnBPClass.Class != nullptr)
    {
        DefaultPawnClass = PlayerPawnBPClass.Class;
    }

    // set default controller to our Blueprinted controller
    static ConstructorHelpers::FClassFinder<APlayerController> PlayerControllerBPClass(TEXT("/Game/Blueprints/BP_MinigolfPlayerController"));
    if (PlayerControllerBPClass.Class != NULL)
    {
        PlayerControllerClass = PlayerControllerBPClass.Class;
    }
}
