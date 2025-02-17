// Fill out your copyright notice in the Description page of Project Settings.


#include "FollowPlayerAIController.h"
#include "Enemies/ZombieEnemy.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/CharacterMovementComponent.h"


AFollowPlayerAIController::AFollowPlayerAIController()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Active = true;
}

// Called when the game starts or when spawned
void AFollowPlayerAIController::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void AFollowPlayerAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (Active)
	{
		AZombieEnemy* Enemy = Cast<AZombieEnemy>(GetPawn());
		if (Enemy && Enemy->Target)
		{
			MoveToLocation(Enemy->Target->GetActorLocation());
		}
	}
}

void AFollowPlayerAIController::SetActive(bool _Active)
{
	Active = _Active;
}

