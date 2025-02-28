// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Doorable.h"
#include "GameFramework/Actor.h"
#include "Floor.generated.h"

UCLASS()
class BATTLEWIZARD_API AFloor : public AActor,  public IDoorable
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFloor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
