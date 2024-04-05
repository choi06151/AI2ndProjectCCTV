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
	// 이미지 파일 경로
	FString ImageFilePath = TEXT("D:/Projects/AI2ndProjectCCTV/Content/PKH/Images/ScreenShot00295.png"); 

	if(false == FPaths::FileExists(ImageFilePath))
	{
		UE_LOG(LogTemp, Error, TEXT("There is no file: %s"), *ImageFilePath);
		return;
	}

	// 이미지 파일 읽기
	TArray<uint8> ImageData;
	FFileHelper::LoadFileToArray(ImageData, *ImageFilePath);

	// 이미지를 Base64로 인코딩
	FString Base64Image = FBase64::Encode(ImageData);

	// HTTP 요청 만들기
	TSharedRef<IHttpRequest> HttpRequest = FHttpModule::Get().CreateRequest();
	HttpRequest->SetVerb(TEXT("POST"));
	HttpRequest->SetURL(URL);
	HttpRequest->SetHeader(TEXT("Content-Type"), TEXT("application/json"));
	HttpRequest->OnProcessRequestComplete().BindUObject(this, &AHttpTestActor::SendImageComplete);

	// JSON body에 Base64 이미지 추가
	FString JsonBody = FString::Printf(TEXT("{\"image_base64\": \"%s\"}"), *Base64Image);
	HttpRequest->SetContentAsString(JsonBody);

	// 요청 보내기
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
	// 1. HttpModule를 가져오고
	FHttpModule& httpModule = FHttpModule::Get();
	// 2. 요청 객체를 생성하고
	TSharedPtr<IHttpRequest> Req = httpModule.CreateRequest();
	// 3. 요청 객체에 요청할 값을 설정하고
	//  3.1 어디에 보낼것인가?
	Req->SetURL(URL);
	//  3.2 어떻게 보낼것인가?? GET / POST
	Req->SetVerb(TEXT("GET"));
	//  3.3 어떤 Content-Type으로 할것인가?
	Req->SetHeader(TEXT("Content-Type"), TEXT("application/json"));
	// 4. 요청 객체에게 서버에서 응답이 오면 알려달라고 내함수를 등록하고싶다.
	Req->OnProcessRequestComplete().BindUObject(this, &AHttpTestActor::ResTextData);
	// 5. 요청 객체에게 요청하라고 한다.
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
