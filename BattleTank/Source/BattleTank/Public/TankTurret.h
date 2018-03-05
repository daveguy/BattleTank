// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankTurret.generated.h"

/**
 * 
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankTurret : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	//-1 is max leftward, +1 is max rightward
	void Rotate(float relativeSpeed);

private:
	UPROPERTY(EditDefaultsOnly, Category = Setup)
		float maxDegreesPerSecond = 25;
};