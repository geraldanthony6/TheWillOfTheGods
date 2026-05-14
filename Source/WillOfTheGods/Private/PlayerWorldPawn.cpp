// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerWorldPawn.h"

#include "BaseAIController.h"
#include "AI/NavigationSystemBase.h"
#include "Blueprint/AIBlueprintHelperLibrary.h"
#include "Navigation/PathFollowingComponent.h"
#include "BaseWorldNode.h"

class UNavigationSystemV1;
// Sets default values
APlayerWorldPawn::APlayerWorldPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	SetRootComponent(Root);
	
	PlayerWorldPawnStaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PlayerWorldPawnStaticMeshComponent"));
	PlayerWorldPawnStaticMeshComponent->SetupAttachment(Root);
	
	PlayerMovementComponent = CreateDefaultSubobject<UFloatingPawnMovement>(TEXT("PlayerMovementComponent"));
	
	AutoPossessAI = EAutoPossessAI::PlacedInWorldOrSpawned;
	AIControllerClass = ABaseAIController::StaticClass();
}

void APlayerWorldPawn::Move(FVector TargetLocation)
{
	if (ABaseAIController* AIController = Cast<ABaseAIController>(GetController()))
	{
		UE_LOG(LogTemp, Warning, TEXT("Moving Player Controller"));
		DesiredLocation = TargetLocation;
		bPlayerMovementEnabled = true;
	}
}

void APlayerWorldPawn::SetupPlayerOnNewNode(ABaseWorldNode* NewNode)
{
	// Move to new node
	Move(NewNode->GetActorLocation());
	
	// Once we reach the new node display the information for that node in the HUD
	PlayerWorldHUD->SetNodeInformation(NewNode->GetNodeData().NodeName, NewNode->GetNodeData().NodeDescription);
}

// Called when the game starts or when spawned
void APlayerWorldPawn::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void APlayerWorldPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	if (bPlayerMovementEnabled)
	{	
		if (ABaseAIController* AIController = Cast<ABaseAIController>(GetController()))
		{
			AIController->MoveToLocation(DesiredLocation);
		}
	}
	
	if (bPlayerMovementEnabled && FVector::Dist(DesiredLocation, GetActorLocation()) < 50.0f)
	{
		bPlayerMovementEnabled = false;
		DesiredLocation = FVector::Zero();
	}
}

// Called to bind functionality to input
void APlayerWorldPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

