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
	// Hat
	UPROPERTY(EditDefaultsOnly, meta =(BindWidget))
	TObjectPtr<class UTextBlock> Txt_BlueCap;

	UPROPERTY(EditDefaultsOnly, meta = (BindWidget))
	TObjectPtr<class UTextBlock> Txt_CowboyHat;

	UPROPERTY(EditDefaultsOnly, meta = (BindWidget))
	TObjectPtr<class UTextBlock> Txt_GentleHat;

	UPROPERTY(EditDefaultsOnly, meta = (BindWidget))
	TObjectPtr<class UTextBlock> Txt_MarioHat;

	UPROPERTY(EditDefaultsOnly, meta = (BindWidget))
	TObjectPtr<class UTextBlock> Txt_SantaHat;

	// Weapon
	UPROPERTY(EditDefaultsOnly, meta = (BindWidget))
	TObjectPtr<class UTextBlock> Txt_Axe;

	UPROPERTY(EditDefaultsOnly, meta = (BindWidget))
	TObjectPtr<class UTextBlock> Txt_Dagger;

	UPROPERTY(EditDefaultsOnly, meta = (BindWidget))
	TObjectPtr<class UTextBlock> Txt_GreatSword;

	UPROPERTY(EditDefaultsOnly, meta = (BindWidget))
	TObjectPtr<class UTextBlock> Txt_Gun;

	UPROPERTY(EditDefaultsOnly, meta = (BindWidget))
	TObjectPtr<class UTextBlock> Txt_LaserBlade;

public:
	void UpdateDetectionUI(const FDetectionData& Data);
};
