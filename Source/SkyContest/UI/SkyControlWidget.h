// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "SkyControlWidget.generated.h"

/**
 * 
 */
UCLASS()
class SKYCONTEST_API USkyControlWidget : public UUserWidget
{
	GENERATED_BODY()

protected:
	USkyControlWidget(const FObjectInitializer& ObjectInitializer);

	virtual void NativeConstruct() override;

	void OnSkyHeightSliderUsed();
	
	UPROPERTY(meta=(BindWidget))
	class USlider* SunHeightSlider;

	UPROPERTY(EditDefaultsOnly)
	UMaterialParameterCollection* SkyParameterCollection;
};
