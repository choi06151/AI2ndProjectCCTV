// Fill out your copyright notice in the Description page of Project Settings.


#include "PKH/JsonParserLib.h"

FDetectionData UJsonParserLib::JsonParse(const FString& Data)
{
	FString JsonString;

	// Create Json Reader
	TSharedRef<TJsonReader<TCHAR>> JsonReader = TJsonReaderFactory<TCHAR>::Create(Data);
	// Create Json Object
	TSharedPtr<FJsonObject> JsonObj = MakeShareable(new FJsonObject());

	// Deserialize JsonGetObjectField
	if (FJsonSerializer::Deserialize(JsonReader, JsonObj))
	{
		FDetectionData DetectionData;

		DetectionData.Axe = JsonObj->HasField(TEXT("axe")) ? JsonObj->GetIntegerField(TEXT("axe")) : 0;
		DetectionData.BlueCap = JsonObj->HasField(TEXT("blue-cap")) ? JsonObj->GetIntegerField(TEXT("blue-cap")) : 0;
		DetectionData.CowboyHat = JsonObj->HasField(TEXT("cowboy-hat")) ? JsonObj->GetIntegerField(TEXT("cowboy-hat")) : 0;
		DetectionData.Dagger = JsonObj->HasField(TEXT("dagger")) ? JsonObj->GetIntegerField(TEXT("dagger")) : 0;
		DetectionData.GentleHat = JsonObj->HasField(TEXT("gentle-hat")) ? JsonObj->GetIntegerField(TEXT("gentle-hat")) : 0;
		DetectionData.GreatSword = JsonObj->HasField(TEXT("great-sword")) ? JsonObj->GetIntegerField(TEXT("great-sword")) : 0;
		DetectionData.Gun = JsonObj->HasField(TEXT("gun")) ? JsonObj->GetIntegerField(TEXT("gun")) : 0;
		DetectionData.LaserBlade = JsonObj->HasField(TEXT("laser-blade")) ? JsonObj->GetIntegerField(TEXT("laser-blade")) : 0;
		DetectionData.MarioHat = JsonObj->HasField(TEXT("mario-hat")) ? JsonObj->GetIntegerField(TEXT("mario-hat")) : 0;
		DetectionData.SantaHat = JsonObj->HasField(TEXT("santa-hat")) ? JsonObj->GetIntegerField(TEXT("santa-hat")) : 0;

		return DetectionData;
	}

	return FDetectionData();
}
