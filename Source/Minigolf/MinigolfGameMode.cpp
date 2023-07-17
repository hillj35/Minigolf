#include "MinigolfGameMode.h"
#include "MinigolfPlayerController.h"
#include "MinigolfPlayerState.h"
#include "MinigolfCharacter.h"
#include "UObject/ConstructorHelpers.h"

AMinigolfGameMode::AMinigolfGameMode()
{
    // use our custom PlayerController class
    PlayerControllerClass = AMinigolfPlayerController::StaticClass();
    PlayerStateClass = AMinigolfPlayerState::StaticClass();

    // set default pawn class to our Blueprinted character
    if (PlayerPawnBPClass != nullptr)
    {
        DefaultPawnClass = PlayerPawnBPClass;
    }

    // set default controller to our Blueprinted controller
    if (PlayerControllerBPClass != NULL)
    {
        PlayerControllerClass = PlayerControllerBPClass;
    }

    // set HUD class
    if (GolfHUDBPClass != nullptr)
    {
        HUDClass = GolfHUDBPClass;
    }
}
