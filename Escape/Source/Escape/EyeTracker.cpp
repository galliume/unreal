// Fill out your copyright notice in the Description page of Project Settings.


#include "EyeTracker.h"
#include "Math/Quat.h" 
#include "GameFramework/Actor.h"

// Sets default values for this component's properties
UEyeTracker::UEyeTracker()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UEyeTracker::BeginPlay()
{
	Super::BeginPlay();
}


// Called every frame
void UEyeTracker::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	FRotator EyeRotator = GetOwner()->GetActorRotation();

	FVector PlayerLocation = GetWorld()->GetFirstPlayerController()->GetPawn()->GetActorLocation();
	UE_LOG(LogTemp, Warning, TEXT("Player location : %s"), *PlayerLocation.ToCompactString());

	//EyeRotator.Pitch = PlayerLocation.Y;
	EyeRotator.Yaw = PlayerLocation.Z;
	EyeRotator.Roll = PlayerLocation.X;

	GetOwner()->SetActorRotation(EyeRotator);
}

