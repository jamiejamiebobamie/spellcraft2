// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Diamondable.h"
#include "Ocean.generated.h"

UCLASS()
class BATTLEWIZARD_API AOcean : public AActor, public IDiamondable
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AOcean();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	};
