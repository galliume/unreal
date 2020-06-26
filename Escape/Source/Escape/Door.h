// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine/TriggerVolume.h"
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Sound/AmbientSound.h" 
#include "Door.generated.h"

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ESCAPE_API UDoor : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UDoor();
	void ToggleDoor(float DeltaTime);
	float TotalMassOfActors() const;

	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

private:
	float CurrentYaw;
	float InitialYaw;
	int TogglingSpeed = 30;
	bool IsLocked = false;		
	float TimeElapsed = 0.f;

	UPROPERTY(EditAnywhere)
	float TargetYaw = 90.f;
	
	UPROPERTY(EditAnywhere)
	ATriggerVolume* PressurePlate;

	UPROPERTY(EditAnywhere)
	ATriggerVolume* KeyeTrigger;

	UPROPERTY(EditAnywhere)
	AAmbientSound* DoorScream;

	UPROPERTY(EditAnywhere)
	AAmbientSound* Ambient;

	UPROPERTY(EditAnywhere)
	AActor* ActorThatOpen; 

	UPROPERTY(EditAnywhere)
	AActor* ActorToShow; 

	UPROPERTY(EditAnywhere)
	float MassToOpenDoor = 1.f; 	
};
