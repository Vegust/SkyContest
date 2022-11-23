// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "UI/SkyControlWidget.h"
#include "SkyContestGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class SKYCONTEST_API ASkyContestGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

protected:
	virtual void RestartPlayer(AController* NewPlayer) override;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<USkyControlWidget> SkyControlWidgetClass;
};
