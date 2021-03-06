// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PawnBase.h"
#include "PawnTurret.generated.h"

class APawnTank;

UCLASS()
class TOONTANKS_API APawnTurret : public APawnBase
{
	GENERATED_BODY()
	
	public:
		APawnTurret();

		// Called every frame
		virtual void Tick(float DeltaTime) override;
		
	private:
		UPROPERTY(EditAnywhere, BluePrintReadWrite, Category = "Combat", meta = (AllowPrivateAccess = "true"))
		float FireRate = 2.0f;
		UPROPERTY(EditAnywhere, BluePrintReadWrite, Category = "Combat", meta = (AllowPrivateAccess = "true"))
		float FireRange = 500.0f;
		APawnTank* PlayerPawn;
		FTimerHandle FireRateTimerHandle;
		
		void CheckFireCondition();
		float ReturnDistanceToPlayer();

	protected:
		virtual void BeginPlay() override;
		virtual void HandleDestruction() override;
};
