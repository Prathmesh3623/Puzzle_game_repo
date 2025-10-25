// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/SphereComponent.h"
#include "Interact_interface.h" 
#include "Dialpad.generated.h"

UCLASS()
class ASSIGNMENT_API ADialpad : public AActor, public IInteract_interface

{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADialpad();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	UPROPERTY(EditAnywhere)
	AActor* GateActor;

	UPROPERTY(VisibleAnywhere)
	USphereComponent* InteractionSphere;

	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* PhoneMesh;
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	virtual void Interact_Implementation(AActor* Interactor) override;

	UPROPERTY(EditAnywhere)
	FString CorrectCode = "100";

	void SubmitCode(const FString& EnteredCode);

	UPROPERTY(EditAnywhere)
	TSubclassOf<UUserWidget> DialpadWidgetClass;

	UUserWidget* ActiveWidget;


};
