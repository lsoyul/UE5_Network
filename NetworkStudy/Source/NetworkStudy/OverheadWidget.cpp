// Fill out your copyright notice in the Description page of Project Settings.


#include "OverheadWidget.h"
#include "Components/TextBlock.h"

void UOverheadWidget::SetDisplayText(FString Text)
{
	if (DisplayText)
	{
		DisplayText->SetText(FText::FromString(Text));
	}
}

void UOverheadWidget::ShowPlayerNetRole(APawn* Pawn)
{
	ENetRole LocalRole = Pawn->GetLocalRole();

	FString LocalRoleStr;
	switch (LocalRole)
	{
	case ENetRole::ROLE_Authority:
		LocalRoleStr = TEXT("Authority");
		break;
	case ENetRole::ROLE_AutonomousProxy:
		LocalRoleStr = TEXT("AutonomousProxy");
		break;
	case ENetRole::ROLE_SimulatedProxy:
		LocalRoleStr = TEXT("SimulatedProxy");
		break;
	}

	ENetRole RemoteRole = Pawn->GetRemoteRole();

	FString RemoteRoleStr;
	switch (RemoteRole)
	{
	case ENetRole::ROLE_Authority:
		RemoteRoleStr = TEXT("Authority");
		break;
	case ENetRole::ROLE_AutonomousProxy:
		RemoteRoleStr = TEXT("AutonomousProxy");
		break;
	case ENetRole::ROLE_SimulatedProxy:
		RemoteRoleStr = TEXT("SimulatedProxy");
		break;
	}

	FString ResultString = FString::Printf(TEXT("Local : %s\nRemote : %s"), *LocalRoleStr, *RemoteRoleStr);
	SetDisplayText(ResultString);
}
