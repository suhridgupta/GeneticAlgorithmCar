// Fill out your copyright notice in the Description page of Project Settings.

#include "CarBody.h"

void UCarBody::SetThrottle(float Throttle)
{
	CurrentThrottle = Throttle;
}

void UCarBody::SetTurn(float Rotation)
{
	CurrentRotation = Rotation;
}

void UCarBody::DriveCar() {
	FVector ForceApplied = GetForwardVector() * MaxForce * CurrentThrottle;

	//USceneComponent is cast to UPrimitiveComponent to allow collisions to occur
	TankRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());

	//Middle of the track is where the force is applied, but AddForceAtLocation is done on entire tank (can be done just on track too)
	FVector ForceLocation = GetComponentLocation();

	FVector DistanceCovered = 0.5*(ForceApplied/TankRoot->GetMass())*GetWorld()->GetDeltaSeconds();
	FitnessValue += (FMath::Abs(DistanceCovered.Size()))/100.0f; //Scale down to avoid floating point issues

	UE_LOG(LogTemp,Warning,TEXT("FitnessValue: %f"),FitnessValue)

	TankRoot->AddForceAtLocation(ForceApplied, ForceLocation);

	FRotator Rotator = FRotator(0.0f, CurrentRotation, 0.0f);
	TankRoot->AddLocalRotation(FQuat(Rotator));

}


