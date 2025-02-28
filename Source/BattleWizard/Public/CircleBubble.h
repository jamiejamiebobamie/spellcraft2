// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Targetable.h"
#include "Lineable.h"
#include "Circleable.h"
#include "Damageable.h"
#include "Components/SphereComponent.h"
#include "GameFramework/Actor.h"
#include "CircleBubble.generated.h"

UCLASS(Blueprintable, BlueprintType)
class BATTLEWIZARD_API ACircleBubble : public AActor, public ITargetable, public ILineable, public IDamageable, public ICircleable
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
	// UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category="Circleable")
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category="Circleable")
	void SetBubbleLifespan(float seconds);

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Circleable")
	TArray<ICircleable*> Circleables;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Circleable")
	USphereComponent* Sphere;
	
};
