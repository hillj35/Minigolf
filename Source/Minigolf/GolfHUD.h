

#pragma once

#include "GameFramework/HUD.h"
#include "Blueprint/UserWidget.h"
#include "GolfHUD.generated.h"

/**
 * 
 */
UCLASS()
class MINIGOLF_API AGolfHUD : public AHUD
{
	GENERATED_BODY()
	
public:
	AGolfHUD();

	virtual void BeginPlay() override;

	/** Class of user widget, loaded from Content Browser */
	UPROPERTY(EditAnywhere)
		TSubclassOf<UUserWidget> widgetHUD;

	/* Reference to created user widget*/
	class UUserWidget* widgetHUDInstance;
};
