// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/SceneComponent.h"
#include "AirPlaneEngine.generated.h"

class AAirPlane;

class UFloatingPawnMovement;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class MYFLIGHTSMILATOR_API UAirPlaneEngine : public USceneComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UAirPlaneEngine();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	int EngineLevel = 0;

	UPROPERTY(EditDefaultsOnly,Category="Engine")
	float TrackMaxDrivingForce = 100000;

	UPROPERTY(EditDefaultsOnly, Category = "Engine")
	float EnginePower = 70;


public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	
	void ChangeEngineLevel(int EngineLevelToChange);

	void SetEngineLevel(int EngineLevelToSet);

	void PushPlane();

	float GetPlaneSpeed();
	
	void SetIsBreaking(bool BreakingToSet);
private:

	float Speed = 0;
	float MaxSpeed = 0;

	bool bIsBreaking = false;

};
