// Copyright Epic Games, Inc. All Rights Reserved.

#include "MyModuleAndPluginGameMode.h"
#include "MyModuleAndPluginCharacter.h"
#include "UObject/ConstructorHelpers.h"

AMyModuleAndPluginGameMode::AMyModuleAndPluginGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
