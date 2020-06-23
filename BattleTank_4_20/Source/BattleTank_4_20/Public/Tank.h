// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "TankAimingComponent.h" //Components
#include "Tank.generated.h"

class UTankBarrel;

UCLASS()
class BATTLETANK_4_20_API ATank : public APawn
{
	GENERATED_BODY()

public:
	
	void AimAt(FVector HitLocation);

	UFUNCTION(BlueprintCallable, Category = "Setup")
	void SetBarrelReference(UTankBarrel * BarrelToSet);

protected:
	
	UTankAimingComponent* TankAimingComponent = nullptr;

private:	

	ATank();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(Editanywhere, Category = "Firing")
	float LaunchSpeed = 10000.f;
	
};
