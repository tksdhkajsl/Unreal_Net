// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "TestGameState.generated.h"

/**
 * 
 */
UCLASS()
class KI7_UNREALNETWORK_API ATestGameState : public AGameStateBase
{
	GENERATED_BODY()

public:

	inline float GetGameElapsedTime() const { return GameElapsedTime; }
	inline float GetGameRemainingTime() const { return GameRemainingTime; }
	inline bool IsGameOver() const { return bGameOver; }
	
protected:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

protected:
	UPROPERTY(Replicated, BlueprintReadOnly, Category = "Game Data")
	float GameElapsedTime = 0.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Game Data")
	float GameDuration = 10.0f; //게임 한 판 시간 :Gamemode에 추가하는 것이 적합함.

	UPROPERTY(Replicated, BlueprintReadOnly, Category = "Game Data")
	float GameRemainingTime = 0.0f;

	UPROPERTY(Replicated, BlueprintReadOnly, Category = "Game Data")
	bool bGameOver = false;
};
