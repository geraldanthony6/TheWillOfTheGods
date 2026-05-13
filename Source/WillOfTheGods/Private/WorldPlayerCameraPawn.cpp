// Fill out your copyright notice in the Description page of Project Settings.


#include "Public/WorldPlayerCameraPawn.h"

#include "EnhancedInputComponent.h"

// Sets default values
AWorldPlayerCameraPawn::AWorldPlayerCameraPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(FName("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	
	WorldPlayerCameraComponent = CreateDefaultSubobject<UCameraComponent>(FName("WorldPlayerCamera"));
	WorldPlayerCameraComponent->SetupAttachment(CameraBoom);
	
}

// Called when the game starts or when spawned
void AWorldPlayerCameraPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

void AWorldPlayerCameraPawn::OnMoveAction(const FInputActionValue& Value)
{
	FVector InputVector = Value.Get<FVector>();
	GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Blue, FString::Printf(TEXT("X: %f Y: %f Z: %f"), InputVector.X, InputVector.Y, InputVector.Z));
	if (InputVector.X > 0.0f)
	{
		FVector ActorLocation = GetActorLocation();
		SetActorLocation(ActorLocation + (GetActorForwardVector() * 100.0f));	
	} else if (InputVector.X < 0.0f)
	{
		FVector ActorLocation = GetActorLocation();
		SetActorLocation(ActorLocation + (GetActorForwardVector() * -100.0f));	
	}
	
	if (InputVector.Y > 0.0f)
	{
		FVector ActorLocation = GetActorLocation();
		SetActorLocation(ActorLocation + (GetActorRightVector() * 100.0f));	
	} else if (InputVector.Y < 0.0f)
	{
		FVector ActorLocation = GetActorLocation();
		SetActorLocation(ActorLocation + (GetActorRightVector() * -100.0f));	
	}

	if (InputVector.Z > 0.0f)
	{
		FVector ActorLocation = GetActorLocation();
		SetActorLocation(ActorLocation + (GetActorUpVector() * 100.0f));	
	} else if (InputVector.Z < 0.0f)
	{
		FVector ActorLocation = GetActorLocation();
		SetActorLocation(ActorLocation + (GetActorUpVector() * -100.0f));	
	}

}

void AWorldPlayerCameraPawn::OnLookAction(const FInputActionValue& Value)
{
	FVector2D LookAxisVector = Value.Get<FVector2D>();
	GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Blue, FString::Printf(TEXT("X: %f Y: %f"), LookAxisVector.X, LookAxisVector.Y));
	AddControllerYawInput(LookAxisVector.X);
	AddControllerPitchInput(LookAxisVector.Y * -1.0f);
}

// Called every frame
void AWorldPlayerCameraPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AWorldPlayerCameraPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(InputComponent))
	{
		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AWorldPlayerCameraPawn::OnMoveAction);
		EnhancedInputComponent->BindAction(LookAction, ETriggerEvent::Triggered, this, &AWorldPlayerCameraPawn::OnLookAction);
	}
	
}

