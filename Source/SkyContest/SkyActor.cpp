// Fill out your copyright notice in the Description page of Project Settings.


#include "SkyActor.h"

#include "Engine/Canvas.h"
#include "Kismet/KismetRenderingLibrary.h"
#include "Materials/MaterialParameterCollection.h"
#include "Materials/MaterialParameterCollectionInstance.h"

ASkyActor::ASkyActor()
{
	SkyMesh = CreateDefaultSubobject<UStaticMeshComponent>("SkyMesh");
	SkyMesh->SetMobility(EComponentMobility::Static);
	SetRootComponent(SkyMesh);
}

void ASkyActor::PostActorCreated()
{
	Super::PostActorCreated();
	if (IsTemplate() || !SkyParameterCollection)
	{
		return;
	}

	if (GetWorld())
	{
		SkyParameterCollectionInstance = GetWorld()->GetParameterCollectionInstance(Cast<UMaterialParameterCollection>(SkyParameterCollection));
		if (SkyParameterCollectionInstance)
		{
			SkyParameterCollectionInstance->OnVectorParameterUpdated().AddUObject(this, &ASkyActor::OnSkyVectorParameterChanged);
			SkyParameterCollectionInstance->OnScalarParameterUpdated().AddUObject(this, &ASkyActor::OnSkyScalarParameterChanged);
		}
	}

	UpdateSkyColor();
}

void ASkyActor::BeginPlay()
{
	Super::BeginPlay();
	UpdateSkyColor();
}

void ASkyActor::OnSkyVectorParameterChanged(TPair<FName, FLinearColor> UpdatedParameter)
{
	UpdateSkyColor();
}

void ASkyActor::OnSkyScalarParameterChanged(TPair<FName, float> UpdatedParameter)
{
	UpdateSkyColor();
}

void ASkyActor::UpdateSkyColor()
{
	if (!SkyParameterCollectionInstance && !SkyParameterCollection)
	{
		return;
	}
	
	UCanvas* DrawCanvas = nullptr;
	FVector2D DrawSize;
	FDrawToRenderTargetContext Context;
	
	UKismetRenderingLibrary::BeginDrawCanvasToRenderTarget(this,SkyColorRenderTarget,DrawCanvas,DrawSize,Context);
	if (DrawCanvas)
	{
		DrawCanvas->K2_DrawMaterial(SkyColorMaterial,FVector2D::ZeroVector,DrawSize,FVector2D::ZeroVector);
	}
	UKismetRenderingLibrary::EndDrawCanvasToRenderTarget(this, Context);
}


