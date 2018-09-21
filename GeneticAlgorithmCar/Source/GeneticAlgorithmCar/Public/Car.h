// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Car.generated.h"

class UCarBody;

UCLASS()
class GENETICALGORITHMCAR_API ACar : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ACar();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable)
	void SetBodyReference(UCarBody* Body);

	UCarBody *CarBody = nullptr;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:
	bool GetFirstPhysicsBodyInReach(float LineAngle);

	FVector GetReachLineStart();

	FVector GetReachLineEnd(float LineAngle);
	
};
