// Fill out your copyright notice in the Description page of Project Settings.


#include "Door.h"
#include "GameFramework/Actor.h"

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

	//FRotator DoorRotator(0.f, -60.f, 0.f);
	//GetOwner()->SetActorRotation(DoorRotator);
}


// Called every frame
void UDoor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	UE_LOG(LogTemp, Warning, TEXT("%s"), *GetOwner()->GetActorRotation().ToString());
	UE_LOG(LogTemp, Warning, TEXT("Current Yaw %f"), GetOwner()->GetActorRotation().Yaw);

	
	float AngleOpener = FMath::RandRange(0.f, 0.1f);

	float CurrentYaw = GetOwner()->GetActorRotation().Yaw;
	FRotator DoorOpener(0.f, TargetYaw, 0.f);
	DoorOpener.Yaw = FMath::FInterpTo(CurrentYaw, TargetYaw, DeltaTime, 2);
	GetOwner()->SetActorRotation(DoorOpener);
}

