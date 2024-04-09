// Fill out your copyright notice in the Description page of Project Settings.


#include "Both/CharacterAnimation.h"

void UCharacterAnimation::NativeUpdateAnimation(float DeltaSeconds) {
	Super::NativeUpdateAnimation(DeltaSeconds);

	APawn * Pawn = TryGetPawnOwner();
	if(nullptr != Pawn) {
		//Is Valid
		Velocity = Pawn->GetVelocity().Size();
	} else {
		//Is Not Valid
	}
}