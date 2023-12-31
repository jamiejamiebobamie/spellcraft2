// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "Circleable.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI, Blueprintable)
class UCircleable : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class BATTLEWIZARD_API ICircleable
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category="Circleable")
bool SetIsCircled(ACircleBubble* CircleBubble);
UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category="Circleable")
ACircleBubble* GetIsCircled();
UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category="Circleable")
FVector GetLocation();
UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category="Circleable")
bool ApplyForce(FVector OptionalForce);
UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category="Circleable")
bool GetIsValid();
};
