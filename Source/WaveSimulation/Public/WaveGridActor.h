// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ProceduralMeshComponent.h"
#include "WaveGridActor.generated.h"

UCLASS(Blueprintable)
class WAVESIMULATION_API AWaveGridActor : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AWaveGridActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called in editor when actor is constructed or a property changes
	virtual void OnConstruction(const FTransform& Transform) override;

	// User-editable material for the wave grid
	UPROPERTY(EditAnywhere, Category = "Wave Grid")
	UMaterialInterface* WaveMaterial;

	// Procedural Mesh Component
	UPROPERTY(VisibleAnywhere)
	UProceduralMeshComponent* ProcMesh;

	// Number of vertices per side of the grid
	UPROPERTY(EditAnywhere, Category = "Wave Grid", meta = (ClampMin = "2", ClampMax = "512"))
	int32 NumVerts = 128;

	// Distance between vertices
	UPROPERTY(EditAnywhere, Category = "Wave Grid", meta = (ClampMin = "1.0", ClampMax = "1000.0"))
	float GridSpacing = 50.0f;

	// Builds the procedural grid mesh
	void CreateWaveGrid(UProceduralMeshComponent* Mesh, int32 InNumVerts, float InGridSpacing);
};
