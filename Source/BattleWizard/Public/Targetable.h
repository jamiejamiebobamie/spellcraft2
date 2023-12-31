// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "Targetable.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI, Blueprintable)
class UTargetable : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */

class BATTLEWIZARD_API ITargetable
{
	GENERATED_BODY()

	public:
	/**Get weight of Targetable to determine weighted average of TargetTracker location. */
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category="Targetable")
	int GetWeight(AWizardBase* Caller);
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category="Targetable")
	AActor* GetSelf();
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category="Targetable")
	FVector GetTargetLocation();
};
