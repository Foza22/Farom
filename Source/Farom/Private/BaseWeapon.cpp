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

	// Set current ammo to default value
	CurrentAmmo = DefaultAmmo;
}

void ABaseWeapon::OnBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	// Check if character overlap weapon pickup collider
	if ((OtherActor != nullptr) && (OtherActor != this) && (OtherComp != nullptr))
	{
		// if we get in of weapon pick up radius, make it interactive
		bCanBeTaken = true;
	}
}

void ABaseWeapon::Fire(const FVector& ViewLocation, const FRotator& ViewRotation)
{
	if (bCanFire)
	{
		// Debug function
		//UE_LOG(LogTemp, Display, TEXT("PEW PEW PEW"));
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
	SpawnRotation.Yaw += 1.0f;
	SpawnRotation.Pitch -= 8.0f;

	// Set Spawn Collision Handling Override
	FActorSpawnParameters ActorSpawnParams;
	ActorSpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButDontSpawnIfColliding;

	// Spawn the projectile at the muzzle
	GetWorld()->SpawnActor<ABaseProjectile>(ProjectileClass, SpawnLocation, SpawnRotation, ActorSpawnParams);

	// On every shot use 1 ammo
	DescreaseAmmo();
}

void ABaseWeapon::DescreaseAmmo()
{
	CurrentAmmo.BulletsAmount--;
	// Debug log
	//LogAmmo();

	// If no ammo in clip and have ammo in stash - start reload
	if (IsClipEmpty() && !IsAmmoEmpty())
	{
		StartReload();
	}
}

// If we have no ammo at all return true
bool ABaseWeapon::IsAmmoEmpty() const
{
	return IsClipEmpty() && CurrentAmmo.BulletsTotal == 0;
}

// If no ammo in current clip return true
bool ABaseWeapon::IsClipEmpty() const
{
	return CurrentAmmo.BulletsAmount == 0;
}

void ABaseWeapon::StartReload()
{
	// If we have bullets in stash start reloading
	if (CurrentAmmo.BulletsTotal > 0)
	{
		// Can't fire during reloading
		bCanFire = false;
		bReloading = true;
		// Start reloading "animation" for 1.5s
		GetWorldTimerManager().SetTimer(ReloadTimerHandle, this, &ABaseWeapon::ChangeClip, 1.5f, false);
	}
}

void ABaseWeapon::ChangeClip()
{
	// Get amount of ammo we lack in clip
	int32 NeedAmmo = DefaultAmmo.BulletsAmount - CurrentAmmo.BulletsAmount;

	// if we have such amount of ammo in stash fill our clip
	if (NeedAmmo <= CurrentAmmo.BulletsTotal)
	{
		CurrentAmmo.BulletsAmount += NeedAmmo;
		CurrentAmmo.BulletsTotal -= NeedAmmo;
	}
	else
	{
		// if not just use as much as possible
		CurrentAmmo.BulletsAmount += CurrentAmmo.BulletsTotal;
		CurrentAmmo.BulletsTotal = 0;
	}

	// Let fire at the end
	bCanFire = true;
	bReloading = false;
}

// Debug function
void ABaseWeapon::LogAmmo()
{
	FString AmmoInfo = "Ammo: " + FString::FromInt(CurrentAmmo.BulletsAmount) + " / ";
	AmmoInfo += FString::FromInt(CurrentAmmo.BulletsTotal);
	//UE_LOG(LogTemp, Display, TEXT("%s"), *AmmoInfo);
}