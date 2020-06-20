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
        ProcessGuess(Input, Lives);
    }
}

void UBullCowCartridge::SetupGame()
{    
    HiddenWord = TEXT("secret");
    Lives = HiddenWord.Len();
    bGameOver = false;

    PrintLine(TEXT("Hello, welcome to bull cows"));
    PrintLine(TEXT("Guess the %i letter word."), HiddenWord.Len());
    PrintLine(TEXT("You have %i lives"), Lives);
    PrintLine(TEXT("Type in your guess and press enter to continue..."));
}

void UBullCowCartridge::EndGame()
{
    bGameOver = true;
    PrintLine(TEXT("Press enter to play again."));
}

void UBullCowCartridge::ProcessGuess(FString Guess, int32 counter)
{
  if (Guess == HiddenWord)   
        {
            PrintLine(TEXT("you have won !"));
            EndGame();
        }
        else
        {
            --counter;

            if (counter < 0) 
            {
                PrintLine(TEXT("No lives left. You lost."), counter);
                EndGame();
            }
            else 
            {
                if (Guess.Len() != HiddenWord.Len()) 
                {
                   PrintLine(TEXT("Try guessing again. You have %i lives"), counter);
                }
            }
        }
}
