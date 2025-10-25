// Fill out your copyright notice in the Description page of Project Settings.


#include "ColourValidator.h"

// Sets default values
AColourValidator::AColourValidator()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AColourValidator::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AColourValidator::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AColourValidator::ValidateCombination()
{
    UE_LOG(LogTemp, Warning, TEXT("Validating combination..."));
    for (int32 i = 0; i < Switches.Num(); ++i)
    {
        if (!Switches[i] || Switches[i]->GetCurrentColorIndex() != TargetCombo[i])
        {
            UE_LOG(LogTemp, Warning, TEXT("Incorrect combination"));
            return;
        }
    }

    UE_LOG(LogTemp, Warning, TEXT("Correct combination! Opening gate"));

    if (FinalDoor)
    {
        FVector NewLocation = FinalDoor->GetActorLocation() + FVector(0.f, 0.f, 600.f); // Move up
        FinalDoor->SetActorLocation(NewLocation);
    }

}
