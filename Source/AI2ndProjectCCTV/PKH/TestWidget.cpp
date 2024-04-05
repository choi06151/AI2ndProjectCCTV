// Fill out your copyright notice in the Description page of Project Settings.


#include "PKH/TestWidget.h"

#include "Components/TextBlock.h"

void UTestWidget::UpdateDetectionUI(const FDetectionData& Data)
{
	// Hat
	Txt_BlueCap->SetText(FText::FromString(FString::Printf(TEXT("BlueCap : %d"), Data.BlueCap)));
	Txt_CowboyHat->SetText(FText::FromString(FString::Printf(TEXT("CowboyHat : %d"), Data.CowboyHat)));
	Txt_GentleHat->SetText(FText::FromString(FString::Printf(TEXT("GentleHat : %d"), Data.GentleHat)));
	Txt_MarioHat->SetText(FText::FromString(FString::Printf(TEXT("MarioHat : %d"), Data.MarioHat)));
	Txt_SantaHat->SetText(FText::FromString(FString::Printf(TEXT("SantaHat : %d"), Data.SantaHat)));

	// Weapon
	Txt_Axe->SetText(FText::FromString(FString::Printf(TEXT("Axe : %d"), Data.Axe)));
	Txt_Dagger->SetText(FText::FromString(FString::Printf(TEXT("Dagger : %d"), Data.Dagger)));
	Txt_GreatSword->SetText(FText::FromString(FString::Printf(TEXT("GreatSword : %d"), Data.GreatSword)));
	Txt_Gun->SetText(FText::FromString(FString::Printf(TEXT("Gun : %d"), Data.Gun)));
	Txt_LaserBlade->SetText(FText::FromString(FString::Printf(TEXT("LaserBlade : %d"), Data.LaserBlade)));
}
