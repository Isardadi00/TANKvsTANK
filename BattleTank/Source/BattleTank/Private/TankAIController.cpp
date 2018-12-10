// Copyright EmbraceIT Ltd.

#include "../Public/TankAIController.h"
#include "../Public/TankAimingComponent.h"
#include "Engine/World.h"
#include "BattleTank.h"
//Depends on movement component via pathfinding system

void ATankAIController::BeginPlay()
{	
	Super::BeginPlay();

}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	auto PlayerTank = GetWorld()->GetFirstPlayerController()->GetPawn();
	auto AITank = GetPawn();
	if (!ensure(PlayerTank && AITank)) { return; }
	{
		// Move towards the player
		MoveToActor(PlayerTank, AcceptanceRadius); // TODO check raidus is in cnetimeters

		// Aim towards the player
		auto AimingComponent = AITank->FindComponentByClass<UTankAimingComponent>();
		AimingComponent->AimAt(PlayerTank->GetActorLocation());

		if (AimingComponent->GetFiringState() == EFiringState::Locked)
		{
			AimingComponent->Fire();
		}	
	}
	
}

