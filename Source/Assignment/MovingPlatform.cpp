// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPlatform.h"

// Sets default values
AMovingPlatform::AMovingPlatform()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

    PlatformMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PlatformMesh"));
    SetRootComponent(PlatformMesh); 

    // Optional: attach collision box if needed for triggers
    BoxCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("Collision"));
    BoxCollision->SetupAttachment(PlatformMesh);

}

// Called when the game starts or when spawned
void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();
	

	StartLocation = GetActorLocation();
	TargetLocation = StartLocation + MovementOffset;
}

// Called every frame
void AMovingPlatform::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

   
    if (!bIsActive) return;

    FVector Destination = bMovingToTarget ? TargetLocation : StartLocation;
    FVector Direction = (Destination - GetActorLocation()).GetSafeNormal();
    FVector Movement = Direction * MovementSpeed * DeltaTime;

    FHitResult Hit;
    AddActorWorldOffset(Movement, true, &Hit); // ✅ Sweep enabled

    float DistanceToTarget = FVector::Dist(GetActorLocation(), Destination);
    if (DistanceToTarget < 10.f)
    {
        bMovingToTarget = !bMovingToTarget;
    }
    
}

void AMovingPlatform::SetPlatformActive(bool bActive)
{
    bIsActive = bActive;
    UE_LOG(LogTemp, Warning, TEXT("Platform activation: %s"), bActive ? TEXT("ON") : TEXT("OFF"));
}

