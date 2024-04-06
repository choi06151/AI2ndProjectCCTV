// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Interfaces/IHttpRequest.h"
#include "HttpTestActor.generated.h"

USTRUCT(BlueprintType)
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

// Component
protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TObjectPtr<class USceneCaptureComponent2D> CaptureComp;

// Request & Response6
protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	FString UploadURL = TEXT("http://127.0.0.1:8000/upload_base64");

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	FString GetURL = TEXT("http://127.0.0.1:8000/get_base64");

public:
	UFUNCTION(BlueprintCallable)
	void SendImage();
	void SendImageComplete(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bConnectedSuccessfully);

	void ReqTextData();
	void ResTextData(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bConnectedSuccessfully);

protected:
	UPROPERTY(EditDefaultsOnly)
	TObjectPtr<class AHttpGameMode> GameMode;

// Texture
protected:
	UPROPERTY(EditDefaultsOnly)
	TObjectPtr<class UTextureRenderTarget2D> RenderTarget;

};
