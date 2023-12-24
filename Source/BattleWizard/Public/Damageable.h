// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "NiagaraFunctionLibrary.h"
#include "NiagaraSystem.h"
#include "UObject/Interface.h"
#include "Damageable.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI, Blueprintable)
class UDamageable : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class BATTLEWIZARD_API IDamageable
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category="Damageable")
bool Damage(float dmgAmt);
UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category="Damageable")
float GetHealth();
UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category="Damageable")
bool ApplyHitImpulse(FVector Impulse);
UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category="Damageable")
bool SpawnHitParticle(UNiagaraSystem* Particle, FVector HitNormal, FVector Location);
};
