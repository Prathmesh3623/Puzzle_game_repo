// Fill out your copyright notice in the Description page of Project Settings.


#include "Dialpad.h"
#include "DialpadWidget.h"
#include "Blueprint/UserWidget.h"

// Sets default values
ADialpad::ADialpad()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

    static ConstructorHelpers::FClassFinder<UUserWidget> WidgetClass(TEXT("/Script/UMGEditor.WidgetBlueprint'/Game/Blueprints/BP_DialpadWidget.BP_DialpadWidget'"));
    if (WidgetClass.Succeeded())
    {
        DialpadWidgetClass = WidgetClass.Class;
    }

    InteractionSphere = CreateDefaultSubobject<USphereComponent>(TEXT("InteractionSphere"));
    RootComponent = InteractionSphere;
    InteractionSphere->SetSphereRadius(150.f);
    InteractionSphere->SetCollisionProfileName(TEXT("Trigger"));


    PhoneMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PhoneMesh"));
    PhoneMesh->SetupAttachment(InteractionSphere);

}

// Called when the game starts or when spawned
void ADialpad::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ADialpad::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ADialpad::Interact_Implementation(AActor* Interactor)
{
    UE_LOG(LogTemp, Warning, TEXT("Trying to interact with phone"));
    UE_LOG(LogTemp, Warning, TEXT("DialpadWidgetClass is %s"), DialpadWidgetClass ? *DialpadWidgetClass->GetName() : TEXT("nullptr"));
    UE_LOG(LogTemp, Warning, TEXT("ActiveWidget is %s"), ActiveWidget ? *ActiveWidget->GetName() : TEXT("nullptr"));
    if (DialpadWidgetClass && !ActiveWidget)
    {
        ActiveWidget = CreateWidget<UUserWidget>(GetWorld(), DialpadWidgetClass);
        if (ActiveWidget)
        {
            ActiveWidget->AddToViewport();
            UE_LOG(LogTemp, Warning, TEXT("widget added to viewport"));
            
            APlayerController* PC = GetWorld()->GetFirstPlayerController();
            if (PC)
            {
                FInputModeUIOnly InputMode;
                InputMode.SetWidgetToFocus(ActiveWidget->TakeWidget());
                InputMode.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
                PC->SetInputMode(InputMode);
                PC->bShowMouseCursor = true;
            }

            UDialpadWidget* Dialpad = Cast<UDialpadWidget>(ActiveWidget);
            if (Dialpad)
            {
                Dialpad->LinkedPhone = this;
            }
        }
    }
    
}

void ADialpad::SubmitCode(const FString& EnteredCode)
{
    if (EnteredCode == CorrectCode)
    {
        UE_LOG(LogTemp, Warning, TEXT("Correct code entered! Opening gate."));
        if (GateActor)
        {
            UStaticMeshComponent* GateMesh = GateActor->FindComponentByClass<UStaticMeshComponent>();
            if (GateMesh)
            {
                FVector NewLocation = GateMesh->GetComponentLocation() + FVector(0.f, 0.f, 600.f);
                GateMesh->SetWorldLocation(NewLocation);
            }
        }

    }
    else
    {
        UE_LOG(LogTemp, Warning, TEXT("Incorrect code."));
    }

    if (ActiveWidget)
    {
        ActiveWidget->RemoveFromParent();
        APlayerController* PC = GetWorld()->GetFirstPlayerController();
        if (PC)
        {
            FInputModeGameOnly InputMode;
            PC->SetInputMode(InputMode);
            PC->bShowMouseCursor = false;
        }
        ActiveWidget = nullptr;
    }
}