// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Target.generated.h"

class USphereComponent;

UCLASS()
class FAROM_API ATarget : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATarget();

protected:
	// Target collision
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		USphereComponent* SphereComp;
};
