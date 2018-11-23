// Fill out your copyright notice in the Description page of Project Settings.

#include "../Public/TankTurret.h"
#include "BattleTank.h"

void Azimuth(float TurretRelativeSpeed)
{
	TurretRelativeSpeed = FMath::Clamp<float>(TurretRelativeSpeed, -1, +1);
}




