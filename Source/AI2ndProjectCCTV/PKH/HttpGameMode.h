// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "HttpTestActor.h"
#include "GameFramework/GameModeBase.h"
#include "HttpGameMode.generated.h"

/**
 * 
 */
UCLASS()
class AI2NDPROJECTCCTV_API AHttpGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	AHttpGameMode();

protected:
	virtual void BeginPlay() override;

// Http Actor
protected:
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<class AHttpTestActor> HttpActorClass;

	UPROPERTY(EditDefaultsOnly)
	TObjectPtr<class AHttpTestActor> HttpActor;
	

// ΐ₯ Ελ½Ε
protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	FDetectionData CurDetectionData;

public:
	UFUNCTION(BlueprintCallable)
	void Detect();

	UFUNCTION(BlueprintCallable)
	void UpdateDetectionData(FDetectionData ResultData);

	UFUNCTION(BlueprintImplementableEvent)
	void UpdateReliabilityData();

	FORCEINLINE FDetectionData GetDetectionData() const { return CurDetectionData; }

// UI
protected:
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<class UTestWidget> TestUIClass;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	TObjectPtr<class UTestWidget> TestUI;
};
