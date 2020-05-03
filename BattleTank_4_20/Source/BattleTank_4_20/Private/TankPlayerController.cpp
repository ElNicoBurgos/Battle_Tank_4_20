// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"
#include "Engine/World.h"
#define OUT


void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();
	if (GetControlledTank() != nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("PlayerController: %s"), *(GetControlledTank()->GetName()));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("PlayerController not possesing a tank"));
	}
	
}


void ATankPlayerController::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	AimTowardsCrosshair();
}

ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::AimTowardsCrosshair()
{
	if (!GetControlledTank())
	{
		return;
	}

	FVector HitLocation;

	if(GetSightRayHitLocacion(HitLocation))
	{
		//UE_LOG(LogTemp, Warning, TEXT("Hit Location: %s"), *(HitLocation.ToString()));
	}
}

bool ATankPlayerController::GetSightRayHitLocacion(FVector& OutHitLocation) const
{
	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize(ViewportSizeX, ViewportSizeY);

	FVector2D ScreenLocation = FVector2D(ViewportSizeX * CrosshairXLocation, ViewportSizeY * CrosshairYLocation);

	UE_LOG(LogTemp, Warning, TEXT("ScreenLocation: %s"), *(ScreenLocation.ToString()));

	return true;
}
