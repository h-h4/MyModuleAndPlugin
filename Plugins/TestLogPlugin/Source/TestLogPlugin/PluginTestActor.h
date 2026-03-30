#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PluginTestActor.generated.h"

UCLASS()
class TESTLOGPLUGIN_API APluginTestActor : public AActor
{
	GENERATED_BODY()
public:
	APluginTestActor();

protected:
	virtual void BeginPlay() override;
	
};
