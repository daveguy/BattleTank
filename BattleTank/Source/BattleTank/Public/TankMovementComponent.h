// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/NavMovementComponent.h"
#include "TankMovementComponent.generated.h"

class UTankTreads;
/**
 * 
 */
UCLASS( ClassGroup = (Custom), meta = (BlueprintSpawnableComponent) )
class BATTLETANK_API UTankMovementComponent : public UNavMovementComponent
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable, category = Setup)
	void Initialize(UTankTreads* leftTreadToSet, UTankTreads* rightTreadToSet);

	UFUNCTION(BlueprintCallable, category = Input)
	void IntendMoveForward(float val);
	
private:
	UTankTreads* leftTread = nullptr;
	UTankTreads* rightTread = nullptr;
};