// Fill out your copyright notice in the Description page of Project Settings.

#include "../Public/TankPlayerController.h"

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();

	auto ControlledTank = GetControlledTank();
	if (!ControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("PlayerController Not Possessing a Tank"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("PlayerController possessing %s"), *(ControlledTank->GetName()));
	}

}

void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick( DeltaTime );
	AimTowardsCrosshair();
}

ATank * ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::AimTowardsCrosshair()
{
	if (!GetControlledTank())
	{return;}

	FVector HitLocation; // Out parameter
	if (GetSightRayHitLocation(HitLocation))
	{
		GetControlledTank() -> AimAt(HitLocation);
	}
}

// Get world location of linetrace through crosshair, true if it hits the landscape
bool ATankPlayerController::GetSightRayHitLocation(FVector&	 HitLocation) const
{
	// Find the crosshair position in pixel coordinates
	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize(ViewportSizeX, ViewportSizeY);
	auto ScreenLocation = FVector2D(ViewportSizeX * CrossHairXLocation, ViewportSizeY * CrossHairYLocation);

	// De-project screen position of the crosshair to a world direction
	FVector LookDirection;
	if (GetLookDirection(ScreenLocation, LookDirection))
	{
		// Line-trace along that look direction, and see what we hit (up to max range)
		GetLookVectorHitLocation(LookDirection, HitLocation);
	}

	
	return true;
}


bool ATankPlayerController::GetLookVectorHitLocation(FVector LookDirection, FVector& HitLocation) const
{
	FHitResult HitResult;
	auto StartLocation = PlayerCameraManager->GetCameraLocation();
	auto EndLocation = StartLocation + (LookDirection * LineTraceRange);
	if (GetWorld()->LineTraceSingleByChannel(
			HitResult,
			StartLocation,
			EndLocation,
			ECollisionChannel::ECC_Visibility))
	{
		HitLocation = HitResult.Location;
		return true;
	}
	HitLocation = FVector(0);
	return false; // linetrace didn�t work
}

bool ATankPlayerController::GetLookDirection(FVector2D& ScreenLocation, FVector& LookDirection) const
{
	FVector CameraWorldLocation; // For Discarding
	return DeprojectScreenPositionToWorld(
		ScreenLocation.X, 
		ScreenLocation.Y, 
		CameraWorldLocation, 
		LookDirection);
}
