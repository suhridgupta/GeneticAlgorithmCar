// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/TriggerBox.h"
#include "FinishLine.generated.h"

/**
 * 
 */
UCLASS()
class GENETICALGORITHMCAR_API AFinishLine : public ATriggerBox
{
	GENERATED_BODY()
	
public:

	AFinishLine();

	virtual void BeginPlay() override;

	UFUNCTION()
	void ReachedFinishLine(class AActor* OverlappedActor, class AActor* OtherActor);
	
	
};
