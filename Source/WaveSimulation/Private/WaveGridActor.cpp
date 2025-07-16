// Fill out your copyright notice in the Description page of Project Settings.


#include "WaveGridActor.h"

// Sets default values
AWaveGridActor::AWaveGridActor()
{
	PrimaryActorTick.bCanEverTick = true;

	ProcMesh = CreateDefaultSubobject<UProceduralMeshComponent>(TEXT("ProcMesh"));
	RootComponent = ProcMesh;

	ProcMesh->bUseAsyncCooking = true;
}

// Called when the game starts or when spawned
void AWaveGridActor::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AWaveGridActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called in editor when placed or properties change
void AWaveGridActor::OnConstruction(const FTransform& Transform)
{
	Super::OnConstruction(Transform);

	if (ProcMesh)
	{
		ProcMesh->ClearAllMeshSections();

		CreateWaveGrid(ProcMesh, NumVerts, GridSpacing);

		if (WaveMaterial)
		{
			ProcMesh->SetMaterial(0, WaveMaterial);
		}
	}
}

// Builds a flat grid mesh in X/Y space
void AWaveGridActor::CreateWaveGrid(UProceduralMeshComponent* Mesh, int32 InNumVerts, float InGridSpacing)
{
	TArray<FVector> Vertices;
	TArray<int32> Triangles;
	TArray<FVector2D> UVs;
	TArray<FVector> Normals;
	TArray<FProcMeshTangent> Tangents;
	TArray<FLinearColor> VertexColors;

	Vertices.Reserve(InNumVerts * InNumVerts);
	UVs.Reserve(InNumVerts * InNumVerts);
	Normals.Reserve(InNumVerts * InNumVerts);

	// Generate vertices and UVs
	for (int32 Y = 0; Y < InNumVerts; ++Y)
	{
		for (int32 X = 0; X < InNumVerts; ++X)
		{
			Vertices.Add(FVector(X * InGridSpacing, Y * InGridSpacing, 0.0f));
			UVs.Add(FVector2D((float)X / (InNumVerts - 1), (float)Y / (InNumVerts - 1)));
			Normals.Add(FVector(0.0f, 0.0f, 1.0f));
			VertexColors.Add(FLinearColor::White);
			Tangents.Add(FProcMeshTangent(1.0f, 0.0f, 0.0f));
		}
	}

	// Generate triangles
	for (int32 Y = 0; Y < InNumVerts - 1; ++Y)
	{
		for (int32 X = 0; X < InNumVerts - 1; ++X)
		{
			int32 Index = Y * InNumVerts + X;

			Triangles.Add(Index);
			Triangles.Add(Index + InNumVerts);
			Triangles.Add(Index + InNumVerts + 1);

			Triangles.Add(Index);
			Triangles.Add(Index + InNumVerts + 1);
			Triangles.Add(Index + 1);
		}
	}

	// Create the mesh
	Mesh->CreateMeshSection_LinearColor(
		0,             // Section Index
		Vertices,
		Triangles,
		Normals,
		UVs,
		VertexColors,
		Tangents,
		false           // Disable collision
	);
}

