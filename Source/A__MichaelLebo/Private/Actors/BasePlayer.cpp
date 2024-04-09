// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/BasePlayer.h"
#include "GameFramework/SpringArmComponent.h"

ABasePlayer::ABasePlayer() {
	GetMesh()->SetRelativeRotation(FRotator(0.f, -90.f, 0.f));

	//Set the spring arm
	SpringArm = CreateDefaultSubobject<USpringArmComponent>("SpringArm");
	SpringArm->SetRelativeLocation(FVector(0.f, 0.f, 60.f));
	SpringArm->SetupAttachment(GetRootComponent()/*, only need this part if we attach to a socket */);
}
void ABasePlayer::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) {
	//Don't forget
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	//Turning
	PlayerInputComponent->BindAxis("TurnRight", this, &ABasePlayer::AddControllerYawInput);

	//Movement
	PlayerInputComponent->BindAxis("moveForward", this, &ABasePlayer::InputAxisMoveForward);
}

void ABasePlayer::InputAxisMoveForward(float AxisValue) {
	AddMovementInput(FRotator(0.f, GetControlRotation().Yaw, 0.f).Vector(), AxisValue);
}
