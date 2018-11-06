// Fill out your copyright notice in the Description page of Project Settings.

#include "../Public/TankAIController.h"


void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	auto PlayerTank = GetPlayerTank();
	if (!PlayerTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("AI can�t find player Tank"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("�IController found player: %s"), *(PlayerTank->GetName()));
	}

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

