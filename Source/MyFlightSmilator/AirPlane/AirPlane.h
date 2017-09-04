// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Pawn.h"
#include "AirPlane.generated.h"


class UAirPlaneEngine;
class UAirPlaneRudder;

UCLASS()

class MYFLIGHTSMILATOR_API AAirPlane : public APawn {
	GENERATED_BODY()
public:
	// Sets default values for this pawn's properties
	AAirPlane();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	void SetIsMovingBySpeed();

	UPROPERTY(EditDefaultsOnly, Category = "PlaneSetup")
	float MaxPlaneSpeed;
	UPROPERTY(EditDefaultsOnly, Category = "PlaneSetup")
	float MinPlaneSpeed;
	
	UPROPERTY(EditDefaultsOnly, Category = "PlaneSetup")
	int EngineLevelMax = 3;
	UPROPERTY(EditDefaultsOnly, Category = "PlaneSetup")
	int EngineLevelMin = 1;
	UPROPERTY(EditDefaultsOnly, Category = "PlaneSetup")
	float RudderMaxTurning = 0.2;

	UFUNCTION(BlueprintCallable, Category = "Engine")
	void SetEngineLevelMax();
	UFUNCTION(BlueprintCallable, Category = "Engine")
	void SetEngineLevelMin();
	UFUNCTION(BlueprintCallable, Category = "Engine")
	void IncreaseEngineLevel();
	UFUNCTION(BlueprintCallable, Category = "Engine")
	void DecreaseEngineLevel();

	UFUNCTION(BlueprintCallable, Category = "Controls")
	void UseRudder(bool bIsUsingRudder,float Scale);


public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:
	UAirPlaneEngine* AirPlaneEngine = nullptr;
	UAirPlaneRudder* AirPlaneRudder = nullptr;

	bool bIsMoving = false;
	bool bIsOnAir = false;

};
