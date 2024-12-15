// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "bubblefish.h"
#include "Squid.generated.h"

UCLASS()
class BUBBLEFISH_API ASquid : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ASquid(const FObjectInitializer& oi);

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Collision)
	USphereComponent* radio_vision;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Character)
	float health;

	int heading;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void moveForward(float delta);

public:	
	// Called every frame
	virtual void Tick(float delta) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
};
