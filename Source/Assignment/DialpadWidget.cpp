// Fill out your copyright notice in the Description page of Project Settings.


#include "DialpadWidget.h"
#include "Dialpad.h"
#include "Components/TextBlock.h"

void UDialpadWidget::OnDigitPressed(const FString& Digit)
{
    CurrentInput += Digit;
    if (DisplayText)
    {
        DisplayText->SetText(FText::FromString(CurrentInput));
    }
}

void UDialpadWidget::OnSubmitPressed()
{
    if (LinkedPhone)
    {
        LinkedPhone->SubmitCode(CurrentInput);
    }
    else
    {
        UE_LOG(LogTemp, Warning, TEXT("Failed to cast widget to UDialpadWidget"));
    }
}
