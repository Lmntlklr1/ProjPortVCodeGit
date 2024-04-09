// Fill out your copyright notice in the Description page of Project Settings.


#include "Examples/ExampleFunctions.h"
#include "../../A__MichaelLebo.h"

// Sets default values
AExampleFunctions::AExampleFunctions() {
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}
// Called when the game starts or when spawned
void AExampleFunctions::BeginPlay() {
	Super::BeginPlay();
	UE_LOG(Game, Error, TEXT("In BEGIN PLAY"));
	BlueprintNativeEvent_Implementation();
	UE_LOG(Game, Error, TEXT("After first call"));
	BlueprintNativeEvent();
}
// Called every frame
void AExampleFunctions::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);
}
void AExampleFunctions::BlueprintCallable() {
	UE_LOG(Game, Error, TEXT("BlueprintCallable in C++"));
}
//void AExampleFunctions::BlueprintImplementableEvent() {
//	UE_LOG(Game, Log, TEXT("BlueprintImplementableEvent in C++"));
//}
void AExampleFunctions::BlueprintNativeEvent_Implementation() {
	UE_LOG(Game, Warning, TEXT("BlueprintNativeEvent in C++"));
}
float AExampleFunctions::PureFunction() const {
	return 3.14f;
}