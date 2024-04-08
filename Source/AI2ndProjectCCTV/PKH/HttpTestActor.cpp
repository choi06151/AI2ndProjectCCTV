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

	// 이미지 파일 읽기
	TArray<uint8> ImageData;
	FFileHelper::LoadFileToArray(ImageData, *ImageFilePath);

	// 이미지를 Base64로 인코딩
	FString Base64Image = FBase64::Encode(ImageData);

	// HTTP Request
	TSharedRef<IHttpRequest> HttpRequest = FHttpModule::Get().CreateRequest();
	HttpRequest->SetVerb(TEXT("POST"));
	HttpRequest->SetURL(UploadURL);
	HttpRequest->SetHeader(TEXT("Content-Type"), TEXT("application/json"));
	HttpRequest->OnProcessRequestComplete().BindUObject(this, &AHttpTestActor::SendImageComplete);

	// JSON body에 Base64 이미지 추가
	// 양식 주의할 것(웹 서버쪽의 양식과 정확하게 일치해야 함)
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
	// 1. HttpModule를 가져오고
	FHttpModule& httpModule = FHttpModule::Get();
	// 2. 요청 객체를 생성하고
	TSharedPtr<IHttpRequest> Req = httpModule.CreateRequest();
	// 3. 요청 객체에 요청할 값을 설정하고
	//  3.1 어디에 보낼것인가?
	Req->SetURL(GetURL);
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
