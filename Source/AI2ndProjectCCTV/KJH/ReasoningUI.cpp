// Fill out your copyright notice in the Description page of Project Settings.


#include "KJH/ReasoningUI.h"

#include "Components/Button.h"
#include "Components/TextBlock.h"
#include "Components/WidgetSwitcher.h"
#include "Kismet/GameplayStatics.h"
#include "Public/KJH/UISaveGame.h"

const int SWITCHER_INDEX_COUNT = 0;
const int SWITCHER_INDEX_CHECK = 1;

void UReasoningUI::NativeConstruct()
{
	Super::NativeConstruct();

	//ResetButtonClickCounts();
	//SaveButtonClickCounts();
	LoadButtonClickCounts();

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

	Btn_AllBlue->OnClicked.AddDynamic(this, &UReasoningUI::OnBtnAllBlueClicked);
	Btn_AllCow->OnClicked.AddDynamic(this, &UReasoningUI::OnBtnAllCowClicked);
	Btn_AllGentle->OnClicked.AddDynamic(this, &UReasoningUI::OnBtnAllGentleClicked);
	Btn_AllMario->OnClicked.AddDynamic(this, &UReasoningUI::OnBtnAllMarioClicked);
	Btn_AllSanta->OnClicked.AddDynamic(this, &UReasoningUI::OnBtnAllSantaClicked);
	Btn_AllAxe->OnClicked.AddDynamic(this, &UReasoningUI::OnBtnAllAxeClicked);
	Btn_AllBlade->OnClicked.AddDynamic(this, &UReasoningUI::OnBtnAllBladeClicked);
	Btn_AllDagger->OnClicked.AddDynamic(this, &UReasoningUI::OnBtnAllDaggerClicked);
	Btn_AllGreat->OnClicked.AddDynamic(this, &UReasoningUI::OnBtnAllGreatClicked);
	Btn_AllGun->OnClicked.AddDynamic(this, &UReasoningUI::OnBtnAllGunClicked);


	//Blue1ClickCount = 0;
	//Blue2ClickCount = 0;
	//Blue3ClickCount = 0;
	//Blue4ClickCount = 0;
	//Blue5ClickCount = 0;
	//Cow1ClickCount = 0;
	//Cow2ClickCount = 0;
	//Cow3ClickCount = 0;
	//Cow4ClickCount = 0;
	//Cow5ClickCount = 0;
	//Gentle1ClickCount = 0;
	//Gentle2ClickCount = 0;
	//Gentle3ClickCount = 0;
	//Gentle4ClickCount = 0;
	//Gentle5ClickCount = 0;
	//Mario1ClickCount = 0;
	//Mario2ClickCount = 0;
	//Mario3ClickCount = 0;
	//Mario4ClickCount = 0;
	//Mario5ClickCount = 0;
	//Santa1ClickCount = 0;
	//Santa2ClickCount = 0;
	//Santa3ClickCount = 0;
	//Santa4ClickCount = 0;
	//Santa5ClickCount = 0;
}

void UReasoningUI::OnBtnBlue1Clicked()
{
	UpdateButtonTextAndState(Btn_Blue1, Txt_Blue1, Blue1ClickCount);
	SaveButtonClickCounts();
}

void UReasoningUI::OnBtnBlue2Clicked()
{
	UpdateButtonTextAndState(Btn_Blue2, Txt_Blue2, Blue2ClickCount);
	SaveButtonClickCounts();
}

void UReasoningUI::OnBtnBlue3Clicked()
{
	UpdateButtonTextAndState(Btn_Blue3, Txt_Blue3, Blue3ClickCount);
	SaveButtonClickCounts();
}

void UReasoningUI::OnBtnBlue4Clicked()
{
	UpdateButtonTextAndState(Btn_Blue4, Txt_Blue4, Blue4ClickCount);
	SaveButtonClickCounts();
}

void UReasoningUI::OnBtnBlue5Clicked()
{
	UpdateButtonTextAndState(Btn_Blue5, Txt_Blue5, Blue5ClickCount);
	SaveButtonClickCounts();
}

void UReasoningUI::OnBtnCow1Clicked()
{
	UpdateButtonTextAndState(Btn_Cow1, Txt_Cow1, Cow1ClickCount);
	SaveButtonClickCounts();
}

void UReasoningUI::OnBtnCow2Clicked()
{
	UpdateButtonTextAndState(Btn_Cow2, Txt_Cow2, Cow2ClickCount);
	SaveButtonClickCounts();
}

void UReasoningUI::OnBtnCow3Clicked()
{
	UpdateButtonTextAndState(Btn_Cow3, Txt_Cow3, Cow3ClickCount);
	SaveButtonClickCounts();
}

void UReasoningUI::OnBtnCow4Clicked()
{
	UpdateButtonTextAndState(Btn_Cow4, Txt_Cow4, Cow4ClickCount);
	SaveButtonClickCounts();
}

void UReasoningUI::OnBtnCow5Clicked()
{
	UpdateButtonTextAndState(Btn_Cow5, Txt_Cow5, Cow5ClickCount);
	SaveButtonClickCounts();
}

void UReasoningUI::OnBtnGentle1Clicked()
{
	UpdateButtonTextAndState(Btn_Gentle1, Txt_Gentle1, Gentle1ClickCount);
	SaveButtonClickCounts();
}

void UReasoningUI::OnBtnGentle2Clicked()
{
	UpdateButtonTextAndState(Btn_Gentle2, Txt_Gentle2, Gentle2ClickCount);
	SaveButtonClickCounts();
}

void UReasoningUI::OnBtnGentle3Clicked()
{
	UpdateButtonTextAndState(Btn_Gentle3, Txt_Gentle3, Gentle3ClickCount);
	SaveButtonClickCounts();
}

void UReasoningUI::OnBtnGentle4Clicked()
{
	UpdateButtonTextAndState(Btn_Gentle4, Txt_Gentle4, Gentle4ClickCount);
	SaveButtonClickCounts();
}

void UReasoningUI::OnBtnGentle5Clicked()
{
	UpdateButtonTextAndState(Btn_Gentle5, Txt_Gentle5, Gentle5ClickCount);
	SaveButtonClickCounts();
}

void UReasoningUI::OnBtnMario1Clicked()
{
	UpdateButtonTextAndState(Btn_Mario1, Txt_Mario1, Mario1ClickCount);
	SaveButtonClickCounts();
}

void UReasoningUI::OnBtnMario2Clicked()
{
	UpdateButtonTextAndState(Btn_Mario2, Txt_Mario2, Mario2ClickCount);
	SaveButtonClickCounts();
}

void UReasoningUI::OnBtnMario3Clicked()
{
	UpdateButtonTextAndState(Btn_Mario3, Txt_Mario3, Mario3ClickCount);
	SaveButtonClickCounts();
}

void UReasoningUI::OnBtnMario4Clicked()
{
	UpdateButtonTextAndState(Btn_Mario4, Txt_Mario4, Mario4ClickCount);
	SaveButtonClickCounts();
}

void UReasoningUI::OnBtnMario5Clicked()
{
	UpdateButtonTextAndState(Btn_Mario5, Txt_Mario5, Mario5ClickCount);
	SaveButtonClickCounts();
}

void UReasoningUI::OnBtnSanta1Clicked()
{
	UpdateButtonTextAndState(Btn_Santa1, Txt_Santa1, Santa1ClickCount);
	SaveButtonClickCounts();
}

void UReasoningUI::OnBtnSanta2Clicked()
{
	UpdateButtonTextAndState(Btn_Santa2, Txt_Santa2, Santa2ClickCount);
	SaveButtonClickCounts();
}

void UReasoningUI::OnBtnSanta3Clicked()
{
	UpdateButtonTextAndState(Btn_Santa3, Txt_Santa3, Santa3ClickCount);
	SaveButtonClickCounts();
}

void UReasoningUI::OnBtnSanta4Clicked()
{
	UpdateButtonTextAndState(Btn_Santa4, Txt_Santa4, Santa4ClickCount);
	SaveButtonClickCounts();
}

void UReasoningUI::OnBtnSanta5Clicked()
{
	UpdateButtonTextAndState(Btn_Santa5, Txt_Santa5, Santa5ClickCount);
	SaveButtonClickCounts();
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

void UReasoningUI::SaveButtonClickCounts()
{
	UUISaveGame* SaveGameInstance = Cast<UUISaveGame>(UGameplayStatics::CreateSaveGameObject(UUISaveGame::StaticClass()));

	SaveGameInstance->ButtonClickCounts.Add("Btn_Blue1", Blue1ClickCount);
	SaveGameInstance->ButtonClickCounts.Add("Btn_Blue2", Blue2ClickCount);
	SaveGameInstance->ButtonClickCounts.Add("Btn_Blue3", Blue3ClickCount);
	SaveGameInstance->ButtonClickCounts.Add("Btn_Blue4", Blue4ClickCount);
	SaveGameInstance->ButtonClickCounts.Add("Btn_Blue5", Blue5ClickCount);
	SaveGameInstance->ButtonClickCounts.Add("Btn_Cow1", Cow1ClickCount);
	SaveGameInstance->ButtonClickCounts.Add("Btn_Cow2", Cow2ClickCount);
	SaveGameInstance->ButtonClickCounts.Add("Btn_Cow3", Cow3ClickCount);
	SaveGameInstance->ButtonClickCounts.Add("Btn_Cow4", Cow4ClickCount);
	SaveGameInstance->ButtonClickCounts.Add("Btn_Cow5", Cow5ClickCount);
	SaveGameInstance->ButtonClickCounts.Add("Btn_Gentle1", Gentle1ClickCount);
	SaveGameInstance->ButtonClickCounts.Add("Btn_Gentle2", Gentle2ClickCount);
	SaveGameInstance->ButtonClickCounts.Add("Btn_Gentle3", Gentle3ClickCount);
	SaveGameInstance->ButtonClickCounts.Add("Btn_Gentle4", Gentle4ClickCount);
	SaveGameInstance->ButtonClickCounts.Add("Btn_Gentle5", Gentle5ClickCount);
	SaveGameInstance->ButtonClickCounts.Add("Btn_Mario1", Mario1ClickCount);
	SaveGameInstance->ButtonClickCounts.Add("Btn_Mario2", Mario2ClickCount);
	SaveGameInstance->ButtonClickCounts.Add("Btn_Mario3", Mario3ClickCount);
	SaveGameInstance->ButtonClickCounts.Add("Btn_Mario4", Mario4ClickCount);
	SaveGameInstance->ButtonClickCounts.Add("Btn_Mario5", Mario5ClickCount);
	SaveGameInstance->ButtonClickCounts.Add("Btn_Santa1", Santa1ClickCount);
	SaveGameInstance->ButtonClickCounts.Add("Btn_Santa2", Santa2ClickCount);
	SaveGameInstance->ButtonClickCounts.Add("Btn_Santa3", Santa3ClickCount);
	SaveGameInstance->ButtonClickCounts.Add("Btn_Santa4", Santa4ClickCount);
	SaveGameInstance->ButtonClickCounts.Add("Btn_Santa5", Santa5ClickCount);

	UGameplayStatics::SaveGameToSlot(SaveGameInstance, "MySaveSlot", 0);
}

void UReasoningUI::LoadButtonClickCounts()
{
	if (UGameplayStatics::DoesSaveGameExist("MySaveSlot", 0))
	{
		UUISaveGame* LoadGameInstance = Cast<UUISaveGame>(UGameplayStatics::LoadGameFromSlot("MySaveSlot", 0));
		// SaveGame 객체에서 버튼 클릭 카운트를 불러옴
		Blue1ClickCount = LoadGameInstance->ButtonClickCounts["Btn_Blue1"];
		Blue2ClickCount = LoadGameInstance->ButtonClickCounts["Btn_Blue2"];
		Blue3ClickCount = LoadGameInstance->ButtonClickCounts["Btn_Blue3"];
		Blue4ClickCount = LoadGameInstance->ButtonClickCounts["Btn_Blue4"];
		Blue5ClickCount = LoadGameInstance->ButtonClickCounts["Btn_Blue5"];
		Cow1ClickCount = LoadGameInstance->ButtonClickCounts["Btn_Cow1"];
		Cow2ClickCount = LoadGameInstance->ButtonClickCounts["Btn_Cow2"];
		Cow3ClickCount = LoadGameInstance->ButtonClickCounts["Btn_Cow3"];
		Cow4ClickCount = LoadGameInstance->ButtonClickCounts["Btn_Cow4"];
		Cow5ClickCount = LoadGameInstance->ButtonClickCounts["Btn_Cow5"];
		Gentle1ClickCount = LoadGameInstance->ButtonClickCounts["Btn_Gentle1"];
		Gentle2ClickCount = LoadGameInstance->ButtonClickCounts["Btn_Gentle2"];
		Gentle3ClickCount = LoadGameInstance->ButtonClickCounts["Btn_Gentle3"];
		Gentle4ClickCount = LoadGameInstance->ButtonClickCounts["Btn_Gentle4"];
		Gentle5ClickCount = LoadGameInstance->ButtonClickCounts["Btn_Gentle5"];
		Mario1ClickCount = LoadGameInstance->ButtonClickCounts["Btn_Mario1"];
		Mario2ClickCount = LoadGameInstance->ButtonClickCounts["Btn_Mario2"];
		Mario3ClickCount = LoadGameInstance->ButtonClickCounts["Btn_Mario3"];
		Mario4ClickCount = LoadGameInstance->ButtonClickCounts["Btn_Mario4"];
		Mario5ClickCount = LoadGameInstance->ButtonClickCounts["Btn_Mario5"];
		Santa1ClickCount = LoadGameInstance->ButtonClickCounts["Btn_Santa1"];
		Santa2ClickCount = LoadGameInstance->ButtonClickCounts["Btn_Santa2"];
		Santa3ClickCount = LoadGameInstance->ButtonClickCounts["Btn_Santa3"];
		Santa4ClickCount = LoadGameInstance->ButtonClickCounts["Btn_Santa4"];
		Santa5ClickCount = LoadGameInstance->ButtonClickCounts["Btn_Santa5"];
	}

	UpdateButtonText(Txt_Blue1, Blue1ClickCount);
	UpdateButtonText(Txt_Blue2, Blue2ClickCount);
	UpdateButtonText(Txt_Blue3, Blue3ClickCount);
	UpdateButtonText(Txt_Blue4, Blue4ClickCount);
	UpdateButtonText(Txt_Blue5, Blue5ClickCount);
	UpdateButtonText(Txt_Cow1, Cow1ClickCount);
	UpdateButtonText(Txt_Cow2, Cow2ClickCount);
	UpdateButtonText(Txt_Cow3, Cow3ClickCount);
	UpdateButtonText(Txt_Cow4, Cow4ClickCount);
	UpdateButtonText(Txt_Cow5, Cow5ClickCount);
	UpdateButtonText(Txt_Gentle1, Gentle1ClickCount);
	UpdateButtonText(Txt_Gentle2, Gentle2ClickCount);
	UpdateButtonText(Txt_Gentle3, Gentle3ClickCount);
	UpdateButtonText(Txt_Gentle4, Gentle4ClickCount);
	UpdateButtonText(Txt_Gentle5, Gentle5ClickCount);
	UpdateButtonText(Txt_Mario1, Mario1ClickCount);
	UpdateButtonText(Txt_Mario2, Mario2ClickCount);
	UpdateButtonText(Txt_Mario3, Mario3ClickCount);
	UpdateButtonText(Txt_Mario4, Mario4ClickCount);
	UpdateButtonText(Txt_Mario5, Mario5ClickCount);
	UpdateButtonText(Txt_Santa1, Santa1ClickCount);
	UpdateButtonText(Txt_Santa2, Santa2ClickCount);
	UpdateButtonText(Txt_Santa3, Santa3ClickCount);
	UpdateButtonText(Txt_Santa4, Santa4ClickCount);
	UpdateButtonText(Txt_Santa5, Santa5ClickCount);
}

void UReasoningUI::UpdateButtonText(UTextBlock* TextBlock, int32 ClickCount)
{
	switch (ClickCount % 4)
	{
	case 0: TextBlock->SetText(FText::FromString(TEXT(""))); break;
	case 1: TextBlock->SetText(FText::FromString(TEXT("X"))); break;
	case 2: TextBlock->SetText(FText::FromString(TEXT("?"))); break;
	case 3: TextBlock->SetText(FText::FromString(TEXT("O"))); break;
	}
}

void UReasoningUI::ResetButtonClickCounts()
{
	
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

	// UI 업데이트
	UpdateButtonText(Txt_Blue1, Blue1ClickCount);
	UpdateButtonText(Txt_Blue2, Blue2ClickCount);
	UpdateButtonText(Txt_Blue3, Blue3ClickCount);
	UpdateButtonText(Txt_Blue4, Blue4ClickCount);
	UpdateButtonText(Txt_Blue5, Blue5ClickCount);
	UpdateButtonText(Txt_Cow1, Cow1ClickCount);
	UpdateButtonText(Txt_Cow2, Cow2ClickCount);
	UpdateButtonText(Txt_Cow3, Cow3ClickCount);
	UpdateButtonText(Txt_Cow4, Cow4ClickCount);
	UpdateButtonText(Txt_Cow5, Cow5ClickCount);
	UpdateButtonText(Txt_Gentle1, Gentle1ClickCount);
	UpdateButtonText(Txt_Gentle2, Gentle2ClickCount);
	UpdateButtonText(Txt_Gentle3, Gentle3ClickCount);
	UpdateButtonText(Txt_Gentle4, Gentle4ClickCount);
	UpdateButtonText(Txt_Gentle5, Gentle5ClickCount);
	UpdateButtonText(Txt_Mario1, Mario1ClickCount);
	UpdateButtonText(Txt_Mario2, Mario2ClickCount);
	UpdateButtonText(Txt_Mario3, Mario3ClickCount);
	UpdateButtonText(Txt_Mario4, Mario4ClickCount);
	UpdateButtonText(Txt_Mario5, Mario5ClickCount);
	UpdateButtonText(Txt_Santa1, Santa1ClickCount);
	UpdateButtonText(Txt_Santa2, Santa2ClickCount);
	UpdateButtonText(Txt_Santa3, Santa3ClickCount);
	UpdateButtonText(Txt_Santa4, Santa4ClickCount);
	UpdateButtonText(Txt_Santa5, Santa5ClickCount);

}

void UReasoningUI::OnBtnAllBlueClicked()
{
	UpdateButtonTextAndState(Btn_Blue1, Txt_Blue1, Blue1ClickCount);
	UpdateButtonTextAndState(Btn_Blue2, Txt_Blue2, Blue2ClickCount);
	UpdateButtonTextAndState(Btn_Blue3, Txt_Blue3, Blue3ClickCount);
	UpdateButtonTextAndState(Btn_Blue4, Txt_Blue4, Blue4ClickCount);
	UpdateButtonTextAndState(Btn_Blue5, Txt_Blue5, Blue5ClickCount);
	SaveButtonClickCounts();
}

void UReasoningUI::OnBtnAllCowClicked()
{
	UpdateButtonTextAndState(Btn_Cow1, Txt_Cow1, Cow1ClickCount);
	UpdateButtonTextAndState(Btn_Cow2, Txt_Cow2, Cow2ClickCount);
	UpdateButtonTextAndState(Btn_Cow3, Txt_Cow3, Cow3ClickCount);
	UpdateButtonTextAndState(Btn_Cow4, Txt_Cow4, Cow4ClickCount);
	UpdateButtonTextAndState(Btn_Cow5, Txt_Cow5, Cow5ClickCount);
	SaveButtonClickCounts();
}

void UReasoningUI::OnBtnAllGentleClicked()
{
	UpdateButtonTextAndState(Btn_Gentle1, Txt_Gentle1, Gentle1ClickCount);
	UpdateButtonTextAndState(Btn_Gentle2, Txt_Gentle2, Gentle2ClickCount);
	UpdateButtonTextAndState(Btn_Gentle3, Txt_Gentle3, Gentle3ClickCount);
	UpdateButtonTextAndState(Btn_Gentle4, Txt_Gentle4, Gentle4ClickCount);
	UpdateButtonTextAndState(Btn_Gentle5, Txt_Gentle5, Gentle5ClickCount);
	SaveButtonClickCounts();
}

void UReasoningUI::OnBtnAllMarioClicked()
{
	UpdateButtonTextAndState(Btn_Mario1, Txt_Mario1, Mario1ClickCount);
	UpdateButtonTextAndState(Btn_Mario2, Txt_Mario2, Mario2ClickCount);
	UpdateButtonTextAndState(Btn_Mario3, Txt_Mario3, Mario3ClickCount);
	UpdateButtonTextAndState(Btn_Mario4, Txt_Mario4, Mario4ClickCount);
	UpdateButtonTextAndState(Btn_Mario5, Txt_Mario5, Mario5ClickCount);
	SaveButtonClickCounts();
}

void UReasoningUI::OnBtnAllSantaClicked()
{
	UpdateButtonTextAndState(Btn_Santa1, Txt_Santa1, Santa1ClickCount);
	UpdateButtonTextAndState(Btn_Santa2, Txt_Santa2, Santa2ClickCount);
	UpdateButtonTextAndState(Btn_Santa3, Txt_Santa3, Santa3ClickCount);
	UpdateButtonTextAndState(Btn_Santa4, Txt_Santa4, Santa4ClickCount);
	UpdateButtonTextAndState(Btn_Santa5, Txt_Santa5, Santa5ClickCount);
	SaveButtonClickCounts();
}

void UReasoningUI::OnBtnAllAxeClicked()
{
	UpdateButtonTextAndState(Btn_Blue1, Txt_Blue1, Blue1ClickCount);
	UpdateButtonTextAndState(Btn_Cow1, Txt_Cow1, Cow1ClickCount);
	UpdateButtonTextAndState(Btn_Gentle1, Txt_Gentle1, Gentle1ClickCount);
	UpdateButtonTextAndState(Btn_Mario1, Txt_Mario1, Mario1ClickCount);
	UpdateButtonTextAndState(Btn_Santa1, Txt_Santa1, Santa1ClickCount);
	SaveButtonClickCounts();
}

void UReasoningUI::OnBtnAllBladeClicked()
{
	UpdateButtonTextAndState(Btn_Blue2, Txt_Blue2, Blue2ClickCount);
	UpdateButtonTextAndState(Btn_Cow2, Txt_Cow2, Cow2ClickCount);
	UpdateButtonTextAndState(Btn_Gentle2, Txt_Gentle2, Gentle2ClickCount);
	UpdateButtonTextAndState(Btn_Mario2, Txt_Mario2, Mario2ClickCount);
	UpdateButtonTextAndState(Btn_Santa2, Txt_Santa2, Santa2ClickCount);
	SaveButtonClickCounts();
}

void UReasoningUI::OnBtnAllDaggerClicked()
{
	UpdateButtonTextAndState(Btn_Blue3, Txt_Blue3, Blue3ClickCount);
	UpdateButtonTextAndState(Btn_Cow3, Txt_Cow3, Cow3ClickCount);
	UpdateButtonTextAndState(Btn_Gentle3, Txt_Gentle3, Gentle3ClickCount);
	UpdateButtonTextAndState(Btn_Mario3, Txt_Mario3, Mario3ClickCount);
	UpdateButtonTextAndState(Btn_Santa3, Txt_Santa3, Santa3ClickCount);
	SaveButtonClickCounts();
}

void UReasoningUI::OnBtnAllGreatClicked()
{
	UpdateButtonTextAndState(Btn_Blue4, Txt_Blue4, Blue4ClickCount);
	UpdateButtonTextAndState(Btn_Cow4, Txt_Cow4, Cow4ClickCount);
	UpdateButtonTextAndState(Btn_Gentle4, Txt_Gentle4, Gentle4ClickCount);
	UpdateButtonTextAndState(Btn_Mario4, Txt_Mario4, Mario4ClickCount);
	UpdateButtonTextAndState(Btn_Santa4, Txt_Santa4, Santa4ClickCount);
	SaveButtonClickCounts();
}

void UReasoningUI::OnBtnAllGunClicked()
{
	UpdateButtonTextAndState(Btn_Blue5, Txt_Blue5, Blue5ClickCount);
	UpdateButtonTextAndState(Btn_Cow5, Txt_Cow5, Cow5ClickCount);
	UpdateButtonTextAndState(Btn_Gentle5, Txt_Gentle5, Gentle5ClickCount);
	UpdateButtonTextAndState(Btn_Mario5, Txt_Mario5, Mario5ClickCount);
	UpdateButtonTextAndState(Btn_Santa5, Txt_Santa5, Santa5ClickCount);
	SaveButtonClickCounts();
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

