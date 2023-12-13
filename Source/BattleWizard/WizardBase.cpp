// Fill out your copyright notice in the Description page of Project Settings.

#include "WizardBase.h"

// Sets default values
AWizardBase::AWizardBase()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AWizardBase::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AWizardBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AWizardBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

TArray<float> AWizardBase::RunInference(TArray<float> points){
	// int j = 0;
	TArray<float> result;
	TWeakInterfacePtr<INNERuntimeCPU> Runtime = UE::NNE::GetRuntime<INNERuntimeCPU>(FString("NNERuntimeORTCpu"));
	if (Runtime.IsValid())
	{
		TUniquePtr<UE::NNE::IModelCPU> Model = Runtime->CreateModel(PreLoadedModelData);
		if (Model.IsValid())
		{
			TUniquePtr<UE::NNE::IModelInstanceCPU> ModelInstance = Model->CreateModelInstance();
			if (ModelInstance.IsValid())
			{
				TConstArrayView<uint32> InputDims = { 1, 40, 2 };
				TConstArrayView<uint32> OutputDims = { 18 };
				TArray<UE::NNE::FTensorShape> InputTensorShapes = { UE::NNE::FTensorShape::Make(InputDims) }; 
				ModelInstance->SetInputTensorShapes(InputTensorShapes);
				TArray<UE::NNE::FTensorShape> OutputTensorShapes = { UE::NNE::FTensorShape::Make(OutputDims) }; 
				TArray<float> InputData = points;
				TArray<float> OutputData;
				TArray<UE::NNE::FTensorBindingCPU> InputBindings;
				TArray<UE::NNE::FTensorBindingCPU> OutputBindings;	
				InputData.SetNumZeroed(InputTensorShapes[0].Volume());
				InputBindings.SetNumZeroed(1);
				InputBindings[0].Data = InputData.GetData();
				InputBindings[0].SizeInBytes = InputData.Num() * sizeof(float);
				OutputData.SetNumZeroed(OutputTensorShapes[0].Volume());
				OutputBindings.SetNumZeroed(1);
				OutputBindings[0].Data = OutputData.GetData();
				OutputBindings[0].SizeInBytes = OutputData.Num() * sizeof(float);

				if (ModelInstance->RunSync(InputBindings, OutputBindings) != 0) {
					UE_LOG(LogTemp, Error, TEXT("Failed to run the model"));
				}

				// float max = 0;

				// for (int i=0; i < OutputData.Num(); i++){
				// 	UE_LOG(LogTemp, Warning, TEXT("%d"), i);
				// 	UE_LOG(LogTemp, Warning, TEXT("%f"), OutputData[i]);
				// 	if (max < OutputData[i]){
				// 		max =  OutputData[i];
				// 		j = i;
				// 	}
				// }
				// UE_LOG(LogTemp, Warning, TEXT("Output: %f"), max);
				// UE_LOG(LogTemp, Warning, TEXT("Output: %d"), j);
				result = OutputData;
			}
			else
			{
				UE_LOG(LogTemp, Error, TEXT("Failed to create the model instance"));
			}
		}
		else
		{
			UE_LOG(LogTemp, Error, TEXT("Failed to create the model"));
		}
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Cannot find runtime NNERuntimeORTCpu, please enable the corresponding plugin"));
	}
	return result;
}