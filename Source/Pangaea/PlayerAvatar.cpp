// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerAvatar.h"

// Sets default values
APlayerAvatar::APlayerAvatar()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	//Utwórz ramiê kamery 
	_springArmComponent = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	_springArmComponent->SetupAttachment(RootComponent);
	_springArmComponent->SetUsingAbsoluteRotation(true);
	_springArmComponent->TargetArmLength = 800.f;
	_springArmComponent->SetRelativeRotation(FRotator(-60.f, 0.f, 0.f));
	_springArmComponent->bDoCollisionTest = false;
	//Utwórz kamerê 
	_cameraComponent = CreateDefaultSubobject
		<UCameraComponent>(TEXT("Camera"));
	_cameraComponent->SetupAttachment(_springArmComponent, _cameraComponent->bUsePawnControlRotation = false;
}

// Called when the game starts or when spawned
void APlayerAvatar::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APlayerAvatar::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void APlayerAvatar::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}
int APlayerAvatar::GetHealthPoints()
{
	return _HealthPoints;
}
bool APlayerAvatar::IsKilled()
{
	return (_HealthPoints <= 0.0f);
}
bool APlayerAvatar::CanAttack()
{
	return (_AttackCountingDown <= 0.0f);
}
