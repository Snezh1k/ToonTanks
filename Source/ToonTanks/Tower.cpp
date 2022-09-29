// Fill out your copyright notice in the Description page of Project Settings.


#include "Tower.h"
#include "Tank.h"
#include "Kismet/GameplayStatics.h"

void ATower::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//Distance
	if(InFireRange())
	{
		RotateTurret(Tank->GetActorLocation());
	}
	//In range
	
	//Rotate Turret
}

void ATower::HandleDestruction()
{
	Super::HandleDestruction();
	Destroy();
}

// Called when the game starts or when spawned
void ATower::BeginPlay()
{
	Super::BeginPlay();
	
	Tank = Cast<ATank>(UGameplayStatics::GetPlayerPawn(this, 0));

	GetWorldTimerManager().SetTimer(FireRateTimerHandle, this, &ATower::CheckFireCondition, FireRate, true);
}

void ATower::CheckFireCondition()
{
	if(Tank == nullptr)
	{
		return;
	}
	if(InFireRange() && Tank->bAlive)
	{
		Fire();
	}
}

bool ATower::InFireRange()
{
	if(Tank)
	{
		float Distance = FVector::Dist(GetActorLocation(), Tank->GetActorLocation());
		if(Distance <= FireRange)
		{
			return true;
		}
	}
	return false;
}
