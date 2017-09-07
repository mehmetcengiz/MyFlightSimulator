// Fill out your copyright notice in the Description page of Project Settings.

#include "MyFlightSmilator.h"
#include "AirPlaneRudder.h"


// Sets default values for this component's properties
UAirPlaneRudder::UAirPlaneRudder()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UAirPlaneRudder::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UAirPlaneRudder::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if(bIsUsingRudder){
		UseRudder(RudderScale);
	}
}

void UAirPlaneRudder::SetRudderScale(float ScaleToSet){

	RudderScale = ScaleToSet;
}

void UAirPlaneRudder::SetIsUsingRudder(bool boolToSet){
	bIsUsingRudder = boolToSet;
}

void UAirPlaneRudder::UseRudder(float Scale){


	float RudderRotation = Scale * PlaneRudderTurningSpeed;
	FRotator RudderTurningSpeed(0, RudderRotation, 0);
	GetOwner()->AddActorLocalRotation(RudderTurningSpeed, true, nullptr, ETeleportType::None);

}

