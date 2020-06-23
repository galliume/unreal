// Fill out your copyright notice in the Description page of Project Settings.

#include "Engine/World.h"
#include "GameFramework/PlayerController.h"
#include "GameFramework/Actor.h"
#include "Door.h"

// Sets default values for this component's properties
UDoor::UDoor()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
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
}

void UDoor::ToggleDoor(float DeltaTime)
{	
	CurrentYaw = FMath::FInterpTo(CurrentYaw, TargetYaw, DeltaTime, DeltaTime * TogglingSpeed);
	FRotator DoorOpener = GetOwner()->GetActorRotation();
	DoorOpener.Yaw = CurrentYaw;
	GetOwner()->SetActorRotation(DoorOpener); 
/* 	
	float AngleOpener = FMath::RandRange(0.f, 0.1f);
	float CurrentYaw = GetOwner()->GetActorRotation().Yaw;
	FRotator DoorOpener(0.f, TargetYaw, 0.f);
	DoorOpener.Yaw = FMath::FInterpTo(CurrentYaw, TargetYaw, DeltaTime, 2);
	GetOwner()->SetActorRotation(DoorOpener); 
*/
}
