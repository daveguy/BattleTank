// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"
#include "Tank.h"
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
	if (!GetSightRayHitLocation(hitLocation))
	{
		hitLocation = FVector(0, 0, 0);
	}
	GetControlledTank()->AimAt(hitLocation);
}

bool ATankPlayerController::GetSightRayHitLocation(FVector & outHitLocation) const
{
	FVector lookDirection;
	FVector cameraWorldLocation;
	if (GetLookDirection(lookDirection, cameraWorldLocation))
	{
		FHitResult hitResult;
		if (GetWorld()->LineTraceSingleByChannel(
			hitResult, 
			cameraWorldLocation, 
			cameraWorldLocation + lookDirection * lineTraceRange,
			ECC_Visibility,
			FCollisionQueryParams(FName(TEXT("")), false, GetControlledTank()))
		){
			outHitLocation = hitResult.Location;
			return true;
		}
	}
	return false;
}

bool ATankPlayerController::GetLookDirection(FVector & outLookDirection, FVector& outCameraWorldLocation) const
{
	int32 viewportSizeX, viewportSizeY;
	GetViewportSize(viewportSizeX, viewportSizeY);
	FVector2D screenLocation(viewportSizeX * crosshairXLocation, viewportSizeY * crosshairYLocation);
	FVector cameraWorldLocation;
	return DeprojectScreenPositionToWorld(screenLocation.X, screenLocation.Y, outCameraWorldLocation, outLookDirection);
}




