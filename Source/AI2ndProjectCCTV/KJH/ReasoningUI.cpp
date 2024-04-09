// Fill out your copyright notice in the Description page of Project Settings.


#include "KJH/ReasoningUI.h"

#include "Components/Button.h"
#include "Components/TextBlock.h"
#include "Components/WidgetSwitcher.h"

const int SWITCHER_INDEX_COUNT = 0;
const int SWITCHER_INDEX_CHECK = 1;

void UReasoningUI::NativeConstruct()
{
	Super::NativeConstruct();

	Btn_Blue1->OnClicked.AddDynamic(this, &UReasoningUI::OnBtnBlue1Clicked);
	Btn_Blue2->OnClicked.AddDynamic(this, &UReasoningUI::OnBtnBlue2Clicked);
	Btn_Blue3->OnClicked.AddDynamic(this, &UReasoningUI::OnBtnBlue3Clicked);
	Btn_Blue4->OnClicked.AddDynamic(this, &UReasoningUI::OnBtnBlue4Clicked);
	Btn_Blue5->OnClicked.AddDynamic(this, &UReasoningUI::OnBtnBlue5Clicked);
	Btn_Cow1->OnClicked.AddDynamic(this, &UReasoningUI::OnBtnCow1Clicked);
	Btn_Cow2->OnClicked.AddDynamic(this, &UReasoningUI::OnBtnCow2Clicked);
	Btn_Cow3->OnClicked.AddDynamic(this, &UReasoningUI::OnBtnCow3Clicked);
	Btn_Cow4->OnClicked.AddDynamic(this, &UReasoningUI::OnBtnCow4Clicked);
	Btn_Cow5->OnClicked.AddDynamic(this, &UReasoningUI::OnBtnCow5Clicked);
	Btn_Gentle1->OnClicked.AddDynamic(this, &UReasoningUI::OnBtnGentle1Clicked);
	Btn_Gentle2->OnClicked.AddDynamic(this, &UReasoningUI::OnBtnGentle2Clicked);
	Btn_Gentle3->OnClicked.AddDynamic(this, &UReasoningUI::OnBtnGentle3Clicked);
	Btn_Gentle4->OnClicked.AddDynamic(this, &UReasoningUI::OnBtnGentle4Clicked);
	Btn_Gentle5->OnClicked.AddDynamic(this, &UReasoningUI::OnBtnGentle5Clicked);
	Btn_Mario1->OnClicked.AddDynamic(this, &UReasoningUI::OnBtnMario1Clicked);
	Btn_Mario2->OnClicked.AddDynamic(this, &UReasoningUI::OnBtnMario2Clicked);
	Btn_Mario3->OnClicked.AddDynamic(this, &UReasoningUI::OnBtnMario3Clicked);
	Btn_Mario4->OnClicked.AddDynamic(this, &UReasoningUI::OnBtnMario4Clicked);
	Btn_Mario5->OnClicked.AddDynamic(this, &UReasoningUI::OnBtnMario5Clicked);
	Btn_Santa1->OnClicked.AddDynamic(this, &UReasoningUI::OnBtnSanta1Clicked);
	Btn_Santa2->OnClicked.AddDynamic(this, &UReasoningUI::OnBtnSanta2Clicked);
	Btn_Santa3->OnClicked.AddDynamic(this, &UReasoningUI::OnBtnSanta3Clicked);
	Btn_Santa4->OnClicked.AddDynamic(this, &UReasoningUI::OnBtnSanta4Clicked);
	Btn_Santa5->OnClicked.AddDynamic(this, &UReasoningUI::OnBtnSanta5Clicked);

	Bnt_Check->OnClicked.AddDynamic(this, &UReasoningUI::OnMyCheck);
	Bnt_Count->OnClicked.AddDynamic(this, &UReasoningUI::OnMyCount);



	Blue1ClickCount = 0;
	Blue2ClickCount = 0;
	Blue3ClickCount = 0;
	Blue4ClickCount = 0;
	Blue5ClickCount = 0;
	Cow1ClickCount = 0;
	Cow2ClickCount = 0;
	Cow3ClickCount = 0;
	Cow4ClickCount = 0;
	Cow5ClickCount = 0;
	Gentle1ClickCount = 0;
	Gentle2ClickCount = 0;
	Gentle3ClickCount = 0;
	Gentle4ClickCount = 0;
	Gentle5ClickCount = 0;
	Mario1ClickCount = 0;
	Mario2ClickCount = 0;
	Mario3ClickCount = 0;
	Mario4ClickCount = 0;
	Mario5ClickCount = 0;
	Santa1ClickCount = 0;
	Santa2ClickCount = 0;
	Santa3ClickCount = 0;
	Santa4ClickCount = 0;
	Santa5ClickCount = 0;
}

void UReasoningUI::OnBtnBlue1Clicked()
{
	UpdateButtonTextAndState(Btn_Blue1, Txt_Blue1, Blue1ClickCount);
}

void UReasoningUI::OnBtnBlue2Clicked()
{
	UpdateButtonTextAndState(Btn_Blue2, Txt_Blue2, Blue2ClickCount);
}

void UReasoningUI::OnBtnBlue3Clicked()
{
	UpdateButtonTextAndState(Btn_Blue3, Txt_Blue3, Blue3ClickCount);
}

void UReasoningUI::OnBtnBlue4Clicked()
{
	UpdateButtonTextAndState(Btn_Blue4, Txt_Blue4, Blue4ClickCount);
}

void UReasoningUI::OnBtnBlue5Clicked()
{
	UpdateButtonTextAndState(Btn_Blue5, Txt_Blue5, Blue5ClickCount);
}

void UReasoningUI::OnBtnCow1Clicked()
{
	UpdateButtonTextAndState(Btn_Cow1, Txt_Cow1, Cow1ClickCount);
}

void UReasoningUI::OnBtnCow2Clicked()
{
	UpdateButtonTextAndState(Btn_Cow2, Txt_Cow2, Cow2ClickCount);
}

void UReasoningUI::OnBtnCow3Clicked()
{
	UpdateButtonTextAndState(Btn_Cow3, Txt_Cow3, Cow3ClickCount);
}

void UReasoningUI::OnBtnCow4Clicked()
{
	UpdateButtonTextAndState(Btn_Cow4, Txt_Cow4, Cow4ClickCount);
}

void UReasoningUI::OnBtnCow5Clicked()
{
	UpdateButtonTextAndState(Btn_Cow5, Txt_Cow5, Cow5ClickCount);
}

void UReasoningUI::OnBtnGentle1Clicked()
{
	UpdateButtonTextAndState(Btn_Gentle1, Txt_Gentle1, Gentle1ClickCount);
}

void UReasoningUI::OnBtnGentle2Clicked()
{
	UpdateButtonTextAndState(Btn_Gentle2, Txt_Gentle2, Gentle2ClickCount);
}

void UReasoningUI::OnBtnGentle3Clicked()
{
	UpdateButtonTextAndState(Btn_Gentle3, Txt_Gentle3, Gentle3ClickCount);
}

void UReasoningUI::OnBtnGentle4Clicked()
{
	UpdateButtonTextAndState(Btn_Gentle4, Txt_Gentle4, Gentle4ClickCount);
}

void UReasoningUI::OnBtnGentle5Clicked()
{
	UpdateButtonTextAndState(Btn_Gentle5, Txt_Gentle5, Gentle5ClickCount);
}

void UReasoningUI::OnBtnMario1Clicked()
{
	UpdateButtonTextAndState(Btn_Mario1, Txt_Mario1, Mario1ClickCount);
}

void UReasoningUI::OnBtnMario2Clicked()
{
	UpdateButtonTextAndState(Btn_Mario2, Txt_Mario2, Mario2ClickCount);
}

void UReasoningUI::OnBtnMario3Clicked()
{
	UpdateButtonTextAndState(Btn_Mario3, Txt_Mario3, Mario3ClickCount);
}

void UReasoningUI::OnBtnMario4Clicked()
{
	UpdateButtonTextAndState(Btn_Mario4, Txt_Mario4, Mario4ClickCount);
}

void UReasoningUI::OnBtnMario5Clicked()
{
	UpdateButtonTextAndState(Btn_Mario5, Txt_Mario5, Mario5ClickCount);
}

void UReasoningUI::OnBtnSanta1Clicked()
{
	UpdateButtonTextAndState(Btn_Santa1, Txt_Santa1, Santa1ClickCount);
}

void UReasoningUI::OnBtnSanta2Clicked()
{
	UpdateButtonTextAndState(Btn_Santa2, Txt_Santa2, Santa2ClickCount);
}

void UReasoningUI::OnBtnSanta3Clicked()
{
	UpdateButtonTextAndState(Btn_Santa3, Txt_Santa3, Santa3ClickCount);
}

void UReasoningUI::OnBtnSanta4Clicked()
{
	UpdateButtonTextAndState(Btn_Santa4, Txt_Santa4, Santa4ClickCount);
}

void UReasoningUI::OnBtnSanta5Clicked()
{
	UpdateButtonTextAndState(Btn_Santa5, Txt_Santa5, Santa5ClickCount);
}

void UReasoningUI::SwitchPanel(int32 index)
{
	WidgetSwitcherReasoning->SetActiveWidgetIndex(index);
}

void UReasoningUI::OnMyCheck()
{
	SwitchPanel(SWITCHER_INDEX_CHECK);
}

void UReasoningUI::OnMyCount()
{
	SwitchPanel(SWITCHER_INDEX_COUNT);
}

void UReasoningUI::UpdateButtonTextAndState(UButton* Button, UTextBlock* TextBlock, int32& ClickCount)
{
	ClickCount = (ClickCount + 1) % 4;

	switch (ClickCount)
	{
	case 0:
		TextBlock->SetText(FText::FromString(TEXT("")));
		break;
	case 1:
		TextBlock->SetText(FText::FromString(TEXT("X")));
		break;
	case 2:
		TextBlock->SetText(FText::FromString(TEXT("?")));
		break;
	case 3:
		TextBlock->SetText(FText::FromString(TEXT("O")));
		break;
	}
}

