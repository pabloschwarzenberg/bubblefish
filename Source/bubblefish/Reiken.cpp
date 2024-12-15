// Fill out your copyright notice in the Description page of Project Settings.

#include "Reiken.h"


// Sets default values
AReiken::AReiken(const FObjectInitializer& oi)
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	cameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	cameraBoom->SetupAttachment(RootComponent);
	cameraBoom->SetAbsolute(false,true);

	camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	camera->SetupAttachment(cameraBoom, USpringArmComponent::SocketName);
	camera->bUsePawnControlRotation = false;

	heading = 1;
	health = 1.0f;
}

// Called when the game starts or when spawned
void AReiken::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AReiken::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AReiken::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	if (PlayerInputComponent)
	{
		PlayerInputComponent->BindAxis("forward", this, &AReiken::moveForward);
		PlayerInputComponent->BindAxis("backward", this, &AReiken::moveForward);
	}
}

void AReiken::moveForward(float delta)
{
	if (Controller && delta)
	{
		FRotator a = GetActorRotation();
		FRotator r(0, 0, 0);
		if (sign(delta) != sign(heading))
		{
			heading = sign(delta);
			if (heading < 0)
				r.Yaw = 180;
			else
				r.Yaw = 0;
			this->SetActorRotation(r);
		}
		FVector fwd = GetActorForwardVector();
		AddMovementInput(fwd, fabs(delta));
	}
}