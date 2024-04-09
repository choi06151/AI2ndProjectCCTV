// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "HttpTestActor.h"
#include "Blueprint/UserWidget.h"
#include "TestWidget.generated.h"

/**
 * 
 */
UCLASS()
class AI2NDPROJECTCCTV_API UTestWidget : public UUserWidget
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, meta =(BindWidget))
	TObjectPtr<class UTextBlock> Txt_DetectionResult;

	UPROPERTY(EditDefaultsOnly, meta = (BindWidget))
	TObjectPtr<class UTextBlock> Txt_Reliability;

public:
	UFUNCTION(BlueprintCallable)
	void UpdateDetectionUI(const FDetectionData& Data);

	UFUNCTION(BlueprintCallable)
	void UpdateReliabilityUI(bool IsReliable);
};
