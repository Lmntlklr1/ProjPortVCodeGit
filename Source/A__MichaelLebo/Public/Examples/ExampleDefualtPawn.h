// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "ExampleDefualtPawn.generated.h"

UCLASS()
class A__MICHAELLEBO_API AExampleDefualtPawn : public APawn {
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AExampleDefualtPawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = Default)
	TSubclassOf<class ACharacter> ClassType;
public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
private:
	void Spawn();
};
