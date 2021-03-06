// Fill out your copyright notice in the Description page of Project Settings.

#include "FinishLine.h"
#include "Car.h"

AFinishLine::AFinishLine()
{
}

void AFinishLine::BeginPlay()
{
	Super::BeginPlay();
    OnActorEndOverlap.AddDynamic(this,&AFinishLine::ReachedFinishLine);
    //UE_LOG(LogTemp,Warning,TEXT("Initialised Collision"))
    
}

void AFinishLine::ReachedFinishLine(class AActor* OverlappedActor, class AActor* OtherActor)
{
    if(OtherActor && OtherActor!=this)
    {
        ACar *Car = Cast<ACar>(OtherActor);
        Car->RaceFinished = true;
    }
}


