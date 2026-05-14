// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseWorldNode.h"

// Sets default values
ABaseWorldNode::ABaseWorldNode()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	NodeMesh = CreateDefaultSubobject<UStaticMeshComponent>("NodeMesh");
	NodeMesh->SetupAttachment(RootComponent);
	NodeMesh->OnClicked.AddDynamic(this, &ABaseWorldNode::OnClicked);

}

// Called when the game starts or when spawned
void ABaseWorldNode::BeginPlay()
{
	Super::BeginPlay();
	
}

void ABaseWorldNode::OnClicked(UPrimitiveComponent* TouchedActor, FKey ButtonPressed)
{
	UE_LOG(LogTemp, Warning, TEXT("Clicked node"));
	
	PlayerWorldPawn->Move(GetActorLocation());
}

// Called every frame
void ABaseWorldNode::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

