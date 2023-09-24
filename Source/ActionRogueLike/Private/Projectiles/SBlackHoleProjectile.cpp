// Fill out your copyright notice in the Description page of Project Settings.


#include "Projectiles/SBlackHoleProjectile.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Components/SphereComponent.h"
#include "PhysicsEngine/RadialForceComponent.h"



ASBlackHoleProjectile::ASBlackHoleProjectile()
{
	
	
	RootComponent = SphereComp;
	// create a sphere component to represent the black hole
	RadialForceComp = CreateDefaultSubobject<URadialForceComponent>(TEXT("RadialForceComp"));
	RadialForceComp->Radius = 250.0f;
	RadialForceComp->bImpulseVelChange = true;
	RadialForceComp->bAutoActivate = false;
	RadialForceComp->SetupAttachment(RootComponent);
	RadialForceComp->ForceStrength = -200000.0f;
	// set initial speed to 0 for testing
	MoveComp->InitialSpeed = 0.0f;

	ForceStrength = RadialForceComp->ForceStrength;
	PrimaryActorTick.bCanEverTick = true;

	SphereComp->OnComponentBeginOverlap.AddDynamic(this, &ASBlackHoleProjectile::OnActorOverlap);
	//SphereComp->OnComponentHit.AddDynamic(this, &ASBlackHoleProjectile::OnActorHit);
}

void ASBlackHoleProjectile::BeginPlay()
{
	Super::BeginPlay();

	// fire impulse on RadialForceComp
	GetWorldTimerManager().SetTimer(TimerHandle_BlackHole, this, &ASBlackHoleProjectile::BlackHole_TimeElapsed, 4.8f);
	
}
void ASBlackHoleProjectile::BlackHole_TimeElapsed()
{
	TimerHandle_BlackHole.Invalidate();
	Destroy();
}

void ASBlackHoleProjectile::OnActorOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	// Check if OtherActor is simulating physics
	if (OtherActor->GetRootComponent()->IsSimulatingPhysics())
	{
		OtherActor->Destroy();
	}
	
}



void ASBlackHoleProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	
}
