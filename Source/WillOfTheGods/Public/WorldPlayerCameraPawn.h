// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InputAction.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/Pawn.h"
#include "GameFramework/SpringArmComponent.h"
#include "WorldPlayerCameraPawn.generated.h"

UCLASS()
class WILLOFTHEGODS_API AWorldPlayerCameraPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AWorldPlayerCameraPawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<USpringArmComponent> CameraBoom;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<UCameraComponent> WorldPlayerCameraComponent;
	
	UPROPERTY(EditAnywhere)
	TObjectPtr<UInputAction> ForwardBackwardAction;
	
	UPROPERTY(EditAnywhere)
	TObjectPtr<UInputAction> LeftRightAction;
	
	UPROPERTY(EditAnywhere)
	TObjectPtr<UInputAction> UpDownAction;
	
	UFUNCTION()
	void OnMoveAction(const FInputActionValue& Value);
	
	UFUNCTION()
	void OnLeftRight();
	
	UFUNCTION()
	void OnUpDown();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
