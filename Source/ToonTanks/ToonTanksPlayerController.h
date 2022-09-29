// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "ToonTanksPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class TOONTANKS_API AToonTanksPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	void SetPlayerEnableState(bool bPlayerEnabled);
	virtual void GameHasEnded(AActor* EndGameFocus, bool bIsWinner) override;
private:
	UPROPERTY(EditAnywhere)
	float RestartDelay = 3.f;

	FTimerHandle RestartTimer;
};
