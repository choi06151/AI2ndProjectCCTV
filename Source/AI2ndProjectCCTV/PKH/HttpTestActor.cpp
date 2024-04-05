// Fill out your copyright notice in the Description page of Project Settings.


#include "PKH/HttpTestActor.h"

#include "HttpModule.h"
#include "JsonParserLib.h"
#include "TestWidget.h"
#include "Interfaces/IHttpResponse.h"

// Sets default values
AHttpTestActor::AHttpTestActor()
{
	PrimaryActorTick.bCanEverTick = false;

	static ConstructorHelpers::FClassFinder<UTestWidget> TestUIClassRef(TEXT("/Game/PKH/UI/WBP_TestUI.WBP_TestUI_C"));
	if(TestUIClassRef.Class)
	{
		TestUIClass = TestUIClassRef.Class;
	}
}

void AHttpTestActor::BeginPlay()
{
	Super::BeginPlay();

	// UI
	TestUI = CreateWidget<UTestWidget>(GetWorld(), TestUIClass);
	if(TestUI)
	{
		TestUI->AddToViewport();
	}

	FTimerHandle Handle;
	GetWorldTimerManager().SetTimer(Handle, FTimerDelegate::CreateLambda([this]()
	{
		SendImage("http://127.0.0.1:8000/upload_base64");
	}), 3.0f, false);
}

void AHttpTestActor::SendImage(const FString& URL)
{
	// �̹��� ���� ���
	FString ImageFilePath = TEXT("D:/Projects/AI2ndProjectCCTV/Content/PKH/Images/ScreenShot00295.png"); 

	if(false == FPaths::FileExists(ImageFilePath))
	{
		UE_LOG(LogTemp, Error, TEXT("There is no file: %s"), *ImageFilePath);
		return;
	}

	// �̹��� ���� �б�
	TArray<uint8> ImageData;
	FFileHelper::LoadFileToArray(ImageData, *ImageFilePath);

	// �̹����� Base64�� ���ڵ�
	FString Base64Image = FBase64::Encode(ImageData);

	// HTTP ��û �����
	TSharedRef<IHttpRequest> HttpRequest = FHttpModule::Get().CreateRequest();
	HttpRequest->SetVerb(TEXT("POST"));
	HttpRequest->SetURL(URL);
	HttpRequest->SetHeader(TEXT("Content-Type"), TEXT("application/json"));
	HttpRequest->OnProcessRequestComplete().BindUObject(this, &AHttpTestActor::SendImageComplete);

	// JSON body�� Base64 �̹��� �߰�
	FString JsonBody = FString::Printf(TEXT("{\"image_base64\": \"%s\"}"), *Base64Image);
	HttpRequest->SetContentAsString(JsonBody);

	// ��û ������
	HttpRequest->ProcessRequest();

	UE_LOG(LogTemp, Warning, TEXT("%s"), *URL);
}

void AHttpTestActor::SendImageComplete(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bConnectedSuccessfully)
{
	if (bConnectedSuccessfully)
	{
		ReqTextData("http://127.0.0.1:8000/get_base64");
	}
	else
	{
		if (Request->GetStatus() == EHttpRequestStatus::Succeeded)
		{
			UE_LOG(LogTemp, Warning, TEXT("Response Failed...%d"), Response->GetResponseCode());
		}
	}
}

void AHttpTestActor::ReqTextData(const FString& URL)
{
	// Request Data from web server(URL)
	// 1. HttpModule�� ��������
	FHttpModule& httpModule = FHttpModule::Get();
	// 2. ��û ��ü�� �����ϰ�
	TSharedPtr<IHttpRequest> Req = httpModule.CreateRequest();
	// 3. ��û ��ü�� ��û�� ���� �����ϰ�
	//  3.1 ��� �������ΰ�?
	Req->SetURL(URL);
	//  3.2 ��� �������ΰ�?? GET / POST
	Req->SetVerb(TEXT("GET"));
	//  3.3 � Content-Type���� �Ұ��ΰ�?
	Req->SetHeader(TEXT("Content-Type"), TEXT("application/json"));
	// 4. ��û ��ü���� �������� ������ ���� �˷��޶�� ���Լ��� ����ϰ�ʹ�.
	Req->OnProcessRequestComplete().BindUObject(this, &AHttpTestActor::ResTextData);
	// 5. ��û ��ü���� ��û�϶�� �Ѵ�.
	Req->ProcessRequest();
}

void AHttpTestActor::ResTextData(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bConnectedSuccessfully)
{
	if (bConnectedSuccessfully)
	{
		FString ResultString = Response->GetContentAsString();
		UE_LOG(LogTemp, Warning, TEXT("%s"), *ResultString);

		FDetectionData ResultData = UJsonParserLib::JsonParse(ResultString);
		UE_LOG(LogTemp, Log, TEXT("Axe: %d"), ResultData.Axe);
		UE_LOG(LogTemp, Log, TEXT("BlueCap: %d"), ResultData.BlueCap);
		UE_LOG(LogTemp, Log, TEXT("CowboyHat: %d"), ResultData.CowboyHat);
		UE_LOG(LogTemp, Log, TEXT("Dagger: %d"), ResultData.Dagger);
		UE_LOG(LogTemp, Log, TEXT("GentleHat: %d"), ResultData.GentleHat);
		UE_LOG(LogTemp, Log, TEXT("GreatSword: %d"), ResultData.GreatSword);
		UE_LOG(LogTemp, Log, TEXT("Gun: %d"), ResultData.Gun);
		UE_LOG(LogTemp, Log, TEXT("LaserBlade: %d"), ResultData.LaserBlade);
		UE_LOG(LogTemp, Log, TEXT("MarioHat: %d"), ResultData.MarioHat);
		UE_LOG(LogTemp, Log, TEXT("SantaHat: %d"), ResultData.SantaHat);

		TestUI->UpdateDetectionUI(ResultData);
	}
	else
	{
		if (Request->GetStatus() == EHttpRequestStatus::Succeeded)
		{
			UE_LOG(LogTemp, Warning, TEXT("Response Failed...%d"), Response->GetResponseCode());
		}
	}
}
