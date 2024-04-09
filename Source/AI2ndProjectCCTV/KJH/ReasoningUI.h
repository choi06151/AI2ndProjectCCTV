// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "ReasoningUI.generated.h"

/**
 * 
 */
UCLASS()
class AI2NDPROJECTCCTV_API UReasoningUI : public UUserWidget
{
	GENERATED_BODY()

protected:
	virtual void NativeConstruct() override;

public:
	UPROPERTY(EditDefaultsOnly, meta = (BindWidget))
	class UButton* Btn_Blue1;

	UPROPERTY(EditDefaultsOnly, meta = (BindWidget))
	class UButton* Btn_Blue2;

	UPROPERTY(EditDefaultsOnly, meta = (BindWidget))
	class UButton* Btn_Blue3;

	UPROPERTY(EditDefaultsOnly, meta = (BindWidget))
	class UButton* Btn_Blue4;

	UPROPERTY(EditDefaultsOnly, meta = (BindWidget))
	class UButton* Btn_Blue5;

	UPROPERTY(EditDefaultsOnly, meta = (BindWidget))
	class UButton* Btn_Cow1;

	UPROPERTY(EditDefaultsOnly, meta = (BindWidget))
	class UButton* Btn_Cow2;

	UPROPERTY(EditDefaultsOnly, meta = (BindWidget))
	class UButton* Btn_Cow3;

	UPROPERTY(EditDefaultsOnly, meta = (BindWidget))
	class UButton* Btn_Cow4;

	UPROPERTY(EditDefaultsOnly, meta = (BindWidget))
	class UButton* Btn_Cow5;

	UPROPERTY(EditDefaultsOnly, meta = (BindWidget))
	class UButton* Btn_Gentle1;

	UPROPERTY(EditDefaultsOnly, meta = (BindWidget))
	class UButton* Btn_Gentle2;

	UPROPERTY(EditDefaultsOnly, meta = (BindWidget))
	class UButton* Btn_Gentle3;

	UPROPERTY(EditDefaultsOnly, meta = (BindWidget))
	class UButton* Btn_Gentle4;

	UPROPERTY(EditDefaultsOnly, meta = (BindWidget))
	class UButton* Btn_Gentle5;

	UPROPERTY(EditDefaultsOnly, meta = (BindWidget))
	class UButton* Btn_Mario1;

	UPROPERTY(EditDefaultsOnly, meta = (BindWidget))
	class UButton* Btn_Mario2;

	UPROPERTY(EditDefaultsOnly, meta = (BindWidget))
	class UButton* Btn_Mario3;

	UPROPERTY(EditDefaultsOnly, meta = (BindWidget))
	class UButton* Btn_Mario4;

	UPROPERTY(EditDefaultsOnly, meta = (BindWidget))
	class UButton* Btn_Mario5;

	UPROPERTY(EditDefaultsOnly, meta = (BindWidget))
	class UButton* Btn_Santa1;

	UPROPERTY(EditDefaultsOnly, meta = (BindWidget))
	class UButton* Btn_Santa2;

	UPROPERTY(EditDefaultsOnly, meta = (BindWidget))
	class UButton* Btn_Santa3;

	UPROPERTY(EditDefaultsOnly, meta = (BindWidget))
	class UButton* Btn_Santa4;

	UPROPERTY(EditDefaultsOnly, meta = (BindWidget))
	class UButton* Btn_Santa5;


	UPROPERTY(EditDefaultsOnly, meta = (BindWidget))
	class UTextBlock* Txt_Blue1;

	UPROPERTY(EditDefaultsOnly, meta = (BindWidget))
	class UTextBlock* Txt_Blue2;

	UPROPERTY(EditDefaultsOnly, meta = (BindWidget))
	class UTextBlock* Txt_Blue3;

	UPROPERTY(EditDefaultsOnly, meta = (BindWidget))
	class UTextBlock* Txt_Blue4;

	UPROPERTY(EditDefaultsOnly, meta = (BindWidget))
	class UTextBlock* Txt_Blue5;

	UPROPERTY(EditDefaultsOnly, meta = (BindWidget))
	class UTextBlock* Txt_Cow1;

	UPROPERTY(EditDefaultsOnly, meta = (BindWidget))
	class UTextBlock* Txt_Cow2;

	UPROPERTY(EditDefaultsOnly, meta = (BindWidget))
	class UTextBlock* Txt_Cow3;

	UPROPERTY(EditDefaultsOnly, meta = (BindWidget))
	class UTextBlock* Txt_Cow4;

	UPROPERTY(EditDefaultsOnly, meta = (BindWidget))
	class UTextBlock* Txt_Cow5;

	UPROPERTY(EditDefaultsOnly, meta = (BindWidget))
	class UTextBlock* Txt_Gentle1;

	UPROPERTY(EditDefaultsOnly, meta = (BindWidget))
	class UTextBlock* Txt_Gentle2;

	UPROPERTY(EditDefaultsOnly, meta = (BindWidget))
	class UTextBlock* Txt_Gentle3;

	UPROPERTY(EditDefaultsOnly, meta = (BindWidget))
	class UTextBlock* Txt_Gentle4;

	UPROPERTY(EditDefaultsOnly, meta = (BindWidget))
	class UTextBlock* Txt_Gentle5;

	UPROPERTY(EditDefaultsOnly, meta = (BindWidget))
	class UTextBlock* Txt_Mario1;

	UPROPERTY(EditDefaultsOnly, meta = (BindWidget))
	class UTextBlock* Txt_Mario2;

	UPROPERTY(EditDefaultsOnly, meta = (BindWidget))
	class UTextBlock* Txt_Mario3;

	UPROPERTY(EditDefaultsOnly, meta = (BindWidget))
	class UTextBlock* Txt_Mario4;

	UPROPERTY(EditDefaultsOnly, meta = (BindWidget))
	class UTextBlock* Txt_Mario5;

	UPROPERTY(EditDefaultsOnly, meta = (BindWidget))
	class UTextBlock* Txt_Santa1;

	UPROPERTY(EditDefaultsOnly, meta = (BindWidget))
	class UTextBlock* Txt_Santa2;

	UPROPERTY(EditDefaultsOnly, meta = (BindWidget))
	class UTextBlock* Txt_Santa3;

	UPROPERTY(EditDefaultsOnly, meta = (BindWidget))
	class UTextBlock* Txt_Santa4;

	UPROPERTY(EditDefaultsOnly, meta = (BindWidget))
	class UTextBlock* Txt_Santa5;

	int32 Blue1ClickCount;
	int32 Blue2ClickCount;
	int32 Blue3ClickCount;
	int32 Blue4ClickCount;
	int32 Blue5ClickCount;
	int32 Cow1ClickCount;
	int32 Cow2ClickCount;
	int32 Cow3ClickCount;
	int32 Cow4ClickCount;
	int32 Cow5ClickCount;
	int32 Gentle1ClickCount;
	int32 Gentle2ClickCount;
	int32 Gentle3ClickCount;
	int32 Gentle4ClickCount;
	int32 Gentle5ClickCount;
	int32 Mario1ClickCount;
	int32 Mario2ClickCount;
	int32 Mario3ClickCount;
	int32 Mario4ClickCount;
	int32 Mario5ClickCount;
	int32 Santa1ClickCount;
	int32 Santa2ClickCount;
	int32 Santa3ClickCount;
	int32 Santa4ClickCount;
	int32 Santa5ClickCount;
	

	UFUNCTION()
	void OnBtnBlue1Clicked();
	UFUNCTION()
	void OnBtnBlue2Clicked();
	UFUNCTION()
	void OnBtnBlue3Clicked();
	UFUNCTION()
	void OnBtnBlue4Clicked();
	UFUNCTION()
	void OnBtnBlue5Clicked();
	UFUNCTION()
	void OnBtnCow1Clicked();
	UFUNCTION()
	void OnBtnCow2Clicked();
	UFUNCTION()
	void OnBtnCow3Clicked();
	UFUNCTION()
	void OnBtnCow4Clicked();
	UFUNCTION()
	void OnBtnCow5Clicked();
	UFUNCTION()
	void OnBtnGentle1Clicked();
	UFUNCTION()
	void OnBtnGentle2Clicked();
	UFUNCTION()
	void OnBtnGentle3Clicked();
	UFUNCTION()
	void OnBtnGentle4Clicked();
	UFUNCTION()
	void OnBtnGentle5Clicked();
	UFUNCTION()
	void OnBtnMario1Clicked();
	UFUNCTION()
	void OnBtnMario2Clicked();
	UFUNCTION()
	void OnBtnMario3Clicked();
	UFUNCTION()
	void OnBtnMario4Clicked();
	UFUNCTION()
	void OnBtnMario5Clicked();
	UFUNCTION()
	void OnBtnSanta1Clicked();
	UFUNCTION()
	void OnBtnSanta2Clicked();
	UFUNCTION()
	void OnBtnSanta3Clicked();
	UFUNCTION()
	void OnBtnSanta4Clicked();
	UFUNCTION()
	void OnBtnSanta5Clicked();

	UPROPERTY(EditDefaultsOnly, meta = (BindWidget))
	class UWidgetSwitcher* WidgetSwitcherReasoning;
	
	UPROPERTY(EditDefaultsOnly, meta = (BindWidget))
	class UButton* Bnt_Check;

	UPROPERTY(EditDefaultsOnly, meta = (BindWidget))
	class UButton* Bnt_Count;

	void SwitchPanel(int32 index);

	UFUNCTION()
	void OnMyCheck();

	UFUNCTION()
	void OnMyCount();

	void SaveButtonClickCounts();
	void LoadButtonClickCounts();
private:
	void UpdateButtonTextAndState(UButton* Button, UTextBlock* TextBlock, int32& ClickCount);
};
