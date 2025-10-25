// Fill out your copyright notice in the Description page of Project Settings.


#include "Light_Switch.h"


// Sets default values
ALight_Switch::ALight_Switch()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


    InteractionSphere = CreateDefaultSubobject<USphereComponent>(TEXT("InteractionSphere"));
    RootComponent = InteractionSphere;
    InteractionSphere->SetSphereRadius(150.f);
    InteractionSphere->SetCollisionProfileName(TEXT("Trigger"));


    
    SwitchMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("LeverMesh"));
    SwitchMesh->SetupAttachment(InteractionSphere);

    HandleMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("HandleMesh"));
    HandleMesh->SetupAttachment(SwitchMesh);
    
}

// Called when the game starts or when spawned
void ALight_Switch::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ALight_Switch::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ALight_Switch::Interact_Implementation(AActor* Interactor)
{
    bIsHandleRotated = !bIsHandleRotated;
    if (RevealLight)
    {
        RevealLight->SetVisibility(true);
    }

    

    for (AColourSwitch* Switch : ControlledColorSwitches)
    {
        if (Switch)
        {
            Switch->SetActorHiddenInGame(false);
            Switch->SetActorEnableCollision(true); // Optional: allow interaction
        }
    }


    FRotator TargetRotation = bIsHandleRotated ? FRotator(0.f, 0.f, -33.f) : FRotator(0.f, 0.f, 54.f);
    HandleMesh->SetRelativeRotation(TargetRotation); 
    

}

