// Fill out your copyright notice in the Description page of Project Settings.


#include "PKH/HttpGameMode.h"

#include "TestWidget.h"
#include "Blueprint/UserWidget.h"
#include "GameFramework/Character.h"

AHttpGameMode::AHttpGameMode()
{
	// Http Actor
	static ConstructorHelpers::FClassFinder<AHttpTestActor> HttpActorClassRef(TEXT("/Game/PKH/BP/BP_HttpTestActor.BP_HttpTestActor_C"));
	if(HttpActorClassRef.Class)
	{
		HttpActorClass = HttpActorClassRef.Class;
	}

	// UI
	static ConstructorHelpers::FClassFinder<UTestWidget> TestUIClassRef(TEXT("/Game/PKH/UI/WBP_TestUI.WBP_TestUI_C"));
	if (TestUIClassRef.Class)
	{
		TestUIClass = TestUIClassRef.Class;
	}
}

void AHttpGameMode::BeginPlay()
{
	Super::BeginPlay();

	// Spawn Http Actor 
	HttpActor = GetWorld()->SpawnActor<AHttpTestActor>(HttpActorClass, FVector(-500, 1350, 92), FRotator::ZeroRotator);

	// UI
	TestUI = CreateWidget<UTestWidget>(GetWorld(), TestUIClass);
	if (TestUI)
	{
		TestUI->AddToViewport();
	}

	/*FTimerHandle Handle;
	GetWorldTimerManager().SetTimer(Handle, FTimerDelegate::CreateLambda([this]()
	{
		Detect();
	}), 5.0f, true, 5.0f);*/
}

void AHttpGameMode::Detect()
{
	HttpActor->SendImage();
}

void AHttpGameMode::UpdateDetectionData(FDetectionData ResultData)
{
	CurDetectionData = ResultData;
	TestUI->UpdateDetectionUI(ResultData);
}
