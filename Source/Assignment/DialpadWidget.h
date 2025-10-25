// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Dialpad.h"
#include "Blueprint/UserWidget.h"
#include "DialpadWidget.generated.h"

/**
 * 
 */
UCLASS()
class ASSIGNMENT_API UDialpadWidget : public UUserWidget
{
	GENERATED_BODY()

public:
    UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
    class UTextBlock* DisplayText;

    UPROPERTY(BlueprintReadWrite)
    FString CurrentInput;

    UPROPERTY(BlueprintReadWrite)
    ADialpad* LinkedPhone;

    UFUNCTION(BlueprintCallable)
    void OnDigitPressed(const FString& Digit);

    UFUNCTION(BlueprintCallable)
    void OnSubmitPressed();



	
};
