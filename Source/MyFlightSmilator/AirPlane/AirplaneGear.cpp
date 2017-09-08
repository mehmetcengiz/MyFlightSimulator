// Fill out your copyright notice in the Description page of Project Settings.

#include "MyFlightSmilator.h"
#include "AirplaneGear.h"



// Sets default values for this component's properties
UAirplaneGear::UAirplaneGear()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UAirplaneGear::BeginPlay()
{
	Super::BeginPlay();

	// ...

}


// Called every frame
void UAirplaneGear::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

}


void UAirplaneGear::ToggleGear() {
	if(bIsGearUp) {
		//GearDown
		bIsGearUp = true;
	}else {
		//GearUp
		bIsGearUp = false;
	}
}

void UAirplaneGear::SetGear(UStaticMeshComponent* WheelFrontToSet, UStaticMeshComponent* WheelBackToSet,
	UStaticMeshComponent* GearFrontToSet, UStaticMeshComponent* GearBackToSet, UStaticMeshComponent* GearBoxFrontToSet,
	UStaticMeshComponent* GearBoxBackToSet, UStaticMeshComponent* HydraolicToSet) {
	
	WheelFront = WheelFrontToSet;
	WheelBack = WheelBackToSet;
	GearFront = GearFrontToSet;
	GearBack = GearBackToSet;
	GearBoxFront = GearBoxFrontToSet;
	GearBoxBack = GearBoxBackToSet;
	Hydraolic = HydraolicToSet;

}

void UAirplaneGear::GearUp() {
	
}
