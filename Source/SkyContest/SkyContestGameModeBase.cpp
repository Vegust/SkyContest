// Copyright Epic Games, Inc. All Rights Reserved.


#include "SkyContestGameModeBase.h"

#include "Blueprint/UserWidget.h"

void ASkyContestGameModeBase::RestartPlayer(AController* NewPlayer)
{
	Super::RestartPlayer(NewPlayer);
	if (const auto PlayerController = Cast<APlayerController>(NewPlayer))
	{
		FInputModeGameAndUI InputMode{};
		InputMode.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
		PlayerController->SetInputMode(InputMode);
		PlayerController->bShowMouseCursor = true;
		if (IsValid(SkyControlWidgetClass))
		{
			CreateWidget<UUserWidget>(GetWorld(), SkyControlWidgetClass)->AddToViewport();
		}
	}
}
