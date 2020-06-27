// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PawnBase.h"
#include "PawnTank.generated.h"

class USpringArmComponent;
class UCameraComponent;

UCLASS()
class TOONTANKS_API APawnTank : public APawnBase
{
	GENERATED_BODY()

	public:

		APawnTank();

		// Called every frame
		virtual void Tick(float DeltaTime) override;

		// Called to bind functionality to input
		virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

		virtual void BeginPlay() override;
	private:

		UPROPERTY(VisibleAnywhere, BluePrintReadOnly, Category = "Components", meta = (AllowPRivateAccess = "true"))
		USpringArmComponent* SpringArm;
		
		UPROPERTY(VisibleAnywhere, BluePrintReadOnly, Category = "Components", meta = (AllowPRivateAccess = "true"))
		UCameraComponent* Camera;

		FVector MoveDirection;
		FQuat RotationDirection;
	
		float MoveSpeed = 100.0f;
		float RotateSpeed = 100.0f;

		void CalculateMoveInput(float Value);
		void CalculateRotateInput(float Value);

		void Move();
		void Rotate();
	protected:
};