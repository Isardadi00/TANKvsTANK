// Fill out your copyright notice in the Description page of Project Settings.

#include "../Public/TankAIController.h"
#include "Tank.h"
#include "BattleTank.h"


void ATankAIController::BeginPlay()
{	
	Super::BeginPlay();

	auto PlayerTank = GetPlayerTank();
	if (!PlayerTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("AI can´t find player Tank"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AIController found player: %s"), *(PlayerTank->GetName()));
	}

}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (GetPlayerTank())
	{
		// TODO move towards the player

		// Aim towards the player
		GetControlledTank()->AimAt(GetPlayerTank()->GetActorLocation());

		// fire if ready
	}
	
}

ATank * ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

ATank * ATankAIController::GetPlayerTank() const
{
	auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (!PlayerPawn){return nullptr;}
	return Cast<ATank>(PlayerPawn);
}

ATank * ATankAIController::GetAITank() const
{
	return Cast<ATank>(GetPawn());
}

