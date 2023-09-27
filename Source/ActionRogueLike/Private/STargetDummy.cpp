// Fill out your copyright notice in the Description page of Project Settings.


#include "STargetDummy.h"
#include "SAttributeComponent.h"


// Sets default values
ASTargetDummy::ASTargetDummy()
{
 	

	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>("MeshComp");
	RootComponent = MeshComp;

	AttributeComp = CreateDefaultSubobject<USAttributeComponent>("AttributeComp");
	AttributeComp->OnHealthChanged.AddDynamic(this, &ASTargetDummy::OnHealthChanged);
}
void ASTargetDummy::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);

	AttributeComp->OnHealthChanged.RemoveDynamic(this, &ASTargetDummy::OnHealthChanged);

}



void ASTargetDummy::OnHealthChanged(AActor* InstigatorActor, USAttributeComponent* OwningComp, float NewHealth, float Delta)
{
	if (Delta < 0.0f)
	{
		MeshComp->SetScalarParameterValueOnMaterials("TimeToHit", GetWorld()->TimeSeconds);
		
		//Change BaseMesh color to red
		//MeshComp->SetVectorParameterValueOnMaterials("BaseColor", FVector(1.0f, 0.0f,0.0f));
	}
	//DrawDebugString(GetWorld(), GetActorLocation(), TEXT("HealthChanged"), nullptr, FColor::Green, 2.0f, true);
}

