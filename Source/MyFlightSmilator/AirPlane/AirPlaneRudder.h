// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/ActorComponent.h"
#include "AirPlaneRudder.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class MYFLIGHTSMILATOR_API UAirPlaneRudder : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UAirPlaneRudder();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly, Category = "Plane Setup")
	float PlaneRudderTurningSpeed = 0.1f;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	void SetRudderScale(float Scale);
	
	void SetIsUsingRudder(bool boolToSet);
	
private:
	bool bIsUsingRudder = false;
	float RudderScale = 0;

	void UseRudder(float Scale);

};
