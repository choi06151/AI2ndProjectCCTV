// Fill out your copyright notice in the Description page of Project Settings.


#include "PKH/HttpTestActor.h"

#include "HttpGameMode.h"
#include "HttpModule.h"
#include "JsonParserLib.h"
#include "Components/SceneCaptureComponent2D.h"
#include "Engine/TextureRenderTarget2D.h"
#include "Interfaces/IHttpResponse.h"
#include "Kismet/KismetRenderingLibrary.h"
#include "Kismet/KismetSystemLibrary.h"

// Sets default values
AHttpTestActor::AHttpTestActor()
{
	PrimaryActorTick.bCanEverTick = false;

	USceneComponent* SceneComp = CreateDefaultSubobject<USceneComponent>(TEXT("SceneComp"));
	SetRootComponent(SceneComp);

	CaptureComp = CreateDefaultSubobject<USceneCaptureComponent2D>(TEXT("CaptureComp"));
	CaptureComp->SetupAttachment(RootComponent);
	CaptureComp->bCaptureEveryFrame = false;

	static ConstructorHelpers::FObjectFinder<UTextureRenderTarget2D> RenderTargetRef(TEXT("/Script/Engine.TextureRenderTarget2D'/Game/PKH/RenderTarget/RT_Capture.RT_Capture'"));
	if(RenderTargetRef.Object)
	{
		RenderTarget = RenderTargetRef.Object;
	}
}

void AHttpTestActor::BeginPlay()
{
	Super::BeginPlay();

	// GameMode
	GameMode = Cast<AHttpGameMode>(GetWorld()->GetAuthGameMode());
	if(nullptr == GameMode)
	{
		return;
	}
}

void AHttpTestActor::SendImage()
{
	// Get Image File Data
	const FString FilePath = UKismetSystemLibrary::GetProjectDirectory();
	const FString FileName = TEXT("SceneCapture.png");
	UKismetRenderingLibrary::ExportRenderTarget(GetWorld(), RenderTarget, FilePath, FileName);

	const FString ImageFilePath = FilePath + FileName;
	if (false == FPaths::FileExists(ImageFilePath))
	{
		UE_LOG(LogTemp, Error, TEXT("There is no file: %s"), *ImageFilePath);
		return;
	}

	// �̹��� ���� �б�
	TArray<uint8> ImageData;
	FFileHelper::LoadFileToArray(ImageData, *ImageFilePath);

	// �̹����� Base64�� ���ڵ�
	FString Base64Image = FBase64::Encode(ImageData);

	// HTTP Request
	TSharedRef<IHttpRequest> HttpRequest = FHttpModule::Get().CreateRequest();
	HttpRequest->SetVerb(TEXT("POST"));
	HttpRequest->SetURL(UploadURL);
	HttpRequest->SetHeader(TEXT("Content-Type"), TEXT("application/json"));
	HttpRequest->OnProcessRequestComplete().BindUObject(this, &AHttpTestActor::SendImageComplete);

	// JSON body�� Base64 �̹��� �߰�
	// ��� ������ ��(�� �������� ��İ� ��Ȯ�ϰ� ��ġ�ؾ� ��)
	FString JsonBody = FString::Printf(TEXT("{\"image_base64\": \"%s\"}"), *Base64Image);
	HttpRequest->SetContentAsString(JsonBody);

	HttpRequest->ProcessRequest();

	UE_LOG(LogTemp, Warning, TEXT("%s"), *UploadURL);
}

void AHttpTestActor::SendImageComplete(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bConnectedSuccessfully)
{
	if (bConnectedSuccessfully)
	{
		ReqTextData();
	}
	else
	{
		if (Request->GetStatus() == EHttpRequestStatus::Succeeded)
		{
			UE_LOG(LogTemp, Warning, TEXT("Response Failed...%d"), Response->GetResponseCode());
		}
	}
}

void AHttpTestActor::ReqTextData()
{
	// Request Data from web server(URL)
	// 1. HttpModule�� ��������
	FHttpModule& httpModule = FHttpModule::Get();
	// 2. ��û ��ü�� �����ϰ�
	TSharedPtr<IHttpRequest> Req = httpModule.CreateRequest();
	// 3. ��û ��ü�� ��û�� ���� �����ϰ�
	//  3.1 ��� �������ΰ�?
	Req->SetURL(GetURL);
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
		GameMode->UpdateDetectionData(ResultData);
	}
	else
	{
		if (Request->GetStatus() == EHttpRequestStatus::Succeeded)
		{
			UE_LOG(LogTemp, Warning, TEXT("Response Failed...%d"), Response->GetResponseCode());
		}
	}
}
