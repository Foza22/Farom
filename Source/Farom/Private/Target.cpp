// Fill out your copyright notice in the Description page of Project Settings.


#include "Target.h"
#include "Components/SphereComponent.h"

// Sets default values
ATarget::ATarget()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	// Creating sphere component for target
	SphereComp = CreateDefaultSubobject<USphereComponent>(TEXT("Sphere"));
	SphereComp->InitSphereRadius(130.0f);

	// Add sphere in blueprint

	// Attaching sphere and enabling collision
	SphereComp->SetupAttachment(RootComponent);
	SetRootComponent(SphereComp);
	SphereComp->SetCollisionProfileName(FName("BlockAll"));
}
