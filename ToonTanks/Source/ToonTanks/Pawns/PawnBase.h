// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "PawnBase.generated.h"

class UCapsuleComponent;
class AProjectileBase;
class UHealthComponent;

UCLASS()
class TOONTANKS_API APawnBase : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	APawnBase();

	void PawnDetroyed();
	
protected:
	void RotateTurret(FVector LookAtTarget);
	void Fire();
	virtual void HandleDestruction();

private :
	UPROPERTY(VisibleAnywhere, BluePrintReadOnly, Category = "Components", meta = (AllowPRivateAccess = "true"))
	UCapsuleComponent* CapsuleComp;
	UPROPERTY(VisibleAnywhere, BluePrintReadOnly, Category = "Components", meta = (AllowPRivateAccess = "true"))
	UStaticMeshComponent* BaseMesh;
	UPROPERTY(VisibleAnywhere, BluePrintReadOnly, Category = "Components", meta = (AllowPRivateAccess = "true"))
	UStaticMeshComponent* TurretMesh;
	UPROPERTY(VisibleAnywhere, BluePrintReadOnly, Category = "Components", meta = (AllowPRivateAccess = "true"))
	USceneComponent* ProjectileSpawnPoint;

	UPROPERTY(EditAnywhere, BluePrintReadOnly, Category = "Projetcile type", meta = (AllowPRivateAccess = "true"))
	TSubclassOf<AProjectileBase> ProjectileClass;

	UPROPERTY(EditAnywhere, BluePrintReadOnly, Category = "Effetcs", meta = (AllowPRivateAccess = "true"))
	UParticleSystem* DeathParticle;

	UPROPERTY(VisibleAnywhere, BluePrintReadOnly, Category = "Components", meta = (AllowPRivateAccess = "true"))
	UHealthComponent* HealthComponent;
};
