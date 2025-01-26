// Fill out your copyright notice in the Description page of Project Settings.


#include "DefenseTower.h"

// Sets default values
ADefenseTower::ADefenseTower()
{
	PrimaryActorTick.bCanEverTick = true;
	_BoxComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("Box Collision"));
	SetRootComponent(_BoxComponent);
	_MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Static Mesh"));
	_MeshComponent->SetupAttachment(_BoxComponent);
}
// Called when the game starts or when spawned
void ADefenseTower::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ADefenseTower::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

int ADefenseTower::GetHealthPoints()
{
	return _HealthPoints;
}
bool ADefenseTower::IsDestroyed()
{
	return (_HealthPoints > 0.0f);
}
bool ADefenseTower::CanFire()
{
	return (_ReloadCountingDown <= 0.0f);
}

