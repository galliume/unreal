// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"

void UBullCowCartridge::BeginPlay() // When the game starts
{
    Super::BeginPlay();
    SetupGame();
}

void UBullCowCartridge::OnInput(const FString& Input) // When the player hits enter
{
    if (bGameOver)
    {
        ClearScreen();
        SetupGame();
    }
    else 
    {
        if (Input == HiddenWord)   
        {
            PrintLine(TEXT("you have won !"));
            EndGame();
        }
        else
        {
            if (Input.Len() != HiddenWord.Len()) 
            {
                PrintLine(TEXT("The hidden word is %i letters long."), HiddenWord.Len());
                EndGame();
            }
        }
    }
}

void UBullCowCartridge::SetupGame()
{
    Lives = 5;
    HiddenWord = TEXT("secret");
    bGameOver = false;

    PrintLine(TEXT("Hello, welcome to bull cows"));
    PrintLine(TEXT("Guess the %i letter word."), HiddenWord.Len());
    PrintLine(TEXT("Type in your guess and press enter to continue..."));
}

void UBullCowCartridge::EndGame()
{
    bGameOver = true;
    PrintLine(TEXT("Press enter to play again."));
}
