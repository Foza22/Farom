// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "FaromHUD.generated.h"

class UUSerWidget;

UCLASS()
class FAROM_API AFaromHUD : public AHUD
{
	GENERATED_BODY()

public:
	// Call for drawing the HUD
	virtual void DrawHUD() override;

private:
	// Crosshair asset pointer
	void DrawCrosshair();
};
