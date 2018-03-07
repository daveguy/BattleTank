// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTreads.h"
#include "Engine/World.h"

void UTankTreads::SetThrottle(float throttle)
{
	FVector forceApplied = GetForwardVector() * throttle * TreadMaxDrivingForce;
	FVector forceLocation = GetComponentLocation();
	UPrimitiveComponent* rootComponent = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());
	rootComponent->AddForceAtLocation(forceApplied, forceLocation);
}


