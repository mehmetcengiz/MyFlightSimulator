// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Pawn.h"
#include "AirPlane.generated.h"

UCLASS()
class MYFLIGHTSMILATOR_API AAirPlane : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AAirPlane();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	
	
};
