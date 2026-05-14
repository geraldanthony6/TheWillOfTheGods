// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/TextBlock.h"
#include "PlayerWorldHUD.generated.h"

/**
 * 
 */
UCLASS()
class WILLOFTHEGODS_API UPlayerWorldHUD : public UUserWidget
{
	GENERATED_BODY()
	
public:
	UFUNCTION()
	void SetNodeInformation(FText NodeName, FText NodeDescription);
	
protected:
	virtual void NativeConstruct() override;
	
	UPROPERTY(meta = (BindWidgetOptional))
	TObjectPtr<UTextBlock> NodeNameText;
	
	UPROPERTY(meta = (BindWidgetOptional))
	TObjectPtr<UTextBlock> NodeDescriptionText;
	
	
};
