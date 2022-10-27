// Fill out your copyright notice in the Description page of Project Settings.


#include "BallBound.h"
#include "Components/BoxComponent.h"
#include "Kismet/GameplayStatics.h"
#include "PaddlePlayerController.h"


// Sets default values
ABallBound::ABallBound()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	BoxCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("Box collision"));
}

// Called when the game starts or when spawned
void ABallBound::BeginPlay()
{
	Super::BeginPlay();
	BoxCollision->OnComponentBeginOverlap.AddDynamic(this, &ABallBound::OnOverlapBegin);

	PlayerControllerREF = Cast<APaddlePlayerController>(UGameplayStatics::GetPlayerController(GetWorld(), 0));

}

// Called every frame
void ABallBound::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABallBound::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndexType, bool bFromSweet, const FHitResult& SweepResult)
{
	if (OtherActor->ActorHasTag("Ball")) {
		OtherActor->Destroy();

		PlayerControllerREF->SpawnNewBall();
	}

}