// Fill out your copyright notice in the Description page of Project Settings.

#include "Tank.h"
#include "TankAimingComponent.h"
#include "TankTurret.h"
#include "Projectile.h"
#include "TankBarrel.h"
#include "Engine/World.h"


// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	tankAimingComponent = CreateDefaultSubobject<UTankAimingComponent>(FName("Aiming Component"));
}

// Called when the game starts or when spawned
void ATank::BeginPlay()
{
	Super::BeginPlay();
	
}

void ATank::Tick(float DeltaTime)
{
	timeSinceFiring += DeltaTime;
}
void ATank::AimAt(FVector AimLocation)
{
	tankAimingComponent->AimAt(AimLocation, projectileLaunchSpeed);
}

void ATank::SetBarrelReference(UTankBarrel * barrelToSet)
{
	tankAimingComponent->SetBarrelReference(barrelToSet);
	barrel = barrelToSet;
}

void ATank::SetTurretReference(UTankTurret* turretToSet)
{
	tankAimingComponent->SetTurretReference(turretToSet);
}

void ATank::Fire()
{
	if (barrel && timeSinceFiring > reloadSpeed)
	{
		//spawn projectile at socket on barrel
		AProjectile* projectile = GetWorld()->SpawnActor<AProjectile>(
			projectileBlueprint,
			barrel->GetSocketLocation(FName("barrelTip")),
			barrel->GetSocketRotation(FName("barrelTip")));
		projectile->LaunchProjectile(projectileLaunchSpeed);

		timeSinceFiring = 0.0f;
	}
}



// Called to bind functionality to input
void ATank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

