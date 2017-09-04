// Fill out your copyright notice in the Description page of Project Settings.

#include "MyFlightSmilator.h"
#include "Gravity.h"
#include "AirPlaneEngine.h"

// Sets default values for this component's properties
UGravity::UGravity()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UGravity::BeginPlay(){
	Super::BeginPlay();
	AirPlaneEngine = GetOwner()->FindComponentByClass<UAirPlaneEngine>();
}


// Called every frame
void UGravity::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	ApplyGravity();
}

void UGravity::ApplyGravity(){

	if (AirPlaneEngine == NULL) { return; }
	auto Speed = AirPlaneEngine->GetPlaneSpeed();

	float GravityZ = Speed < MinSpeedToFly ? MinSpeedToFly - Speed : 0;
	GravityZ = GravityZ > MaxGravity ? MaxGravity : GravityZ;

	UE_LOG(LogTemp, Warning, TEXT("Gravity: %f"), GravityZ);

	FVector Gravity(0, 0, -GravityZ);
	GetOwner()->AddActorWorldOffset(Gravity, true, nullptr, ETeleportType::None);
}

