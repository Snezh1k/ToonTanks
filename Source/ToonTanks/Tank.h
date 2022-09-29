// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BasePawn.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Tank.generated.h"

/**
 * 
 */
UCLASS()
class TOONTANKS_API ATank : public ABasePawn
{
	GENERATED_BODY()
public:
	ATank();
	
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void HandleDestruction();

	APlayerController* GetTankPlayerController() const
	{
		return TankPlayerController;
	}

	bool bAlive = true;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
private:
	UPROPERTY(EditAnywhere, Category="Components")
	USpringArmComponent* ArmComponent;
	
	UPROPERTY(EditAnywhere, Category="Components")
	UCameraComponent* CameraComponent;
	
	void Move(float Value);
	void Turn(float Value);
	 

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(AllowPrivateAccess = true), Category="Movement")
	float Speed = 200.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(AllowPrivateAccess = true), Category="Movement")
	float TurnRate = 90.f;

	APlayerController* TankPlayerController;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
