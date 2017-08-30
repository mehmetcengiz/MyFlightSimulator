// Fill out your copyright notice in the Description page of Project Settings.

#include "MyFlightSmilator.h"
#include "DragForce.h"


// Sets default values for this component's properties
UDragForce::UDragForce(){
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

}


// Called when the game starts
void UDragForce::BeginPlay(){
	Super::BeginPlay();

}


// Called every frame
void UDragForce::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction){
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	
	auto PlaneSpeed = GetOwner()->GetVelocity();
	auto FrictionForce= FMath::Clamp<float>(PlaneSurfaceConstant * AirFrictionConstant * PlaneSpeed.X, 0, MaxAirFriction);
	auto ForceApplied = GetOwner()->GetActorForwardVector() * FrictionForce;

	auto DragLocation = GetComponentLocation();
	auto AirplaneRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());


	AirplaneRoot->AddForceAtLocation(-ForceApplied, DragLocation);
	UE_LOG(LogTemp, Warning, TEXT("Air Friction: %s"), *ForceApplied.ToString());

}
