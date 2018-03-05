// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"


UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	//-1 is max downward, +1 is max upward
	void Elevate(float relativeSpeed);

private:
	UPROPERTY(EditDefaultsOnly, Category = Setup)
	float maxDegreesPerSecond = 10;

	UPROPERTY(EditDefaultsOnly, Category = Setup)
	float maxElevation = 35;

	UPROPERTY(EditDefaultsOnly, Category = Setup)
	float minElevation = 0;
};
