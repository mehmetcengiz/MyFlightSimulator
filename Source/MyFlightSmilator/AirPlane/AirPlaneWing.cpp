// Fill out your copyright notice in the Description page of Project Settings.

#include "MyFlightSmilator.h"
#include "AirPlaneWing.h"


// Sets default values for this component's properties
UAirPlaneWing::UAirPlaneWing()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UAirPlaneWing::BeginPlay()
{
	Super::BeginPlay();

	if(bIsUsingWings){
		UseWings(WingsScale);
	}
	
}


// Called every frame
void UAirPlaneWing::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (bIsUsingWings) {
		UseWings(WingsScale);
	}
}

void UAirPlaneWing::UseWings(float Scale){

	float WingsRotation = Scale * PlaneWingTurningSpeed;
	FRotator RudderTurningSpeed(0, 0, WingsRotation);

	GetOwner()->AddActorLocalRotation(RudderTurningSpeed, true, nullptr, ETeleportType::None);
}

void UAirPlaneWing::SetWingsScale(float ScaleToSet) {

	WingsScale = ScaleToSet;
}

void UAirPlaneWing::SetIsUsingWings(bool boolToSet) {
	bIsUsingWings = boolToSet;
}