// Fill out your copyright notice in the Description page of Project Settings.

#include"TankMovementComponent.h"
#include "TankTreads.h"
#include "Engine/World.h"

void UTankMovementComponent::Initialize(UTankTreads* leftTreadToSet, UTankTreads* rightTreadToSet)
{
	leftTread = leftTreadToSet;
	rightTread = rightTreadToSet;
}

void UTankMovementComponent::IntendMoveForward(float val)
{
	if (!leftTread || !rightTread) { return; }
	leftTread->SetThrottle(val);
	rightTread->SetThrottle(val);
}

void UTankMovementComponent::IntendTurnRight(float val)
{
	if (!leftTread || !rightTread) { return; }
	leftTread->SetThrottle(val);
	rightTread->SetThrottle(-val);
}


void UTankMovementComponent::RequestDirectMove(const FVector & MoveVelocity, bool bForceMaxSpeed)
{
	FVector tankForward = GetOwner()->GetActorForwardVector().GetSafeNormal();
	FVector AIForwardIntention = MoveVelocity.GetSafeNormal();
	
	IntendMoveForward(FVector::DotProduct(tankForward, AIForwardIntention));
	IntendTurnRight(FVector::CrossProduct(tankForward, AIForwardIntention).Z);

	//UE_LOG(LogTemp, Warning, TEXT("move velocity: %s"), *MoveVelocity.GetSafeNormal().ToString());
}
