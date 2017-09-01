// Fill out your copyright notice in the Description page of Project Settings.

#include "MyFlightSmilator.h"
#include "AirFriction.h"


// Sets default values for this component's properties
UAirFriction::UAirFriction() {
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UAirFriction::BeginPlay() {
	Super::BeginPlay();

	ApplyFriction();

}


// Called every frame
void UAirFriction::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) {
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	ApplyFriction();

}

void UAirFriction::ApplyFriction() {

	auto Velocity = 200;

	auto forceApplied = GetOwner()->GetActorForwardVector() * Velocity * 9000;
	auto forceLocation = GetOwner()->GetActorLocation();
	auto tankRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());
	tankRoot->AddForceAtLocation(-forceApplied, forceLocation);
}
