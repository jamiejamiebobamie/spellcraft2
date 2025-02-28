// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "Lineable.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI, Blueprintable)
class ULineable : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class BATTLEWIZARD_API ILineable
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category="Lineable")
FVector GetLocation();
UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category="Lineable")
bool ApplyImpulse(FVector Impulse);
};
