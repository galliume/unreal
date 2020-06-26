// Fill out your copyright notice in the Description page of Project Settings.

#include "Door.h"
#include "Engine/World.h"
#include "GameFramework/PlayerController.h"
#include "GameFramework/Actor.h"
#include "Components/PrimitiveComponent.h" 

// Sets default values for this component's properties
UDoor::UDoor()
{
	PrimaryComponentTick.bCanEverTick = true;
}

// Called when the game starts
void UDoor::BeginPlay()
{
	Super::BeginPlay();

	InitialYaw = GetOwner()->GetActorRotation().Yaw;
	CurrentYaw = InitialYaw;
	TargetYaw += InitialYaw;

	ActorThatOpen = GetWorld()->GetFirstPlayerController()->GetPawn();
}


// Called every frame
void UDoor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (!IsLocked && PressurePlate && PressurePlate->IsOverlappingActor(ActorThatOpen))
	{
		IsLocked = true;
		TargetYaw = 180.f;
		TogglingSpeed = 10000;
		ToggleDoor(DeltaTime);	
		
		if (IsLocked && DoorScream)
		{
			ActorToShow->SetActorHiddenInGame(false);
			DoorScream->Play();
			Ambient->Play();
		}
	} 
	else if (!IsLocked)
	{
		ToggleDoor(DeltaTime);	
	} 

	if (TotalMassOfActors() > MassToOpenDoor)
	{
		TogglingSpeed = 30;	
		TargetYaw = 280.f;
		ToggleDoor(DeltaTime);	
	}

	TimeElapsed = GetWorld()->GetTimeSeconds();
}

void UDoor::ToggleDoor(float DeltaTime)
{	
	CurrentYaw = FMath::FInterpTo(CurrentYaw, TargetYaw, DeltaTime, DeltaTime * TogglingSpeed);
	FRotator DoorOpener = GetOwner()->GetActorRotation();
	DoorOpener.Yaw = CurrentYaw;
	GetOwner()->SetActorRotation(DoorOpener); 
}

float UDoor::TotalMassOfActors() const
{
	float TotalMass = 0.f;

	if (KeyeTrigger) 
	{
		TArray<AActor*> OverlappingActors;
		KeyeTrigger->GetOverlappingActors(OverlappingActors);

		for (AActor* Actor : OverlappingActors)
		{
			TotalMass += Actor->FindComponentByClass<UPrimitiveComponent>()->GetMass();
		}
	}

	return TotalMass;
}