// Fill out your copyright notice in the Description page of Project Settings.

#include "Car.h"
#include "FinishLine.h"
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
	//GetOwner()->EndRace.AddUniqueDynamic(this,&ACar::DriveFinished);
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
		CarBody->CurrentThrottle = 1.0f;
		if(GetFirstPhysicsBodyInReach(45.0f))
		{
			//TODO Logic For Turning Left
			CarBody->CurrentRotation = -1.0f;
			//UE_LOG(LogTemp,Warning,TEXT("Turn Left"))
			DrawDebugLine(GetWorld(),GetReachLineStart(),GetReachLineEnd(45),FColor(0,255,0,255),false);
			DrawDebugLine(GetWorld(),GetReachLineStart(),GetReachLineEnd(-45),FColor(255,0,0,255),false);
		}
		else if(GetFirstPhysicsBodyInReach(-45.0f))
		{
			//TODO Logic For Turning Right
			CarBody->CurrentRotation = 1.0f;
			//UE_LOG(LogTemp,Warning,TEXT("Turn Right"))
			DrawDebugLine(GetWorld(),GetReachLineStart(),GetReachLineEnd(45),FColor(255,0,0,255),false);
			DrawDebugLine(GetWorld(),GetReachLineStart(),GetReachLineEnd(-45),FColor(0,255,0,255),false);
		}
		else
		{
			//This Lady's NOT For Turning
			DrawDebugLine(GetWorld(),GetReachLineStart(),GetReachLineEnd(45),FColor(255,0,0,255),false);
			DrawDebugLine(GetWorld(),GetReachLineStart(),GetReachLineEnd(-45),FColor(255,0,0,255),false);
		}
		CarBody->DriveCar();
		CarBody->CurrentRotation = 0.0f;

		if(RaceFinished)
		{
			DriveFinished();
		}
	}
}

// Called to bind functionality to input
void ACar::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

bool ACar::GetFirstPhysicsBodyInReach(float LineAngle)
{
	FHitResult Hit;
	FCollisionQueryParams TraceParameters(FName(TEXT("")), false, GetOwner());
	//Get Line Trace(Ray-Cast) Till Reach Distance
	GetWorld()->LineTraceSingleByObjectType(
		OUT Hit,
		GetReachLineStart(),
		GetReachLineEnd(LineAngle),
		FCollisionObjectQueryParams(ECollisionChannel::ECC_WorldStatic),
		TraceParameters
	);
	AActor *ActorHit = Hit.GetActor();
	//Only Log if ActorHit is NOT a nullptr. UE4 Will Crash Otherwise
	if (ActorHit)
	{
		//UE_LOG(LogTemp, Warning, TEXT("Collision WIth %s"), *(ActorHit->GetName()))
		return true;
	}
	return false;
}

FVector ACar::GetReachLineStart()
{
	return GetActorLocation()+FVector(0,0,50);
}

FVector ACar::GetReachLineEnd(float LineAngle)
{
	return GetActorLocation()+(GetActorRotation()+FRotator(0,LineAngle,0)).Vector()*350+FVector(0,0,50);
}

void ACar::DriveFinished()
{
	UE_LOG(LogTemp,Warning,TEXT("Reached Finish Line"))
	RaceFinished = false;
}