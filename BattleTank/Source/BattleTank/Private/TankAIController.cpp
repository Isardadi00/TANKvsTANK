// Fill out your copyright notice in the Description page of Project Settings.

#include "../Public/TankAIController.h"
#include "../Public/Tank.h"
#include "BattleTank.h"


void ATankAIController::BeginPlay()
{	
	Super::BeginPlay();

}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	auto PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
	auto AITank = Cast<ATank>(GetPawn());
	if (PlayerTank)
	{
		// Move towards the player
		MoveToActor(PlayerTank, AcceptanceRadius); // TODO check raidus is in cnetimeters

		// Aim towards the player
		AITank->AimAt(PlayerTank->GetActorLocation());

		AITank->Fire(); // TODO limit firing frame
	}
	
}

