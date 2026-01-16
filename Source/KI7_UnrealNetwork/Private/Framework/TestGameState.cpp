// Fill out your copyright notice in the Description page of Project Settings.


#include "Framework/TestGameState.h"
#include "Net/UnrealNetwork.h"

void ATestGameState::BeginPlay()
{
	Super::BeginPlay();
	GameRemainingTime = GameDuration;
}

void ATestGameState::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (HasAuthority())
	{
		GameElapsedTime += DeltaTime;
		if (GameRemainingTime < 0.0f)
		{
			GameRemainingTime = 0.0f;
		}
	}
}

void ATestGameState::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(ATestGameState, GameElapsedTime);
	DOREPLIFETIME(ATestGameState, GameRemainingTime);
}
