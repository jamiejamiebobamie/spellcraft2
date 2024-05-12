// Fill out your copyright notice in the Description page of Project Settings.

#include "WizardBase.h"

// Sets default values
AWizardBase::AWizardBase()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

NPC_Circle_X = {80, 65, 48, 31, 22, 8, 2, 1, 6, 19, 32, 55, 71, 99, 132, 158, 182, 222, 242, 251, 255, 254, 249, 227, 205, 172, 142, 118, 105};
NPC_Circle_Y = {16, 19, 29, 46, 60, 94, 119, 150, 173, 199, 216, 233, 240, 247, 248, 247, 241, 219, 188, 166, 146, 118, 94, 49, 28, 11, 2, 0, 4};

NPC_Line_X = { 0, 30, 60, 90, 120, 180, 210, 255, 244 };
NPC_Line_Y = { 122, 122, 122, 122, 122, 122, 122, 122, 122 };

NPC_Diamond_X = { 0, 16, 207, 246, 254, 255, 243, 192, 169, 152, 128, 123, 99, 53, 14, 0 };
NPC_Diamond_Y = { 6, 3, 21, 21, 22, 26, 48, 111, 153, 176, 221, 218, 169, 102, 18, 0 };

NPC_Star_X = { 13, 12, 69, 119, 149, 176, 54, 0, 12, 63, 254, 220, 138, 87, 25 };
NPC_Star_Y = { 229, 224, 115, 0, 105, 238, 129, 90, 85, 79, 75, 104, 156, 183, 208 };


	
// # circle_5476400767172608 # {"word": "circle", "countrycode": "US", "timestamp": "2017-03-08 17:55:28.07827 UTC", "recognized": true, "key_id": "5476400767172608", "drawing": [[[80, 65, 48, 31, 22, 8, 2, 1, 6, 19, 32, 55, 71, 99, 132, 158, 182, 222, 242, 251, 255, 254, 249, 227, 205, 172, 142, 118, 105], [16, 19, 29, 46, 60, 94, 119, 150, 173, 199, 216, 233, 240, 247, 248, 247, 241, 219, 188, 166, 146, 118, 94, 49, 28, 11, 2, 0, 4]]]}
// # line_5050980804591616 # {"word": "line", "countrycode": "SE", "timestamp": "2017-01-24 15:28:05.32524 UTC", "recognized": true, "key_id": "5050980804591616", "drawing": [[[0, 255, 244], [10, 10, 0]]]}
// # diamond_6120925068001280 # {"word": "diamond", "countrycode": "BR", "timestamp": "2017-03-01 21:14:59.42366 UTC", "recognized": true, "key_id": "6120925068001280", "drawing": [[[0, 16, 207, 246, 254, 255, 243, 192, 169, 152, 128, 123, 99, 53, 14, 0], [6, 3, 21, 21, 22, 26, 48, 111, 153, 176, 221, 218, 169, 102, 18, 0]]]}
// # star_5188434064834560 # {"word": "star", "countrycode": "DE", "timestamp": "2017-03-18 12:38:28.372 UTC", "recognized": true, "key_id": "5188434064834560", "drawing": [[[13, 12, 69, 119, 149, 176, 54, 0, 12, 63, 254, 220, 138, 87, 25], [229, 224, 115, 0, 105, 238, 129, 90, 85, 79, 75, 104, 156, 183, 208]]]}
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

// int ITargetable::GetWeight()
// {
// 	return 0;
// }


TArray<float> AWizardBase::RunInference(TArray<float> points)
{
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