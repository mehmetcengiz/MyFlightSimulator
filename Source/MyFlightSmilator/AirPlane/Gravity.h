// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/ActorComponent.h"
#include "Gravity.generated.h"

class UAirPlaneEngine;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class MYFLIGHTSMILATOR_API UGravity : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UGravity();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly, Category = "AirPlane")
	float MinSpeedToFly = 135.0f;
	UPROPERTY(EditDefaultsOnly, Category = "AirPlane")
	float MaxGravity = 20.0f;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	void ApplyGravity();

private:
	UAirPlaneEngine* AirPlaneEngine = nullptr;
	
};
