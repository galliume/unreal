// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "TankGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class TOONTANKS_API ATankGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
	
	protected:
		virtual void BeginPlay() override;

	public:
		void ActorDied(AActor* DeadActor);

		UFUNCTION(BluePrintImplementableEvent)
		void GameStart();
		UFUNCTION(BluePrintImplementableEvent)
		void GameOver(bool PlayerWon);
	private:
		void HandleGameStart();
		void HandleGameOver(bool PlayerWon);
};
