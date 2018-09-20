// Fill out your copyright notice in the Description page of Project Settings.

#include "Car.h"
#include "CarBody.h"
#include "Runtime/Engine/Public/DrawDebugHelpers.h"

// Sets default values
ACar::ACar()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACar::BeginPlay()
{
	Super::BeginPlay();
}

void ACar::SetBodyReference(UCarBody* Body)
{
	CarBody = Body;
}

// Called every frame
void ACar::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	if (CarBody)
	{
		DrawDebugLine(GetWorld(),GetActorLocation()+FVector(0,0,50),GetActorLocation()+GetActorRotation().Vector()*500+FVector(0,0,50),FColor(255,0,0,255),false);
		DrawDebugLine(GetWorld(),GetActorLocation()+FVector(0,0,50),GetActorLocation()+(GetActorRotation()+FRotator(0,45,0)).Vector()*200+FVector(0,0,50),FColor(255,0,0,255),false);
		DrawDebugLine(GetWorld(),GetActorLocation()+FVector(0,0,50),GetActorLocation()+(GetActorRotation()+FRotator(0,-45,0)).Vector()*200+FVector(0,0,50),FColor(255,0,0,255),false);
		CarBody->DriveCar();
	}
}

// Called to bind functionality to input
void ACar::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

