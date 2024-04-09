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
}

void UTestWidget::UpdateReliabilityUI(bool IsReliable)
{
	const FText Reliability = IsReliable ? FText::FromString(TEXT("검출 정상")) : FText::FromString(TEXT("검출 비정상"));
	Txt_Reliability->SetText(Reliability);

	const FSlateColor FontColor = IsReliable ? FSlateColor(FColor::Green) : FSlateColor(FColor::Red);
	Txt_Reliability->SetColorAndOpacity(FontColor);
}
