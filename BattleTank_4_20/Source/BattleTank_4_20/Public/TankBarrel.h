// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"

/**
 * 
 */
UCLASS(meta=(BlueprintSpawnableComponent), hidecategories = Collision)
class BATTLETANK_4_20_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()
	
	
public:
	void Elevate(float DegreePerSecond);

private:
	UPROPERTY(EditAnywhere, Category = Setup)
	float MaxDegreesPerSeconds = 20.f; 

	UPROPERTY(EditAnywhere, Category = Setup)
	float MaxElevationRotation = 40.f;

	UPROPERTY(EditAnywhere, Category = Setup)
	float MinElevationRotation = 0.f;


};
