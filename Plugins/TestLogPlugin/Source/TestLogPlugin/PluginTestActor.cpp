#include "PluginTestActor.h"



APluginTestActor::APluginTestActor()
{
	PrimaryActorTick.bCanEverTick = false;
}

void APluginTestActor::BeginPlay()
{
	Super::BeginPlay();
	
	UE_LOG(LogTemp, Warning, TEXT("TestLogPlugin의 액터가 정상적으로 스폰되었습니다"));
}