// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerWorldHUD.h"

void UPlayerWorldHUD::NativeConstruct()
{
	Super::NativeConstruct();
	
	NodeNameText->SetVisibility(ESlateVisibility::Hidden);
	NodeDescriptionText->SetVisibility(ESlateVisibility::Hidden);
}

void UPlayerWorldHUD::SetNodeInformation(FText NodeName, FText NodeDescription)
{
	NodeNameText->SetVisibility(ESlateVisibility::Visible);
	NodeDescriptionText->SetVisibility(ESlateVisibility::Visible);
	NodeNameText->SetText(NodeName);
	NodeDescriptionText->SetText(NodeDescription);
}


