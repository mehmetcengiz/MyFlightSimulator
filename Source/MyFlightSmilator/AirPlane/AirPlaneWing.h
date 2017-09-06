// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/ActorComponent.h"
#include "AirPlaneWing.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class MYFLIGHTSMILATOR_API UAirPlaneWing : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UAirPlaneWing();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly, Category = "Plane Setup")
	float PlaneRotatingSpeed = 0.2f;
	float PlaneUpDownSpeed = 0.4f;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;



	void SetWingsScaleForRotating(float ScaleToSet);
	void SetIsUsingWingsForRotating(bool boolToSet);

	void SetWingsScaleForUpDownMovement(float ScaleToSet);
	void SetIsUsingWingsForDownMovement(bool boolToSet);
	void SetIsUsingWingsForUpMovement(bool boolToSet);


private:

	bool bIsUsingWingsToRotate = false;
	float WingsScaleForRotate = 0;

	float WingsScaleForUpDownMovement = 0;
	bool bIsUsingWingsForUpMovement = false;
	bool bIsUsingWingsForDownMovement = false;


	void UseWingsToRotate(float Scale);
	void UseWingsToUp(float Scale);
	void UseWingsToDown(float Scale);
	
};
