// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "NNE.h"
#include "NNERuntimeCPU.h"
#include "NNEModelData.h"
#include "Targetable.h"
#include "Lineable.h"
#include "Circleable.h"
#include "Damageable.h"
#include "Diamondable.h"
#include "WizardBase.generated.h"


// UCLASS(Blueprintable, Category="MyGame")
UCLASS()
class BATTLEWIZARD_API AWizardBase : public ACharacter, public ITargetable, public ILineable, public ICircleable, public IDamageable, public IDiamondable
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AWizardBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION(BlueprintCallable, Category = "mycategory") 
	TArray<float> RunInference(TArray<float> points);

    // virtual int GetWeight_Implementation() override;

public:
	UPROPERTY(EditAnywhere)
	TObjectPtr<UNNEModelData> PreLoadedModelData;
};
