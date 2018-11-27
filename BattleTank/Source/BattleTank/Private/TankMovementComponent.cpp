// Fill out your copyright notice in the Description page of Project Settings.

#include "../Public/TankMovementComponent.h"
#include "../Public/TankTrack.h"
#include "BattleTank.h"

void UTankMovementComponent::Initialise(UTankTrack * LeftTrackToSet, UTankTrack * RightTrackToSet)
{
	if (!LeftTrackToSet || !RightTrackToSet) { return; }
	LeftTrack = LeftTrackToSet;
	RightTrack = RightTrackToSet;
}

void UTankMovementComponent::IntendMoveForward(float Throw)
{
	if (!LeftTrack || !RightTrack) { return; }
	LeftTrack->SetThrottle(Throw);
	RightTrack->SetThrottle(Throw);

	//TODO prevent double speed due to dual control use
}

void UTankMovementComponent::IntendTurnRight(float Throw)
{
	if (!LeftTrack || !RightTrack) { return; }
	LeftTrack->SetThrottle(-Throw);
	RightTrack->SetThrottle(Throw);

	//TODO prevent double speed due to dual control use
}

void UTankMovementComponent::IntendTurnLeft(float Throw)
{
	LeftTrack->SetThrottle(Throw);
	RightTrack->SetThrottle(-Throw);

	//TODO prevent double speed due to dual control use
}
