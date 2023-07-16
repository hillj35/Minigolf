#include "GolfHUD.h"

AGolfHUD::AGolfHUD()
{

}

void AGolfHUD::BeginPlay()
{
	Super::BeginPlay();

	widgetHUDInstance = CreateWidget<UUserWidget>(GetWorld(), widgetHUD);
	if (widgetHUDInstance)
		widgetHUDInstance->AddToViewport();
}