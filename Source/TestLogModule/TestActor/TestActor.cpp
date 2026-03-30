// Fill out your copyright notice in the Description page of Project Settings.


#include "TestActor.h"


ATestActor::ATestActor()
{
	PrimaryActorTick.bCanEverTick = false;
}

void ATestActor::BeginPlay()
{
	Super::BeginPlay();
	
	UE_LOG(LogTemp, Warning, TEXT("TestLogModule의 TestActor이 정상적으로 생성되었습니다."));
}

void ATestActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

