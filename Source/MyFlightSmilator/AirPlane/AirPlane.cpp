// Fill out your copyright notice in the Description page of Project Settings.

#include "MyFlightSmilator.h"
#include "AirPlane.h"
#include "AirPlaneEngine.h"


// Sets default values
AAirPlane::AAirPlane(){
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AAirPlane::BeginPlay(){
	Super::BeginPlay();
	AirPlaneEngine = FindComponentByClass<UAirPlaneEngine>();
}

// Called every frame
void AAirPlane::Tick(float DeltaTime){
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void AAirPlane::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent){
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}


void AAirPlane::SetEngineLevelMax() {
	if (AirPlaneEngine == NULL) { return; }
	AirPlaneEngine->SetEngineLevel(EngineLevelMax);
}

void AAirPlane::SetEngineLevelMin(){
	if (AirPlaneEngine == NULL) { return; }
	AirPlaneEngine->SetEngineLevel(EngineLevelMin);
}

void AAirPlane::IncreaseEngineLevel(){
	if (AirPlaneEngine == NULL) { return; }
	AirPlaneEngine->ChangeEngineLevel(1);
}

void AAirPlane::DecreaseEngineLevel(){
	if (AirPlaneEngine == NULL) { return; }
	AirPlaneEngine->ChangeEngineLevel(-1);
}
