// Fill out your copyright notice in the Description page of Project Settings.

#include "MyFlightSmilator.h"
#include "PlaneEngine.h"


// Sets default values for this component's properties
UPlaneEngine::UPlaneEngine()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UPlaneEngine::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UPlaneEngine::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UPlaneEngine::ChangeEngineLevel(int32 EngineLevelToChange) {
	EngineLevel += EngineLevelToChange;
}

void UPlaneEngine::SetEngineLevel(int32 EngineLevelToSet) {
	EngineLevel = EngineLevelToSet;
}