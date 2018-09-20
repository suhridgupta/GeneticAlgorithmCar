// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "CarBody.generated.h"

/**
 * 
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class GENETICALGORITHMCAR_API UCarBody : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable, Category = "Input")
	void SetThrottle(float Throttle);

	UFUNCTION(BlueprintCallable, Category = "Input")
	void SetTurn(float Rotation);

	void DriveCar();

	UPROPERTY(EditDefaultsOnly, Category = "Input")
	float MaxForce = 1000.0f;

	float CurrentThrottle = 0.0f;
	float CurrentRotation = 0.0f;
	
private:
	UPrimitiveComponent* TankRoot = nullptr;

	float FitnessValue = 0.0f;
	
};
