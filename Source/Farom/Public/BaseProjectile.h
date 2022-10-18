// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BaseProjectile.generated.h"

class USphereComponent;
class UProjectileMovementComponent;
class USkeletalMeshComponent;

UCLASS()
class FAROM_API ABaseProjectile : public AActor
{
	GENERATED_BODY()

	// Sphere collision component
	UPROPERTY(VisibleDefaultsOnly, Category = Projectile)
		USphereComponent* CollisionComp;

	// Add and configure sphere in blueprints

	// Projectile movement component
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Movement, meta = (AllowPrivateAccess = "true"))
		UProjectileMovementComponent* ProjectileMovement;

public:
	// Sets default values for this actor's properties
	ABaseProjectile();
	
	// called when projectile hits something
	UFUNCTION()
		virtual void OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

	//// Returns CollisionComp subobject
	//USphereComponent* GetCollisionComp() const { return CollisionComp; }
	//// Returns ProjectileMovement subobject
	//UProjectileMovementComponent* GetProjectileMovement() const { return ProjectileMovement; }
};
