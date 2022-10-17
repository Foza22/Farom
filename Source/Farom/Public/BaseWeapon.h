// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BaseWeapon.generated.h"

class USkeletalMeshComponent;
class UBoxComponent;

UCLASS()
class FAROM_API ABaseWeapon : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ABaseWeapon();

	// Assisting variable
	bool bCanBeTaken;

protected:

private:

	// Mesh for our gun
	UPROPERTY(VisibleAnywhere, Category = Mesh)
		USkeletalMeshComponent* WeaponMesh;

	// Create Box collider for our gun
	UPROPERTY(EditAnywhere)
		UBoxComponent* BoxCollider;

	// Mark as CanBeTaken on overlapping
	UFUNCTION()
	void OnBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

};
