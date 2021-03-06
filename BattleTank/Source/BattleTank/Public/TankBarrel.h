// Copyright EmbraceIT Ltd.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "Engine/World.h"
#include "TankBarrel.generated.h"

UCLASS( ClassGroup = (Custom), meta = (BlueprintSpawnableComponent), hidecategories = ("Collision"))
class BATTLETANK_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()

public:
	// -1 is max downward speed, and +1 is max up movement
	void Elevate(float BarrelRelativeSpeed);

private:
	UPROPERTY(EditDefaultsOnly, Category = "BarrelSetup")
		float MaxDegreesPerSecond = 10;
	UPROPERTY(EditDefaultsOnly, Category = "BarrelSetup")
		float MaxElevationDegrees = 40;
	UPROPERTY(EditDefaultsOnly, Category = "BarrelSetup")
		float MinimumElevationDegrees = 0;
};

