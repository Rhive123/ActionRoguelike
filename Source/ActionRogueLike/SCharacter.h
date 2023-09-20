// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"

// Enhanced Input
#include "InputActionValue.h"
#include "SinteractionComponent.h"

#include "SCharacter.generated.h"


class UCameraComponent;
class USpringArmComponent;
class UInputAction;
class UInputMappingContext;


UCLASS()
class ACTIONROGUELIKE_API ASCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ASCharacter();

protected:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	USpringArmComponent* SpringArmComp;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UCameraComponent* CameraComp;
	// SInteractionComponent
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	class USInteractionComponent* InteractionComp;


	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Define a subclass for the editor to provide a list of possible projectiles (either an Aactor or a subclass)
	UPROPERTY(EditAnywhere, Category = "Spawn")
	TSubclassOf<AActor> ProjectileClass;

	

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	// Function to handle forward movement based on a value
	void Move(const FInputActionValue& Value);

	// Function to handle mouse look based on a value
	void LookMouse(const FInputActionValue& Value);

	// Function to handle primary attack based on input value
	void PrimaryAttack(const FInputActionValue& Value);

	// Function to handle primary interact
	void PrimaryInteract();

	// Input_Jump action
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
	UInputAction* Input_Jump;
	// Input_Move action
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
	UInputAction* Input_Move;
	// Input_LookMouse action
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
	UInputAction* Input_LookMouse;
	// Input_PrimaryAttack action
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
	UInputAction* Input_PrimaryAttack;
	// input_PrimaryInteract action
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
	UInputAction* Input_PrimaryInteract;

	// Input Mapping Context
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
	UInputMappingContext* DefaultInputMapping;



	
	
};
