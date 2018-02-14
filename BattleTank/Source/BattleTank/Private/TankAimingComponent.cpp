// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAimingComponent.h"
#include "TankBarrel.h"
#include "Kismet/GameplayStatics.h"


// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


void UTankAimingComponent::AimAt(FVector aimLocation, float projectileLaunchSpeed)
{
	if (!barrel) { return; }
	FVector projectileLaunchVelocity;
	FVector startLocation = barrel->GetSocketLocation(FName("barrelTip"));
	if (UGameplayStatics::SuggestProjectileVelocity(
		this,
		projectileLaunchVelocity,
		startLocation,
		aimLocation,
		projectileLaunchSpeed,
		ESuggestProjVelocityTraceOption::DoNotTrace)) {

		FVector aimdirection = projectileLaunchVelocity.GetSafeNormal();
		MoveBarrelTowards(aimdirection);
	}
}

void UTankAimingComponent::MoveBarrelTowards(FVector aimDirection)
{
	FRotator barrelRotator = barrel->GetForwardVector().Rotation();
	FRotator aimDirectionRotator = aimDirection.Rotation();
	FRotator deltaRotation = aimDirectionRotator - barrelRotator;
	barrel->Elevate(5);
}

void UTankAimingComponent::SetBarrelReference(UTankBarrel * barrelToSet)
{

	barrel = barrelToSet;
}