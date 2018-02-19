// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include <Engine/World.h>
#include "Tank.h"


void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	GetcontrolledTank()->AimAt(GetPlayerTank()->GetActorLocation());
}

ATank* ATankAIController::GetcontrolledTank() const
{
	return Cast<ATank>(GetPawn());
}

ATank* ATankAIController::GetPlayerTank() const
{
	return Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
}
