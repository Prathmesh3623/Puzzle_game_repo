// Fill out your copyright notice in the Description page of Project Settings.


#include "Lever.h"
#include "MovingPlatform.h"
#include "AssignmentCharacter.h"


// Sets default values
ALever::ALever()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
   

    InteractionSphere = CreateDefaultSubobject<USphereComponent>(TEXT("InteractionSphere"));
    RootComponent = InteractionSphere;
    InteractionSphere->SetSphereRadius(150.f);
    InteractionSphere->SetCollisionProfileName(TEXT("Trigger"));


    Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
    Mesh->SetupAttachment(InteractionSphere);

    HandleMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("HnadleMesh"));
    HandleMesh->SetupAttachment(Mesh);

}

// Called when the game starts or when spawned
void ALever::BeginPlay()
{
	Super::BeginPlay();
    InteractionSphere->OnComponentBeginOverlap.AddDynamic(this, &ALever::OnOverlapBegin);
    InteractionSphere->OnComponentEndOverlap.AddDynamic(this, &ALever::OnOverlapEnd);
}

// Called every frame
void ALever::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
void ALever::Interact_Implementation(AActor* Interactor)
{
    ToggleLever();
}
void ALever::ToggleLever()
{
    bIsOn = !bIsOn;

    for (AActor* Platform : ControlledPlatforms)
    {
        if (AMovingPlatform* MP = Cast<AMovingPlatform>(Platform))
        {
            MP->SetPlatformActive(bIsOn);
            UE_LOG(LogTemp, Display, TEXT("Toggling"));
        }
    }
    FRotator OnRotation = FRotator(0.f, 0.f, -90.f);
    FRotator OffRotation = FRotator(0.f, 0.f, 0.f);

    HandleMesh->SetRelativeRotation(bIsOn ? OnRotation : OffRotation);

}
void ALever::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
    UPrimitiveComponent* OtherComp, int32 OtherBodyIndex,
    bool bFromSweep, const FHitResult& SweepResult)
{
    if (OtherActor->IsA(AAssignmentCharacter::StaticClass()))
    {
        bPlayerInRange = true;
        UE_LOG(LogTemp, Display, TEXT("Press E to Toggle"));
        // Optional: Show UI prompt like "Press E to toggle"
    }
}

void ALever::OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
    UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
    if (OtherActor->IsA(AAssignmentCharacter::StaticClass()))
    {
        bPlayerInRange = false;
        // Optional: Hide UI prompt
    }
}
