// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Projectiles/SProjectileBase.h"
#include "SBlackHoleProjectile.generated.h"

class URadialForceComponent;
/**
 * 
 */
UCLASS()
class ACTIONROGUELIKE_API ASBlackHoleProjectile : public ASProjectileBase
{
	GENERATED_BODY()
	
	protected:
	//// create a sphere component to represent the black hole
	//UPROPERTY(VisibleAnywhere,BlueprintReadWrite, Category = "Components")
	//USphereComponent* SphereComp;
	
	// create a radial force component to push things away on hit /
	UPROPERTY(VisibleAnywhere,BlueprintReadWrite, Category = "Components")
	URadialForceComponent* RadialForceComp;

	virtual void BeginPlay() override;
	
	
	UFUNCTION()
	void OnActorOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	
	
	void BlackHole_TimeElapsed();
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, Category = "Black Hole Attributes")
    float ForceStrength;
public:
	// Sets default values for this actor's properties
	ASBlackHoleProjectile();
private:
	FTimerHandle TimerHandle_BlackHole;
};


