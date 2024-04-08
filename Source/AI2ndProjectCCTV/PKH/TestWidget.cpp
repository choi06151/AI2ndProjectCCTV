// Fill out your copyright notice in the Description page of Project Settings.


#include "PKH/TestWidget.h"

#include "Components/TextBlock.h"

void UTestWidget::UpdateDetectionUI(const FDetectionData& Data)
{
	FString Result = "";
	// Hat
	Result.Append(Data.BlueCap > 0 ? FString::Printf(TEXT("BlueCap : %d\n"), Data.BlueCap) : "");
	Result.Append(Data.CowboyHat > 0 ? FString::Printf(TEXT("CowboyHat : %d\n"), Data.CowboyHat) : "");
	Result.Append(Data.GentleHat > 0 ? FString::Printf(TEXT("GentleHat : %d\n"), Data.GentleHat) : "");
	Result.Append(Data.MarioHat > 0 ? FString::Printf(TEXT("MarioHat : %d\n"), Data.MarioHat) : "");
	Result.Append(Data.SantaHat > 0 ? FString::Printf(TEXT("SantaHat : %d\n"), Data.SantaHat) : "");

	// line spacing
	if(false == Result.IsEmpty())
	{
		Result.Append(TEXT("\n"));
	}

	// Weapon
	Result.Append(Data.Axe > 0 ? FString::Printf(TEXT("Axe : %d\n"), Data.Axe) : "");
	Result.Append(Data.Dagger > 0 ? FString::Printf(TEXT("Dagger : %d\n"), Data.Dagger) : "");
	Result.Append(Data.GreatSword > 0 ? FString::Printf(TEXT("GreatSword : %d\n"), Data.GreatSword) : "");
	Result.Append(Data.Gun > 0 ? FString::Printf(TEXT("Gun : %d\n"), Data.Gun) : "");
	Result.Append(Data.LaserBlade > 0 ? FString::Printf(TEXT("LaserBlade : %d\n"), Data.LaserBlade) : "");

	Txt_DetectionResult->SetText(FText::FromString(Result));

	//// Hat
	//Txt_BlueCap->SetText(FText::FromString(FString::Printf(TEXT("BlueCap : %d"), Data.BlueCap)));
	//Txt_CowboyHat->SetText(FText::FromString(FString::Printf(TEXT("CowboyHat : %d"), Data.CowboyHat)));
	//Txt_GentleHat->SetText(FText::FromString(FString::Printf(TEXT("GentleHat : %d"), Data.GentleHat)));
	//Txt_MarioHat->SetText(FText::FromString(FString::Printf(TEXT("MarioHat : %d"), Data.MarioHat)));
	//Txt_SantaHat->SetText(FText::FromString(FString::Printf(TEXT("SantaHat : %d"), Data.SantaHat)));

	//// Weapon
	//Txt_Axe->SetText(FText::FromString(FString::Printf(TEXT("Axe : %d"), Data.Axe)));
	//Txt_Dagger->SetText(FText::FromString(FString::Printf(TEXT("Dagger : %d"), Data.Dagger)));
	//Txt_GreatSword->SetText(FText::FromString(FString::Printf(TEXT("GreatSword : %d"), Data.GreatSword)));
	//Txt_Gun->SetText(FText::FromString(FString::Printf(TEXT("Gun : %d"), Data.Gun)));
	//Txt_LaserBlade->SetText(FText::FromString(FString::Printf(TEXT("LaserBlade : %d"), Data.LaserBlade)));
}
