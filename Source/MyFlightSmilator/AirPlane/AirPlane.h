// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Pawn.h"
#include "AirPlane.generated.h"


class UAirPlaneEngine;
class UAirPlaneRudder;
class UAirPlaneWing;

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
	float MinPlaneSpeedToFly = 120;
	
	UPROPERTY(EditDefaultsOnly, Category = "PlaneSetup")
	int EngineLevelMax = 3;
	UPROPERTY(EditDefaultsOnly, Category = "PlaneSetup")
	int EngineLevelMin = 0;
	UPROPERTY(EditDefaultsOnly, Category = "PlaneSetup")
	float RudderMaxTurning = 0.2;
	UPROPERTY(EditDefaultsOnly, Category = "PlaneSetup")
	float WingsMaxUpDownMovement = 0.2;

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
	UFUNCTION(BlueprintCallable, Category = "Controls")
	void UseWingsToRotate(bool bIsUsingWings,float Scale);
	UFUNCTION(BlueprintCallable, Category = "Controls")
	void SetIsBreaking(bool BreakingToSet);
	UFUNCTION(BlueprintCallable, Category = "Controls")
	void UseWingsForUpMovement(bool IsWingsUpToSet);
	UFUNCTION(BlueprintCallable, Category = "Controls")
	void UseWingsForDownMovement(bool IsWingsDownToSet);


public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
private:
	UAirPlaneEngine* AirPlaneEngine = nullptr;
	UAirPlaneRudder* AirPlaneRudder = nullptr;
	UAirPlaneWing* AirPlaneWing = nullptr;

	bool bIsMoving = false;
	

};
