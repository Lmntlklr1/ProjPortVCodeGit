// Fill out your copyright notice in the Description page of Project Settings.


#include "Examples/ExampleDefualtPawn.h"
#include "../../A__MichaelLebo.h"
#include "GameFramework/PlayerInput.h"
#include "GameFramework/Character.h"

// Sets default values
AExampleDefualtPawn::AExampleDefualtPawn() {
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}
// Called when the game starts or when spawned
void AExampleDefualtPawn::BeginPlay() {
	Super::BeginPlay();
	bool Test = false;
	UE_LOG(Game, Log, TEXT("This is the Bool value %s"), Test ? TEXT("TRUE") : TEXT("FALSE"));
	// Up Ccast
	AActor* Actor = this;

	// Down Cast
	APawn* Pawn = Cast<APawn>(Actor);
	if(Pawn) {
		//Valid
		UE_LOG(Game, Warning, TEXT("Actor is %s"), *Pawn->GetName());
	} else {
		//Valid
		UE_LOG(Game, Log, TEXT("Numbers are %d or %f"), 4, 7.3f);
	}
	UE_LOG(Game, Error, TEXT("Velocity is %s"), *GetVelocity().ToString());
}
// Called every frame
void AExampleDefualtPawn::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);

}
// Called to bind functionality to input
void AExampleDefualtPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) {
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	UPlayerInput::AddEngineDefinedActionMapping(FInputActionKeyMapping("Test_Spawn", EKeys::SpaceBar));

	PlayerInputComponent->BindAction("Test_Spawn", EInputEvent::IE_Pressed, this, &AExampleDefualtPawn::Spawn);
}
void AExampleDefualtPawn::Spawn() {
	GetWorld()->SpawnActor<APawn>(ClassType, GetActorTransform());
}
