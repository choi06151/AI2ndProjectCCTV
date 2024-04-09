// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "UISaveGame.generated.h"

/**
 * 
 */
UCLASS()
class AI2NDPROJECTCCTV_API UUISaveGame : public USaveGame
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly)
	TMap<FString, int32> ButtonClickCounts;
};
