// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ExampleVariable.generated.h"

//Decalre Delegate Type
// make known our required function signature
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FVaraibleDelegate, AActor*, OtherActor);

UCLASS(Abstract)
class A__MICHAELLEBO_API AExampleVariable : public AActor {
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AExampleVariable();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	//Read Only
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Variable|ReadOnly")
	bool VisibleAnywhere;
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "Variable|ReadOnly")
	uint8 VisibleDefaultsOnly;
	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category = "Variable|ReadOnly")
	int32 VisibleInstanceOnlyOdd;
	UPROPERTY(VisibleInstanceOnly, Category = "Variable|ReadOnly")
	int64 VisibleInstanceOnly;

	// Read Write
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Variable|ReadWrite")
	float EditAnywhere;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Variable|ReadWrite")
	FName EditDefaultsOnlyOdd;
	UPROPERTY(EditInstanceOnly, BlueprintReadWrite, Category = "Variable|ReadWrite")
	FString EditInstanceOnlyOdd;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Variable|ReadWrite")
	FText EditDefaultsOnly;
	UPROPERTY(EditInstanceOnly, Category = "Variable|ReadWrite")
	FVector EditInstanceOnly;

	//Class Reference
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Variable|ClassReference")
	TSubclassOf<AActor> ClassType;

	// Create Delegate / Event Dispatcher varaible
	UPROPERTY(BlueprintAssignable, BlueprintCallable, Category = Varaible)
	FVaraibleDelegate OnExampleDelegate;

	//Array
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Variable|Array")
	TArray<int32> ValueArray;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Variable|Array")
	TArray<UObject *> PointerArray;
public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
private:
	UFUNCTION()
	void ExampleBoundFunction(AActor* OtherActor);
	UFUNCTION()
	void ExampleBoundFunction2(AActor* OtherActor);
};
