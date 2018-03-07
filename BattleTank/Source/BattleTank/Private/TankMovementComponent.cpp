// Fill out your copyright notice in the Description page of Project Settings.

#include"TankMovementComponent.h"
#include "TankTreads.h"

void UTankMovementComponent::Initialize(UTankTreads* leftTreadToSet, UTankTreads* rightTreadToSet)
{
	leftTread = leftTreadToSet;
	rightTread = rightTreadToSet;
}

void UTankMovementComponent::IntendMoveForward(float val)
{
	if (!leftTread || !rightTread) { return; }
	//UE_LOG(LogTemp, Warning, TEXT("Intend move forward: %f"), val);
	leftTread->SetThrottle(val);
	rightTread->SetThrottle(val);
}


