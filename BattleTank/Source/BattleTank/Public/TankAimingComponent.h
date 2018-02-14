// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "TankAimingComponent.generated.h"

class UTankBarrel;

UCLASS( ClassGroup=(Custom), meta=( ) )
class BATTLETANK_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTankAimingComponent();

	void AimAt(FVector aimLocation, float projectileLaunchSpeed);

	void SetBarrelReference(UTankBarrel* barrelToSet);

private:
	UTankBarrel* barrel = nullptr;

	void MoveBarrelTowards(FVector aimDirection);
};
