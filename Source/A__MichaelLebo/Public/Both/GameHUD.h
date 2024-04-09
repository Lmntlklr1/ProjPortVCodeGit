// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "GameHUD.generated.h"

/**
 *
 */
UCLASS()
class A__MICHAELLEBO_API UGameHUD : public UUserWidget {
	GENERATED_BODY()
protected:
	UPROPERTY(BlueprintReadOnly, meta=(BindWidget))
	class UProgressBar* HealthBar;
};
