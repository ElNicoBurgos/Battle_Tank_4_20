// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "Engine/World.h"
#include "GameFramework/PlayerController.h"
#define OUT



void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	if (GetControlledTank() != nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("AIController: %s"), *(GetControlledTank()->GetName()));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AIController not possesing a tank"));
	}

	if (GetControlledTank() != nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("AI actor find an enemy: %s"), *(GetPlayerTank()->GetName()));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AIController doesn't find an enemy"));
	}
}


void ATankAIController::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	if (GetControlledTank() == nullptr)
	{
		return;
	}
	else
	{
		GetControlledTank()->AimAt(GetPlayerTank()->GetActorLocation());
	}

}

ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

ATank * ATankAIController::GetPlayerTank() const
{

	if (!(GetWorld()->GetFirstPlayerController()->GetPawn()))
	{
		return nullptr;
		
	}
	else
	{
		return Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
	}
}




