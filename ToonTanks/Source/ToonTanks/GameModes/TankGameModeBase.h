// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "TankGameModeBase.generated.h"

class APawnTurret;
class APawnTank;

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

		int32 TargetTurrets = 0;
		
		UPROPERTY(VisibleAnywhere, BluePrintReadOnly, Category = "Player", meta = (AllowPRivateAccess = "true"))
		APawnTank* PlayerTank;

		UPROPERTY(EditAnywhere, BluePrintReadWrite, Category = "Game loop", meta = (AllowPRivateAccess = "true"))
		int StartDelay = 3;

		void HandleGameStart();
		void HandleGameOver(bool PlayerWon);
		int32 GetTargetTurretsCount();
};
