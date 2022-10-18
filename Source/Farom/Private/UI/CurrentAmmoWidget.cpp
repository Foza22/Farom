// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/CurrentAmmoWidget.h"
#include "BaseWeapon.h"
#include "Farom/FaromCharacter.h"

int32 UCurrentAmmoWidget::GetAmmoInClip() const
{
	const auto Pawn = GetOwningPlayerPawn();
	if (!Pawn) return 0;

	const auto Player = Cast< AFaromCharacter>(Pawn);
	const auto Weapon = Player->GetWeapon();
	if (!Weapon) return 0;

	return Weapon->GetAmmoData().BulletsAmount;
}

int32 UCurrentAmmoWidget::GetAmmoTotal() const
{
	const auto Pawn = GetOwningPlayerPawn();
	if (!Pawn) return 0;

	const auto Player = Cast< AFaromCharacter>(Pawn);
	const auto Weapon = Player->GetWeapon();
	if (!Weapon) return 0;

	return Weapon->GetAmmoData().BulletsTotal;
}

bool UCurrentAmmoWidget::IsReloading() const
{
	const auto Pawn = GetOwningPlayerPawn();
	if (!Pawn) return false;

	const auto Player = Cast< AFaromCharacter>(Pawn);
	const auto Weapon = Player->GetWeapon();
	if (!Weapon) return false;

	return Weapon->IsReloading();
}
