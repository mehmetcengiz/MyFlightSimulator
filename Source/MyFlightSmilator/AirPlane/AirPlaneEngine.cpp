// Fill out your copyright notice in the Description page of Project Settings.

#include "MyFlightSmilator.h"
#include "AirPlaneEngine.h"


// Sets default values for this component's properties
UAirPlaneEngine::UAirPlaneEngine(){
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UAirPlaneEngine::BeginPlay(){
	Super::BeginPlay();
}


// Called every frame
void UAirPlaneEngine::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction){
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	PushThePlane();

}

void UAirPlaneEngine::SetThrottle(float Throttle){
	CurrentThrottle = FMath::Clamp<float>(CurrentThrottle + Throttle, 0, 1);
}

void UAirPlaneEngine::PushThePlane(){
	auto ForceApplied = GetOwner()->GetActorForwardVector() * CurrentThrottle * TrackMaxDrivingForce;
	auto EngineLocation = GetComponentLocation();
	auto AirplaneRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());
	
	UE_LOG(LogTemp, Warning, TEXT("Force: %s"), *ForceApplied.ToString());
	//UE_LOG(LogTemp, Warning, TEXT("EngineLocation: %s"), EngineLocation.ToString());
	//UE_LOG(LogTemp, Warning, TEXT("AirplaneRoot: %s"), *AirplaneRoot->GetName());
	AirplaneRoot->AddForceAtLocation(ForceApplied, EngineLocation);
}

