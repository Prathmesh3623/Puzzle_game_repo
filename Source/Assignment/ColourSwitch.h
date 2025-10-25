// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Interact_interface.h"
#include "Components/SphereComponent.h"
#include "ColourSwitch.generated.h"

class AColourValidator; // Forward declaration
UCLASS()
class ASSIGNMENT_API AColourSwitch : public AActor, public IInteract_interface
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AColourSwitch();


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;


    virtual void Interact_Implementation(AActor* Interactor) override;

    int32 GetCurrentColorIndex() const;

protected:
    virtual void BeginPlay() override;

    void UpdateColor();

    UPROPERTY(EditAnywhere)
    USphereComponent* InteractionZone;

    UPROPERTY(EditAnywhere)
    UStaticMeshComponent* Mesh;

    UPROPERTY(EditAnywhere)
    TArray<FLinearColor> ColorOptions;

    int32 CurrentColorIndex = 0;

    UMaterialInstanceDynamic* DynamicMat;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Puzzle")
    AColourValidator* Validator;
};
