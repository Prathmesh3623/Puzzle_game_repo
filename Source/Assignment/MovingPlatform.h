// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/BoxComponent.h"
#include "MovingPlatform.generated.h"

UCLASS()
class ASSIGNMENT_API AMovingPlatform : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMovingPlatform();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	// Called externally to activate/deactivate movement
	void SetPlatformActive(bool bActive);

private:

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* PlatformMesh;

	UPROPERTY(VisibleAnywhere)
	UBoxComponent* BoxCollision;

	FVector StartLocation;
	FVector TargetLocation;

	UPROPERTY(EditAnywhere, Category = "Platform")
	FVector MovementOffset = FVector(500.f, 0.f, 0.f);

	UPROPERTY(EditAnywhere, Category = "Platform")
	float MovementSpeed = 200.f;

	bool bMovingToTarget = true;
	bool bIsActive = false;

};
