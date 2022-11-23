// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/TextureRenderTarget.h"
#include "GameFramework/Actor.h"
#include "SkyActor.generated.h"

UCLASS()
class SKYCONTEST_API ASkyActor : public AActor
{
	GENERATED_BODY()

public:
	ASkyActor();

protected:
	virtual void PostActorCreated() override;
	virtual void BeginPlay() override;

	void UpdateSkyColor();
	void OnSkyVectorParameterChanged(TPair<FName, FLinearColor> UpdatedParameter);
	void OnSkyScalarParameterChanged(TPair<FName, float> UpdatedParameter);

	UPROPERTY(Transient)
	UMaterialParameterCollectionInstance* SkyParameterCollectionInstance;
	
	UPROPERTY(EditDefaultsOnly, Category="Sky")
	UMaterialParameterCollection* SkyParameterCollection;

	UPROPERTY(EditDefaultsOnly, Category="Sky")
	UStaticMeshComponent* SkyMesh;

	UPROPERTY(EditDefaultsOnly, Category="SkyColor")
	UTextureRenderTarget2D* SkyColorRenderTarget;

	UPROPERTY(EditDefaultsOnly, Category="SkyColor")
	UMaterialInterface* SkyColorMaterial;
};
