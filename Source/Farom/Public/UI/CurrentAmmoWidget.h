// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "CurrentAmmoWidget.generated.h"

struct FAmmoData;

UCLASS()
class FAROM_API UCurrentAmmoWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable, Category = UI)
		int32 GetAmmoInClip() const;

	UFUNCTION(BlueprintCallable, Category = UI)
		int32 GetAmmoTotal() const;

	UFUNCTION(BlueprintCallable, Category = UI)
		bool IsReloading() const;
};
