// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"
#include <Engine/World.h>

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();
}

void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AimTowardsCrosshair();
}

ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::AimTowardsCrosshair()
{
	ATank* tank = GetControlledTank();
	if (!tank) { return; }
	FVector hitLocation;
	if (GetSightRayHitLocation(hitLocation))
	{
		UE_LOG(LogTemp, Warning, TEXT("Hit Direction: %s"), *hitLocation.ToString());
		//TODO rotate tanks bits
	}
}

bool ATankPlayerController::GetSightRayHitLocation(FVector & outHitLocation) const
{
	return GetLookDirection(outHitLocation);
}

bool ATankPlayerController::GetLookDirection(FVector & outLookDirection) const
{
	int32 viewportSizeX, viewportSizeY;
	GetViewportSize(viewportSizeX, viewportSizeY);
	FVector2D screenLocation(viewportSizeX * crosshairXLocation, viewportSizeY * crosshairYLocation);
	FVector cameraWorldLocation;
	return DeprojectScreenPositionToWorld(screenLocation.X, screenLocation.Y, cameraWorldLocation, outLookDirection);
}




