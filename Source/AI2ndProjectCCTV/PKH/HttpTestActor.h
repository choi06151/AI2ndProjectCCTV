// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Interfaces/IHttpRequest.h"
#include "HttpTestActor.generated.h"

USTRUCT()
struct FDetectionData
{
	GENERATED_BODY()

	uint8 Axe;
	uint8 BlueCap;
	uint8 CowboyHat;
	uint8 Dagger;
	uint8 GentleHat;
	uint8 GreatSword;
	uint8 Gun;
	uint8 LaserBlade;
	uint8 MarioHat;
	uint8 SantaHat;
};

UCLASS()
class AI2NDPROJECTCCTV_API AHttpTestActor : public AActor
{
	GENERATED_BODY()
	
public:	
	AHttpTestActor();

protected:
	virtual void BeginPlay() override;

// Request & Response
public:
	void SendImage(const FString& URL);
	void SendImageComplete(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bConnectedSuccessfully);

	void ReqTextData(const FString& URL);
	void ResTextData(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bConnectedSuccessfully);

// UI
protected:
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<class UTestWidget> TestUIClass;

	UPROPERTY(EditDefaultsOnly)
	TObjectPtr<class UTestWidget> TestUI;
};
