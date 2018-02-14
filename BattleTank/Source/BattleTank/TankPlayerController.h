// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

//#include "Tank.h"
#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

class ATank;

UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
private:
	UPROPERTY(EditAnywhere)
	float crosshairXLocation = 0.5;
	UPROPERTY(EditAnywhere)
	float crosshairYLocation = 1.0 / 3;
	UPROPERTY(EditAnywhere)
	float lineTraceRange = 100 * 1000 * 10;

	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

	ATank* GetControlledTank() const;

	//start the tank moving the barrel towards the crosshair
	void AimTowardsCrosshair();
	
	bool GetSightRayHitLocation(FVector& outHitLocation) const;

	bool GetLookDirection(FVector& outLookDirection, FVector& outCameraWorldLocation) const;
};