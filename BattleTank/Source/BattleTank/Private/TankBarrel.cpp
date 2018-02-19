// Fill out your copyright notice in the Description page of Project Settings.

#include "TankBarrel.h"
#include "Engine/World.h"

void UTankBarrel::Elevate(float relativeSpeed) {

	relativeSpeed = FMath::Clamp<float>(relativeSpeed, -1.0f, 1.0f);
	float elevationChange = relativeSpeed * maxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	float newElevation = RelativeRotation.Pitch + elevationChange;
	newElevation = FMath::Clamp<float>(newElevation, minElevation, maxElevation);

	SetRelativeRotation(FRotator(newElevation, 0, 0));
}
