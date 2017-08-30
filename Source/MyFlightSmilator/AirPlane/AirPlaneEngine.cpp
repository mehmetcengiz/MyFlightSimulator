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

	UE_LOG(LogTemp, Warning, TEXT("EngineLevel: %f"), EngineLevel);

}

void UAirPlaneEngine::ChangeEngineLevel(int EngineLevelToChange){
	UE_LOG(LogTemp, Warning, TEXT("Engine level incremented."));
	EngineLevel += EngineLevelToChange;
}

void UAirPlaneEngine::SetEngineLevel(int EngineLevelToSet){
	UE_LOG(LogTemp, Warning, TEXT("Engine level Set."));
	EngineLevel = EngineLevelToSet;
}



