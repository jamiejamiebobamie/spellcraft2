// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Targetable.h"
#include "Circleable.h"
#include "Damageable.h"
#include "GameFramework/Actor.h"
#include "IceCube.generated.h"

UCLASS()
class BATTLEWIZARD_API AIceCube : public AActor, public ITargetable, public ICircleable, public IDamageable
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AIceCube();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
