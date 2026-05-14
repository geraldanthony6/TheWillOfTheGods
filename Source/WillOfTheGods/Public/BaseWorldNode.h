// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PlayerWorldPawn.h"
#include "GameFramework/Actor.h"
#include "BaseWorldNode.generated.h"

UCLASS()
class WILLOFTHEGODS_API ABaseWorldNode : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABaseWorldNode();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Variables
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TObjectPtr<UStaticMeshComponent> NodeMesh;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	bool bIsPlayerOnNode;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Player References")
	TObjectPtr<APlayerWorldPawn> PlayerWorldPawn;
	
	// Functions
	UFUNCTION()
	void OnClicked(UPrimitiveComponent* TouchedActor, FKey ButtonPressed);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
