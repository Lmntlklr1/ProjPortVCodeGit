// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Actors/BaseCharacter.h"

#include "BasePlayer.generated.h"

class USpringArmComponent;
/**
 *
 */
UCLASS()
class A__MICHAELLEBO_API ABasePlayer : public ABaseCharacter {
	GENERATED_BODY()
public:
	ABasePlayer();
protected:
	class USpringArmComponent* SpringArm;

	void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
private:
	void InputAxisMoveForward(float AxisValue);
};
