// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SpotLightComponent.h"
#include "GameFramework/Actor.h"
#include "Interact_interface.h"
#include "ColourSwitch.h"
#include "Components/SphereComponent.h"
#include "Light_Switch.generated.h"

UCLASS()
class ASSIGNMENT_API ALight_Switch : public AActor, public IInteract_interface
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ALight_Switch();
public:
	virtual void Interact_Implementation(AActor* Interactor) override;

protected:
	UPROPERTY(VisibleAnywhere)
	USphereComponent* InteractionSphere;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UStaticMeshComponent* SwitchMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UStaticMeshComponent* HandleMesh;

	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	UPointLightComponent* RevealLight;

	UPROPERTY(EditAnywhere, Category = "Puzzle")
	TArray<AColourSwitch*> ControlledColorSwitches;


	bool bIsHandleRotated = false;


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
