// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "HttpTestActor.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "JsonParserLib.generated.h"

/**
 * 
 */
UCLASS()
class AI2NDPROJECTCCTV_API UJsonParserLib : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	static FDetectionData JsonParse(const FString& Data);
};
