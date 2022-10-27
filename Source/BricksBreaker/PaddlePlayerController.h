// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "PaddlePlayerController.generated.h"

/**
 * 
 */

class ABall;

UCLASS()
class BRICKSBREAKER_API APaddlePlayerController : public APlayerController
{
	GENERATED_BODY()

		APaddlePlayerController();
	UFUNCTION()
		virtual void SetupInputComponent();

protected:
	virtual void BeginPlay() override;

	void MoveHorizontal(float AxisValue);
	void MoveVertical(float AxisValue);
	void MoveBrick(float BSAxisValue);
	
	void Lanch();

	UPROPERTY(EditAnywhere)
		TSubclassOf<ABall> BallObj;

	ABall* MyBall;
	FVector SpawnLocation = FVector(10.0f, 0.0f, 40.0f);
	FRotator SpawnRotator = FRotator(0.0f, 0.0f, 0.0f);
	FActorSpawnParameters SpawnInfo;

public:
	void SpawnNewBall();

};
