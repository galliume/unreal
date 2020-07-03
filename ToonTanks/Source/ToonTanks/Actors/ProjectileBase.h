// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Particles/ParticleSystemComponent.h"
#include "ProjectileBase.generated.h"

class UProjectileMovementComponent;

UCLASS()
class TOONTANKS_API AProjectileBase : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AProjectileBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:	

	UPROPERTY(VisibleAnywhere, BluePrintReadOnly, Category = "Components", meta = (AllowPRivateAccess = "true"))
	UProjectileMovementComponent* ProjectileMovement;

	UPROPERTY(VisibleAnywhere, BluePrintReadOnly, Category = "Components", meta = (AllowPRivateAccess = "true"))
	UStaticMeshComponent* ProjectileMesh;

	UPROPERTY(VisibleAnywhere, BluePrintReadOnly, Category = "Components", meta = (AllowPRivateAccess = "true"))
	UParticleSystemComponent* ParticleTrail;

	UPROPERTY(EditDefaultsOnly, Category = "Damage", meta = (AllowPRivateAccess = "true"))
	TSubclassOf<UDamageType> DamageType;

	UPROPERTY(EditAnywhere, BluePrintReadWrite, Category = "Movement", meta = (AllowPRivateAccess = "true"))
	float MovementSpeed = 1300.0f;

	UPROPERTY(EditAnywhere, BluePrintReadWrite, Category = "Damage", meta = (AllowPRivateAccess = "true"))
	float Damage = 50.0f;

	UPROPERTY(EditAnywhere, BluePrintReadOnly, Category = "Effetcs", meta = (AllowPRivateAccess = "true"))
	UParticleSystem* HitParticle;

	UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

};
