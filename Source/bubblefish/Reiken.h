// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Camera/CameraComponent.h"
#include "Reiken.generated.h"

int sign(float value);

UCLASS()
class BUBBLEFISH_API AReiken : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AReiken(const FObjectInitializer& oi);

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
	class UCameraComponent* camera;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
	class USpringArmComponent* cameraBoom;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Character)
	float health;

	int heading;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void moveForward(float delta);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	
	
};
