// Fill out your copyright notice in the Description page of Project Settings.


#include "PaddlePlayerController.h"
#include "Kismet/GameplayStatics.h"
#include "Camera/CameraActor.h"

#include "Paddle.h"
#include "Ball.h"
#include "Brick.h"

APaddlePlayerController::APaddlePlayerController()
{
}

void APaddlePlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	EnableInput(this);

	InputComponent->BindAxis("MoveHorizontal", this, &APaddlePlayerController::MoveHorizontal);
	InputComponent->BindAxis("MoveVertical", this, &APaddlePlayerController::MoveVertical);
	InputComponent->BindAxis("MoveBrick", this, &APaddlePlayerController::MoveBrick);

	InputComponent->BindAction("Launch", IE_Pressed, this, &APaddlePlayerController::Lanch);
}

void APaddlePlayerController::BeginPlay()
{
	TArray<AActor*> CameraActors;

	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ACameraActor::StaticClass(), CameraActors);

	FViewTargetTransitionParams Params;
	SetViewTarget(CameraActors[0], Params);

	SpawnNewBall();
}

void APaddlePlayerController::MoveHorizontal(float AxisValue)
{
	auto MyPawn = Cast<APaddle>(GetPawn());

	if (MyPawn) {
		MyPawn->MoveHorizontal(AxisValue);
	}
}

void APaddlePlayerController::MoveVertical(float AxisValue)
{
	auto MyPawn = Cast<APaddle>(GetPawn());

	if (MyPawn) {
		MyPawn->MoveVertical(AxisValue);
	}
}

void APaddlePlayerController::MoveBrick(float BSAxisValue)
{
	auto MyPawn = Cast<APaddle>(GetPawn());
		if (MyPawn) {
			MyPawn->MoveBrick(BSAxisValue);
		}
}

void APaddlePlayerController::Lanch()
{
	MyBall->Lauch();
}


void APaddlePlayerController::SpawnNewBall()
{
	if (!MyBall) {
		MyBall = nullptr;
	}

	if (BallObj) {
		MyBall = GetWorld()->SpawnActor<ABall>(BallObj, SpawnLocation, SpawnRotator, SpawnInfo);
	}
}
