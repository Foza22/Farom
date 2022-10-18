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
	// UI function for current ammo
	UFUNCTION(BlueprintCallable, Category = UI)
		int32 GetAmmoInClip() const;
	
	// UI function for ammo in total
	UFUNCTION(BlueprintCallable, Category = UI)
		int32 GetAmmoTotal() const;

	// Function for drawing UI reloading
	UFUNCTION(BlueprintCallable, Category = UI)
		bool IsReloading() const;
};
