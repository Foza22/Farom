// Copyright Epic Games, Inc. All Rights Reserved.

#include "FaromCharacter.h"
#include "HeadMountedDisplayFunctionLibrary.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/Controller.h"
#include "GameFramework/SpringArmComponent.h"
#include "Animation/SkeletalMeshActor.h"
#include "BaseWeapon.h"

//////////////////////////////////////////////////////////////////////////
// AFaromCharacter

AFaromCharacter::AFaromCharacter()
{
	// Set size for collision capsule
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);

	// set our turn rates for input
	BaseTurnRate = 45.f;
	BaseLookUpRate = 45.f;

	// Configure character movement
	GetCharacterMovement()->bOrientRotationToMovement = true; // Character moves in the direction of input...	
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 540.0f, 0.0f); // ...at this rotation rate
	GetCharacterMovement()->JumpZVelocity = 600.f;
	GetCharacterMovement()->AirControl = 0.2f;

	// Create a camera boom (pulls in towards the player if there is a collision)
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->TargetArmLength = 300.0f; // The camera follows at this distance behind the character	
	CameraBoom->bUsePawnControlRotation = true; // Rotate the arm based on the controller

	// I changed a location of camera a little bit
	// Change camera boom parameters to move camera to right
	CameraBoom->SetRelativeLocation(FVector(0.f, 0.f, 60.f));
	CameraBoom->SocketOffset.Z = 90.f;
	CameraBoom->SocketOffset.X = 70.f;

	// Create a follow camera
	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom); // Attach the camera to the end of the boom and let the boom adjust to match the controller orientation
	FollowCamera->bUsePawnControlRotation = false; // Camera does not rotate relative to arm
	FollowCamera->SetRelativeRotation(FRotator(10.f, 0.f, 0.f)); // Turn camera to look right at character

	// Note: The skeletal mesh and anim blueprint references on the Mesh component (inherited from Character) 
	// are set in the derived blueprint asset named MyCharacter (to avoid direct content references in C++)
}

void AFaromCharacter::BeginPlay()
{
	Super::BeginPlay();

}

//////////////////////////////////////////////////////////////////////////
// Input

void AFaromCharacter::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	// Set up gameplay key bindings
	check(PlayerInputComponent);
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping);

	PlayerInputComponent->BindAxis("MoveForward", this, &AFaromCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &AFaromCharacter::MoveRight);

	// We have 2 versions of the rotation bindings to handle different kinds of devices differently
	// "turn" handles devices that provide an absolute delta, such as a mouse.
	// "turnrate" is for devices that we choose to treat as a rate of change, such as an analog joystick
	PlayerInputComponent->BindAxis("Turn", this, &AFaromCharacter::Turn);
	PlayerInputComponent->BindAxis("TurnRate", this, &AFaromCharacter::TurnAtRate);
	PlayerInputComponent->BindAxis("LookUp", this, &AFaromCharacter::LookUp);
	PlayerInputComponent->BindAxis("LookUpRate", this, &AFaromCharacter::LookUpAtRate);

	// Bind our pickup action
	PlayerInputComponent->BindAction("Pickup", IE_Pressed, this, &AFaromCharacter::Pickup);
}

void AFaromCharacter::LookUp(float Value)
{
	AddControllerPitchInput(Value);
}

void AFaromCharacter::Turn(float Value)
{
	AddControllerYawInput(Value);
}

void AFaromCharacter::Pickup()
{
	// Create the array for all objects in area
	TArray<AActor*> InRange;
	GetOverlappingActors(InRange);

	for (int i = 0; i < InRange.Num(); ++i)
	{
		// If we can cast element in radius to our object we destroy it on map and spawn like our weapon
		const auto Weapon = Cast<ABaseWeapon>(InRange[i]);
		// And if we are in radius of object collision
		if (Weapon->bCanBeTaken)
		{
			Weapon->Destroy();
			SpawnWeapon();
		}
	}

}

void AFaromCharacter::SpawnWeapon()
{
	if (!GetWorld()) return;

	// Spawn weapon
	const auto Weapon = GetWorld()->SpawnActor<ABaseWeapon>(WeaponClass);
	// If it successful, we attach it to our socket
	if (Weapon)
	{
		FAttachmentTransformRules AttachmentRules(EAttachmentRule::SnapToTarget, false);
		Weapon->AttachToComponent(GetMesh(), AttachmentRules, "WeaponSocket");
	}
}

void AFaromCharacter::TurnAtRate(float Rate)
{
	// calculate delta for this frame from the rate information
	AddControllerYawInput(Rate * BaseTurnRate * GetWorld()->GetDeltaSeconds());
}

void AFaromCharacter::LookUpAtRate(float Rate)
{
	// calculate delta for this frame from the rate information
	AddControllerPitchInput(Rate * BaseLookUpRate * GetWorld()->GetDeltaSeconds());
}

void AFaromCharacter::MoveForward(float Value)
{
	if ((Controller != nullptr) && (Value != 0.0f))
	{
		// find out which way is forward
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		// get forward vector
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
		AddMovementInput(Direction, Value);
	}
}

void AFaromCharacter::MoveRight(float Value)
{
	if ((Controller != nullptr) && (Value != 0.0f))
	{
		// find out which way is right
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		// get right vector 
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
		// add movement in that direction
		AddMovementInput(Direction, Value);
	}
}
