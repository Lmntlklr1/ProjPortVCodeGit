// Fill out your copyright notice in the Description page of Project Settings.


#include "Examples/ExampleVariable.h"
#include "../../A__MichaelLebo.h"

// Sets default values
AExampleVariable::AExampleVariable() {
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;//this is just the same 
	PrimaryActorTick.bStartWithTickEnabled = false; // look at the can ever tick for priority
	ClassType = AExampleVariable::StaticClass();

	// Same thing as Bind in blueprint
	OnExampleDelegate.AddDynamic(this, &AExampleVariable::ExampleBoundFunction);
	OnExampleDelegate.AddDynamic(this, &AExampleVariable::ExampleBoundFunction2);
	
	ValueArray.Add(3);
	ValueArray.Add(4);

	PointerArray.Add(this);
	PointerArray.Add(nullptr);
}
// Called when the game starts or when spawned
void AExampleVariable::BeginPlay() {
	Super::BeginPlay();

	//Same thing as Call in blueprint
	OnExampleDelegate.Broadcast(this);
}
// Called every frame
void AExampleVariable::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);
}
void AExampleVariable::ExampleBoundFunction(AActor* OtherActor) {
	UE_LOG(Game, Error, TEXT("Function called by delegate"));
}
void AExampleVariable::ExampleBoundFunction2(AActor* OtherActor) {
	UE_LOG(Game, Error, TEXT("Another function called"));
}

