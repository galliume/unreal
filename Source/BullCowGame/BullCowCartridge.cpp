// Fill out your copyright notice in the Description page of Project Settings.
#include "Misc/FileHelper.h"
#include "Misc/Paths.h"
#include "BullCowCartridge.h"

void UBullCowCartridge::BeginPlay() // When the game starts
{
    Super::BeginPlay();

    const FString WordListPath = FPaths::ProjectContentDir() / TEXT("WordList/HiddenWordList.txt");
    TArray<FString> WordList;
    FFileHelper::LoadFileToStringArray(WordList, *WordListPath);
        
    Isograms = GetValidWords(WordList);

    SetupGame();
}

void UBullCowCartridge::OnInput(const FString& PlayerInput) // When the player hits enter
{
    if (bGameOver)
    {
        ClearScreen();
        SetupGame();
    }
    else 
    {
        ProcessGuess(PlayerInput);
    }
}

void UBullCowCartridge::SetupGame()
{    
    HiddenWord = Isograms[FMath::RandRange(0, Isograms.Num()) - 1];
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
    PrintLine(TEXT("\nPress enter to play again."));
}

void UBullCowCartridge::ProcessGuess(const FString& Guess)
{
    if (Guess == HiddenWord)   
    {
        PrintLine(TEXT("you have won !"));
        EndGame();
        return;
    }

    if (Guess.Len() != HiddenWord.Len()) 
    {
        PrintLine(TEXT("Try guessing again. You have %i lives"), Lives);
        PrintLine(TEXT("The hidden word is %i letters long"), HiddenWord.Len());
        return;
    }

    if (!IsIsogram(Guess))
    {
        PrintLine(TEXT("No repeating letters, guess again"));
        return;
    } 

    PrintLine(TEXT("Lost a life !"));
    --Lives;

    if (Lives <= 0)
    {
        ClearScreen();

        PrintLine(TEXT("No lives left."));
        PrintLine(TEXT("The hidden word was %s"), *HiddenWord);
        PrintLine(TEXT("No lives left !"));

        EndGame();
        return;
    }

    PrintLine(TEXT("Guess again, you have %i lives left !"), Lives);
}

bool UBullCowCartridge::IsIsogram(const FString& Word) const
{
    for (int32 Index = 0; Index < Word.Len(); Index++)
    {
        for (int32 Comparison = Index + 1; Comparison < Word.Len(); Comparison++)
        {
            if (Word[Index] == Word[Comparison])
            {
                return false;
            }
        }
    }

    return true;
}

TArray<FString> UBullCowCartridge::GetValidWords(const TArray<FString>& WordList) const
{
    TArray<FString> ValidWords;

    for (FString Word : WordList)
    {
        if (Word.Len() >= 4 && Word.Len() <= 8 && IsIsogram(Word))
        {
            ValidWords.Emplace(Word);
        }
    }

    return ValidWords;
}