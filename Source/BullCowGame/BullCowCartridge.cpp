// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"

void UBullCowCartridge::BeginPlay() // When the game starts
{
    Super::BeginPlay();
    PrintLine(TEXT("Hello, welcome to bull cows"));
    PrintLine(TEXT("press enter to continue..."));
}

void UBullCowCartridge::OnInput(const FString& Input) // When the player hits enter
{
    ClearScreen();

    FString HiddenWord = TEXT("secret");
}