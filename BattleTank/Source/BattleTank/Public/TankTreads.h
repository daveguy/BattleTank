// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankTreads.generated.h"

/**
 * 
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankTreads : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	//sets throttle between -1 and +1
	UFUNCTION(BlueprintCallable)
	void SetThrottle(float throttle);
	
	//Max force per tread in newtons
	UPROPERTY(EditDefaultsOnly)
	float TreadMaxDrivingForce = 400000;
	
};
