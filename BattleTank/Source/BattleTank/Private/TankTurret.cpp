// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTurret.h"
#include "Engine/World.h"

void UTankTurret::Rotate(float relativeSpeed) {
	relativeSpeed = FMath::Clamp<float>(relativeSpeed, -1.0f, 1.0f);
	float yawChange = relativeSpeed * maxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	float newYaw = RelativeRotation.Yaw + yawChange;
	SetRelativeRotation(FRotator(0, newYaw, 0));
	//AddRelativeRotation(FRotator(RelativeRotation.Pitch, 0, 0));
}


