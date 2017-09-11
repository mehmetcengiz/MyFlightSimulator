// Fill out your copyright notice in the Description page of Project Settings.

#include "MyFlightSmilator.h"
#include "AirPlaneWing.h"
#include "AirPlaneEngine.h"


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

	AirPlaneEngine = GetOwner()->FindComponentByClass<UAirPlaneEngine>();
}


// Called every frame
void UAirPlaneWing::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	ApplyWingsLiftingForce();

	if (bIsUsingWingsToRotate) {
		ChangeRotationSpeed();
		UseWingsToRotate(WingsScaleForRotate);
	}else if(PlaneRotationSpeed > DefaultPlaneRotatingSpeed){
		FixRotationSpeed();
		UseWingsToRotate(WingsScaleForRotate);
	}

	if(bIsUsingWingsForDownMovement) {
		UseWingsToDown(WingsScaleForUpDownMovement);
	}else if(bIsUsingWingsForUpMovement) {
		UseWingsToUp(WingsScaleForUpDownMovement);
	}
}

void UAirPlaneWing::ChangeRotationSpeed(){
	PlaneRotationSpeed += 0.025f;
}

void UAirPlaneWing::FixRotationSpeed(){
		PlaneRotationSpeed -= 0.02f;
}

void UAirPlaneWing::ApplyWingsLiftingForce() {
	if (AirPlaneEngine == NULL) { return;}
	
	float Speed = AirPlaneEngine->GetPlaneSpeed();
	float LiftingForce = Speed > 120 ? Speed - 120 : 0;
	FVector DeltaForceOffset(0, 0, LiftingForce/10);

	GetOwner()->AddActorLocalOffset(DeltaForceOffset, true, nullptr, ETeleportType::None);
}

void UAirPlaneWing::UseWingsToRotate(float Scale){

	float WingsRotation = Scale * PlaneRotationSpeed;
	FRotator NewRotation = GetOwner()->GetActorRotation();
	NewRotation.Roll += WingsRotation;
	GetOwner()->SetActorRotation(NewRotation, ETeleportType::None);
}

void UAirPlaneWing::UseWingsToUp(float Scale) {

	float WingsRotation = Scale * PlaneUpDownSpeed;
	FRotator RudderTurningSpeed(WingsRotation, 0, 0);
	GetOwner()->AddActorLocalRotation(-RudderTurningSpeed, true, nullptr, ETeleportType::None);
}

void UAirPlaneWing::UseWingsToDown(float Scale) {

	float WingsRotation = Scale * PlaneUpDownSpeed;
	FRotator RudderTurningSpeed(WingsRotation, 0, 0);
	GetOwner()->AddActorLocalRotation(RudderTurningSpeed, true, nullptr, ETeleportType::None);
}




void UAirPlaneWing::SetWingsScaleForRotating(float ScaleToSet) {

	WingsScaleForRotate = ScaleToSet;
}

void UAirPlaneWing::SetIsUsingWingsForRotating(bool boolToSet) {
	bIsUsingWingsToRotate = boolToSet;
}

void UAirPlaneWing::SetWingsScaleForUpDownMovement(float ScaleToSet) {
	WingsScaleForUpDownMovement = ScaleToSet;
}

void UAirPlaneWing::SetIsUsingWingsForDownMovement(bool boolToSet) {
	bIsUsingWingsForDownMovement = boolToSet;
}

void UAirPlaneWing::SetIsUsingWingsForUpMovement(bool boolToSet) {
	bIsUsingWingsForUpMovement = boolToSet;
}
