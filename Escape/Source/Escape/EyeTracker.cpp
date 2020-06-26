// Fill out your copyright notice in the Description page of Project Settings.


#include "EyeTracker.h"
#include <math.h>
#include "Kismet/KismetMathLibrary.h"
#include "GameFramework/Actor.h"

// Sets default values for this component's properties
UEyeTracker::UEyeTracker()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
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

 	FVector PlayerLocation = GetWorld()->GetFirstPlayerController()->GetPawn()->GetActorLocation();
	FRotator PlayerRot = UKismetMathLibrary::FindLookAtRotation(GetOwner()->GetActorLocation(), PlayerLocation);
	GetOwner()->SetActorRotation(PlayerRot); 
}

