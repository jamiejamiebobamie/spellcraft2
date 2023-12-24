// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Targetable.h"
#include "Lineable.h"
#include "Damageable.h"
#include "GameFramework/Actor.h"
#include "CircleBubble.generated.h"

UCLASS(Blueprintable, BlueprintType)
class BATTLEWIZARD_API ACircleBubble : public AActor, public ITargetable, public ILineable, public IDamageable
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACircleBubble();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
};
