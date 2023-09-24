// Fill out your copyright notice in the Description page of Project Settings.


#include "Projectiles/SDashProjectile.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Particles/ParticleSystemComponent.h"
#include "Kismet/GameplayStatics.h"



void ASDashProjectile::BeginPlay()
{
	Super::BeginPlay();

	// Set the timer to call the function that will destroy the projectile
	GetWorldTimerManager().SetTimer(TimerHandle_DelayedDetonate, this, &ASDashProjectile::Explode, DetonateDelay);
}

void ASDashProjectile::Explode_Implementation()
{
    // Clear timer if the Explode was already called through another source like OnActorHit
	GetWorldTimerManager().ClearTimer(TimerHandle_DelayedDetonate);
	UGameplayStatics::SpawnEmitterAtLocation(this, ImpactVFX, GetActorLocation(), GetActorRotation());
	EffectComp->DeactivateSystem();
	MoveComp->StopMovementImmediately();

	GetWorldTimerManager().SetTimer(TimerHandle_DelayedTeleport, this, &ASDashProjectile::TeleportInstigator, TeleportDelay);
	// Skip base implementation as it will destroy actor (we need to stay alive a bit longer to finish the 2nd timer)
	// Super::Explode_Implementation();
}
void ASDashProjectile::TeleportInstigator()
{
	// Get the player character
	AActor* ActorToTeleport = GetInstigator();
	// Check to make sure the player pawn is valid
	if (ensure(ActorToTeleport))
	{
		// Keep instigator rotation or it may end up jarring
		ActorToTeleport->TeleportTo(GetActorLocation(), ActorToTeleport->GetActorRotation(), false, false);
		Destroy();
	}
	
}