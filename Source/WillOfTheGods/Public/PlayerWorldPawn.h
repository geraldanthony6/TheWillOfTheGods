// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "GameFramework/FloatingPawnMovement.h"
#include "GameFramework/Pawn.h"
#include "PlayerWorldPawn.generated.h"

UCLASS()
class WILLOFTHEGODS_API APlayerWorldPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	APlayerWorldPawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Variables
	UPROPERTY()
	TObjectPtr<USceneComponent> Root;
	
	UPROPERTY(EditAnywhere)
	TObjectPtr<UStaticMeshComponent> PlayerWorldPawnStaticMeshComponent;
	
	UPROPERTY(EditAnywhere)
	TObjectPtr<UFloatingPawnMovement> PlayerMovementComponent;
	
	UPROPERTY(EditAnywhere)
	bool bPlayerMovementEnabled;
	
	UPROPERTY(EditAnywhere)
	FVector DesiredLocation;
	

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION()
	void Move(FVector TargetLocation);
	
};
