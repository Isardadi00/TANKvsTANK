// Copyright EmbraceIT Ltd.

#include "../Public/TankTurret.h"
#include "BattleTank.h"

void UTankTurret::Rotate(float RelativeSpeed)
{
	RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1, +1);
	auto RotationChange = RelativeSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	auto NewRotation = RelativeRotation.Yaw + RotationChange;
	SetRelativeRotation(FRotator(0, NewRotation, 0));
}




