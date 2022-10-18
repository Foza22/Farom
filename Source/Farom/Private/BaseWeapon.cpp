// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseWeapon.h"
#include "Components/SkeletalMeshComponent.h"
#include "Components/SphereComponent.h"
#include "Components/BoxComponent.h"
#include "BaseProjectile.h"
#include "GameFramework/Character.h"
#include "GameFramework/Controller.h"
#include "Farom/FaromCharacter.h"


// Sets default values
ABaseWeapon::ABaseWeapon()
{
	PrimaryActorTick.bCanEverTick = false;

	// Create mesh for weapon
	// Choose mesh in blueprint
	WeaponMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Mesh"));
	SetRootComponent(WeaponMesh);

	// Create Collision collider
	BoxCollider = CreateDefaultSubobject<UBoxComponent>(TEXT("Collider"));
	BoxCollider->SetGenerateOverlapEvents(true);
	BoxCollider->SetWorldScale3D(FVector(2.0f, 2.0f, 2.0f));
	// Get notify on overlapping
	BoxCollider->OnComponentBeginOverlap.AddDynamic(this, &ABaseWeapon::OnBeginOverlap);
	BoxCollider->AttachToComponent(RootComponent, FAttachmentTransformRules::SnapToTargetNotIncludingScale);

	// By default can't be taken
	bCanBeTaken = false;

	CurrentAmmo = DefaultAmmo;
}

void ABaseWeapon::OnBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	// Check if character overlap weapon pickup collider
	if ((OtherActor != nullptr) && (OtherActor != this) && (OtherComp != nullptr))
	{
		bCanBeTaken = true;
	}
}

void ABaseWeapon::Fire(const FVector& ViewLocation, const FRotator& ViewRotation)
{
	if (bCanFire)
	{
		UE_LOG(LogTemp, Display, TEXT("PEW PEW PEW"));
		MakeShot(ViewLocation, ViewRotation);
	}
}

void ABaseWeapon::MakeShot(const FVector& ViewLocation, const FRotator& ViewRotation)
{
	// If no ammo, exit function
	if (IsAmmoEmpty()) return;

	// Try and fire a projectile
	if (!ProjectileClass) return;

	if (!GetWorld()) return;

	// Get location of muzzle to spawn projectile
	const FTransform SocketTransform = WeaponMesh->GetSocketTransform(MuzzleSocketName);
	const FVector SpawnLocation = SocketTransform.GetLocation();


	// Get ViewRotation and configure it
	FRotator SpawnRotation = ViewRotation;
	SpawnRotation.Yaw += 2.0f;
	SpawnRotation.Pitch -= 5.0f;

	// Set Spawn Collision Handling Override
	FActorSpawnParameters ActorSpawnParams;
	ActorSpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButDontSpawnIfColliding;

	// Spawn the projectile at the muzzle
	GetWorld()->SpawnActor<ABaseProjectile>(ProjectileClass, SpawnLocation, SpawnRotation, ActorSpawnParams);

	DescreaseAmmo();
}

void ABaseWeapon::DescreaseAmmo()
{
	CurrentAmmo.BulletsAmount--;
	LogAmmo();

	if (IsClipEmpty() && !IsAmmoEmpty())
	{
		StartReload();
	}
}

bool ABaseWeapon::IsAmmoEmpty() const
{
	return IsClipEmpty() && CurrentAmmo.BulletsTotal == 0;
}

bool ABaseWeapon::IsClipEmpty() const
{
	return CurrentAmmo.BulletsAmount == 0;
}

void ABaseWeapon::StartReload()
{
	if (CurrentAmmo.BulletsTotal > 0)
	{
		bCanFire = false;
		bReloading = true;
		GetWorldTimerManager().SetTimer(ReloadTimerHandle, this, &ABaseWeapon::ChangeClip, 1.5f, false);
	}
}

void ABaseWeapon::ChangeClip()
{
	int32 NeedAmmo = DefaultAmmo.BulletsAmount - CurrentAmmo.BulletsAmount;

	if (NeedAmmo <= CurrentAmmo.BulletsTotal)
	{
		CurrentAmmo.BulletsAmount += NeedAmmo;
		CurrentAmmo.BulletsTotal -= NeedAmmo;
	}
	else
	{
		CurrentAmmo.BulletsAmount += CurrentAmmo.BulletsTotal;
		CurrentAmmo.BulletsTotal = 0;
	}

	bCanFire = true;
	bReloading = false;
}

void ABaseWeapon::LogAmmo()
{
	FString AmmoInfo = "Ammo: " + FString::FromInt(CurrentAmmo.BulletsAmount) + " / ";
	AmmoInfo += FString::FromInt(CurrentAmmo.BulletsTotal);
	UE_LOG(LogTemp, Display, TEXT("%s"), *AmmoInfo);
}