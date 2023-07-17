#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "MinigolfPlayerState.generated.h"

/**
 * 
 */
UCLASS()
class MINIGOLF_API AMinigolfPlayerState : public APlayerState
{
	GENERATED_BODY()

public:
	AMinigolfPlayerState();
	void ResetStrokes();
	void SetIsMoving(bool moving);
	bool GetIsMoving();

	UFUNCTION(BlueprintCallable, category = "State")
		void AddStroke();

	UPROPERTY(BlueprintReadOnly)
		int strokes;

private:
	bool isMoving;
};
