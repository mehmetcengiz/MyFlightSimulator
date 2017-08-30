// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/SceneComponent.h"
#include "DragForce.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class MYFLIGHTSMILATOR_API UDragForce : public USceneComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UDragForce();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly, Category = "AirPlane Setup")
	float PlaneSurfaceConstant = 50000;

	UPROPERTY(EditDefaultsOnly, Category = "AirPlane Setup")
	float AirFrictionConstant = 1;
	UPROPERTY(EditDefaultsOnly, Category = "AirPlane Setup")
	float MaxAirFriction = 500000;

	

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	
	
};
