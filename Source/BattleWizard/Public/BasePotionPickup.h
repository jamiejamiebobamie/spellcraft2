// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Targetable.h"
#include "Lineable.h"
#include "Circleable.h"
#include "Damageable.h"
#include "BasePotionPickup.generated.h"

UCLASS(Blueprintable, BlueprintType)
class BATTLEWIZARD_API ABasePotionPickup : public AActor, public ITargetable, public ILineable, public ICircleable, public IDamageable
{
	GENERATED_BODY()

public:	
	// Sets default values for this actor's properties
	ABasePotionPickup();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
