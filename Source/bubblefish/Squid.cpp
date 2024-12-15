// Fill out your copyright notice in the Description page of Project Settings.

#include "Squid.h"
#include "Manta.h"

int sign(float value)
{
	if (value<0)
		return -1;
	else
		return 1;
}

// Sets default values
ASquid::ASquid(const FObjectInitializer& oi)
{
	PrimaryActorTick.bCanEverTick = true;
	heading = 1;
	health = 1.0f;
	radio_vision = oi.CreateDefaultSubobject<USphereComponent>(this, TEXT("sight"));
	radio_vision->SetupAttachment(RootComponent);
	radio_vision->SetSphereRadius(500);
}

// Called when the game starts or when spawned
void ASquid::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASquid::Tick(float delta)
{
	Super::Tick(delta);
	AManta* player = Cast<AManta>(UGameplayStatics::GetPlayerPawn(GetWorld(), 0));
	if (player == NULL)
		return;
	FVector vplayer = player->GetActorLocation() - GetActorLocation();
	float distancia = vplayer.Size();
	if (distancia <= radio_vision->GetScaledSphereRadius())
	{
		vplayer.Normalize();
		AddMovementInput(vplayer, 20*delta);
		FRotator heading = vplayer.Rotation();
		heading.Pitch = 0;
		RootComponent->SetWorldRotation(heading);
	}
}

// Called to bind functionality to input
void ASquid::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

void ASquid::moveForward(float delta)
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