// Fill out your copyright notice in the Description page of Project Settings.


#include "ColourValidator.h"
#include "ColourSwitch.h"

// Sets default values
AColourSwitch::AColourSwitch()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

    InteractionZone = CreateDefaultSubobject<USphereComponent>(TEXT("InteractionZone"));
    RootComponent = InteractionZone;
    InteractionZone->InitSphereRadius(100.f);
  
    


    Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
    Mesh->SetupAttachment(InteractionZone);
}

// Called when the game starts or when spawned
void AColourSwitch::BeginPlay()
{
    Super::BeginPlay();
    SetActorHiddenInGame(true);
    SetActorEnableCollision(false); 
    DynamicMat = Mesh->CreateAndSetMaterialInstanceDynamic(0);
    UpdateColor();
	
}

// Called every frame
void AColourSwitch::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


void AColourSwitch::Interact_Implementation(AActor* Interactor)
{
    UE_LOG(LogTemp, Warning, TEXT("ColorSwitch Interacted!"));

    CurrentColorIndex = (CurrentColorIndex + 1) % ColorOptions.Num();
    UpdateColor();
    if (Validator)
    {
        Validator->ValidateCombination();
    }

}

void AColourSwitch::UpdateColor()
{
    if (DynamicMat && ColorOptions.IsValidIndex(CurrentColorIndex))
    {
        DynamicMat->SetVectorParameterValue("Color", ColorOptions[CurrentColorIndex]);
    }
}

int32 AColourSwitch::GetCurrentColorIndex() const
{
    return CurrentColorIndex;
}