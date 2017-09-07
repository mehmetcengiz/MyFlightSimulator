// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/StaticMeshComponent.h"
#include "AirplaneGear.generated.h"

/**
 * 
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class MYFLIGHTSMILATOR_API UAirplaneGear : public UActorComponent
{
	GENERATED_BODY()


public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UAirplaneGear();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Gear")
	void ToggleGear();

	void SetGear(UStaticMeshComponent* WheelFront, UStaticMeshComponent* WheelBack, 
		UStaticMeshComponent* GearFront, UStaticMeshComponent* GearBack, 
		UStaticMeshComponent* GearBoxFront, UStaticMeshComponent* GearBoxBack, UStaticMeshComponent* Hydraolic);

private:
	bool bIsGearUp = false;
	
	UStaticMeshComponent* WheelFront;
	UStaticMeshComponent* WheelBack;
	UStaticMeshComponent* GearFront;
	UStaticMeshComponent* GearBack; 
	UStaticMeshComponent* GearBoxFront;
	UStaticMeshComponent* GearBoxBack;
	UStaticMeshComponent* Hydraolic;

};

