// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ColourSwitch.h"
#include "GameFramework/Actor.h"
#include "ColourValidator.generated.h"

UCLASS()
class ASSIGNMENT_API AColourValidator : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AColourValidator();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
public:
	UFUNCTION(BlueprintCallable)
	void ValidateCombination();

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<AColourSwitch*> Switches;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<int32> TargetCombo;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	AActor* FinalDoor;


};
