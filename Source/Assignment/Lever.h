// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/SphereComponent.h"
#include "Interact_interface.h"
#include "Lever.generated.h"

UCLASS()
class ASSIGNMENT_API ALever : public AActor, public IInteract_interface
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ALever();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
public:
	UPROPERTY(VisibleAnywhere)
	USphereComponent* InteractionSphere;

	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* Mesh;

	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* HandleMesh;

	UFUNCTION()
	void ToggleLever();

	bool bPlayerInRange = false;
	UFUNCTION()
	void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
		UPrimitiveComponent* OtherComp, int32 OtherBodyIndex,
		bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	void OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
		UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
public:
	virtual void Interact_Implementation(AActor* Interactor) override;

private:
	UPROPERTY(EditAnywhere, Category = "Lever")
	TArray<AActor*> ControlledPlatforms;

	bool bIsOn = false;
	
};
