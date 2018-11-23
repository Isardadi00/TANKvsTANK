// Fill out your copyright notice in the Description page of Project Settings.

#include "../Public/TankBarrel.h"
#include "BattleTank.h"


void UTankBarrel::Elevate(float BarrelRelativeSpeed)
{
	// Move the barrel the right amount this frame
	// Given a Max elevation speed, and the frame time
	BarrelRelativeSpeed = FMath::Clamp<float>(BarrelRelativeSpeed, -1, +1);
	auto ElevationChange = BarrelRelativeSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	auto RawNewElevation = RelativeRotation.Pitch + ElevationChange;
	auto Elevation = FMath::Clamp<float>(RawNewElevation, MinimumElevationDegrees, MaxElevationDegrees);
	SetRelativeRotation(FRotator(Elevation, 0, 0));
};