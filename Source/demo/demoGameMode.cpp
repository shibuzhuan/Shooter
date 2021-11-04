// Copyright Epic Games, Inc. All Rights Reserved.

#include "demoGameMode.h"
#include "demoHUD.h"
#include "demoCharacter.h"
#include "MyGameState.h"
#include "UObject/ConstructorHelpers.h"

AdemoGameMode::AdemoGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = AdemoHUD::StaticClass();
	PrimaryActorTick.bCanEverTick = true;
}

void AdemoGameMode::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	AMyGameState* GS = GetGameState<AMyGameState>();
	if (GS)
	{
		if (GS->Score > 3)
		{
			OnVictory();
		}
	}
}

void AdemoGameMode::OnVictory_Implementation() 
{
	GEngine->AddOnScreenDebugMessage(0, 5.0f, FColor::Yellow, TEXT("Hello world"));
}
