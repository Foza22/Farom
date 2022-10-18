// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BaseWeapon.generated.h"

class USkeletalMeshComponent;
class UBoxComponent;
class ABaseProjectile;

USTRUCT(BlueprintType)
struct FAmmoData
{
	GENERATED_USTRUCT_BODY()
public:
	// Amount of bullets in clip
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = Weapon)
		int32 BulletsAmount;

	// Total amount of bullets
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = Weapon)
		int32 BulletsTotal;
};

UCLASS()
class FAROM_API ABaseWeapon : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ABaseWeapon();

	// Assisting variable
	bool bCanBeTaken;
	bool bCanFire;
	bool bReloading;

	void Fire(const FVector& ViewLocation, const FRotator& ViewRotation);
	void MakeShot(const FVector& ViewLocation, const FRotator& ViewRotation);

	// Function to start reloading
	void StartReload();

	// Timer handle for reloading
	FTimerHandle ReloadTimerHandle;

	// Functions for UI
	FAmmoData GetAmmoData() const { return CurrentAmmo; }
	bool IsReloading() { return bReloading; }

protected:
	// Name for muzzle socket
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		FName MuzzleSocketName = "Muzzle";

	// Mesh for our gun
	UPROPERTY(VisibleAnywhere, Category = Mesh)
		USkeletalMeshComponent* WeaponMesh;

	// Create Box collider for our gun
	UPROPERTY(EditAnywhere, Category = ColliderBox)
		UBoxComponent* BoxCollider;

	// Projectile class to spawn
	UPROPERTY(EditDefaultsOnly, Category = Projectile)
		TSubclassOf<ABaseProjectile> ProjectileClass;

	// Information about ammo
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = Weapon)
		FAmmoData DefaultAmmo {30,120};

	// Mark as CanBeTaken on overlapping
	UFUNCTION()
		void OnBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	// Helping functions for reload and shooting
	void DescreaseAmmo();
	bool IsAmmoEmpty() const;
	bool IsClipEmpty() const;
	void ChangeClip();
	// Debug function
	void LogAmmo();

private:
	// Stores current amount of ammo
	FAmmoData CurrentAmmo;
};
