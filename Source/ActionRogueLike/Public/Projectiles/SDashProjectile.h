// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Projectiles/SProjectileBase.h"
#include "SDashProjectile.generated.h"

/**
 * 
 */
UCLASS()
class ACTIONROGUELIKE_API ASDashProjectile : public ASProjectileBase
{
	GENERATED_BODY()
	
	protected:
	FTimerHandle TimerHandle_DelayedDetonate;
	FTimerHandle TimerHandle_DelayedTeleport;
	UPROPERTY(EditAnywhere, Category = "Dash")
	float DetonateDelay = 0.5f;
	UPROPERTY(EditAnywhere, Category = "Dash")
	float TeleportDelay = 0.2f;

	
	virtual void Explode_Implementation() override;
	void TeleportInstigator();
	// override BeginPlay
	virtual void BeginPlay() override;
};
