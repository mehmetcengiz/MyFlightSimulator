// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Pawn.h"
#include "AirPlane.generated.h"


class UPlaneEngine;
class UAirPlaneEngine;

UCLASS()

class MYFLIGHTSMILATOR_API AAirPlane : public APawn {
	GENERATED_BODY()
public:
	// Sets default values for this pawn's properties
	AAirPlane();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly, Category = "PlaneSetup")
	float MaxPlaneSpeed;
	UPROPERTY(EditDefaultsOnly, Category = "PlaneSetup")
	float MinPlaneSpeed;
	UPROPERTY(EditDefaultsOnly, Category = "PlaneSetup")
	int32 EngineLevelMax = 3;
	UPROPERTY(EditDefaultsOnly, Category = "PlaneSetup")
	int32 EngineLevelMin = 1;



public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION(BlueprintCallable, Category = "Plane Control")
	void SetEngineLevelToMax();

	UFUNCTION(BlueprintCallable, Category = "Plane Control")
	void IncreaseEngineLevel();

	UFUNCTION(BlueprintCallable, Category = "Plane Control")
	void DecreaseEngineLevel();

	UFUNCTION(BlueprintCallable, Category = "Plane Control")
	void SetEngineLevelToMin();

	UFUNCTION(BlueprintCallable, Category = "Setup")
	void SetAirPlaneEngine(UAirPlaneEngine* AirPlaneEngineToSet);


private:
	UAirPlaneEngine* AirPlaneEngine = nullptr;

};
