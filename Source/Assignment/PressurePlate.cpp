// Fill out your copyright notice in the Description page of Project Settings.


#include "PressurePlate.h"
#include "AssignmentCharacter.h"


// Sets default values
APressurePlate::APressurePlate()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


    PlateMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PlateMesh"));
    RootComponent = PlateMesh;

    TriggerZone = CreateDefaultSubobject<UBoxComponent>(TEXT("TriggerZone"));
    TriggerZone->SetupAttachment(RootComponent);
    TriggerZone->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
    TriggerZone->SetCollisionResponseToAllChannels(ECR_Ignore);
    TriggerZone->SetCollisionResponseToChannel(ECC_PhysicsBody, ECR_Overlap);
    TriggerZone->SetGenerateOverlapEvents(true);

}

// Called when the game starts or when spawned
void APressurePlate::BeginPlay()
{
	Super::BeginPlay();
	
   
    if(GateToOpen)
    {
        GateInitialLocation = GateToOpen->GetActorLocation();
    }

    TriggerZone->OnComponentBeginOverlap.AddDynamic(this, &APressurePlate::OnOverlapBegin);
    TriggerZone->OnComponentEndOverlap.AddDynamic(this, &APressurePlate::OnOverlapEnd);
}




// Called every frame

void APressurePlate::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
    UPrimitiveComponent* OtherComp, int32 OtherBodyIndex,
    bool bFromSweep, const FHitResult& SweepResult)
{
    UE_LOG(LogTemp, Warning, TEXT("Overlap Begin with: %s"), *OtherActor->GetName());
    if (GateToOpen && OtherActor && (OtherActor->ActorHasTag("Box") || OtherActor->IsA(ACharacter::StaticClass())))
    {
        FVector NewLocation = GateToOpen->GetActorLocation() + GateOpenOffset;
        GateToOpen->SetActorLocation(NewLocation);
    }

}
void APressurePlate::OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
    UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
    if (GateToOpen)
    {
        GateToOpen->SetActorLocation(GateInitialLocation);
    }
}
