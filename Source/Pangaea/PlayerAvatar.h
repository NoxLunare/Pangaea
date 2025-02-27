// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "PlayerAvatar.generated.h"

UCLASS(Blueprintable)
class PANGAEA_API APlayerAvatar : public ACharacter
{
	GENERATED_BODY()
	
public:
	// Sets default values for this character's properties
	APlayerAvatar();
	UPROPERTY(EditAnywhere, Category = "PlayerAvatar Params")
	int HealthPoints = 500;
	UPROPERTY(EditAnywhere, Category = "PlayerAvatar Params")
	float Strength = 10.0f;
	UPROPERTY(EditAnywhere, Category = "PlayerAvatar Params")
	float Armor = 3.0f;
	UPROPERTY(EditAnywhere, Category = "PlayerAvatar Params")
	float AttackRange = 6.0f;
	UPROPERTY(EditAnywhere, Category = "PlayerAvatar Params")
	float AttackInterval = 1.2f;


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	int _HealthPoints;
	float _AttackCountingDown;


public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	UFUNCTION(BlueprintCallable, Category = "Pangaea|PlayerCharacter", meta = (DisplayName = "Get HP"))
	int GetHealthPoints();
	UFUNCTION(BlueprintCallable,
		Category = "Pangaea|PlayerCharacter")
	bool IsKilled();
	UFUNCTION(BlueprintCallable, Category = "Pangaea|PlayerCharacter")
	bool CanAttack();
	void Attack();
	void Hit(int damage);
	FORCEINLINE USpringArmComponent* GetSringArmComponent() const
	{
		return _springArmComponent;
	}
	FORCEINLINE UCameraComponent* GetCameraComponent() const
	{
		return _cameraComponent;
	}

protected:
	void DieProcess();

private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera", meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* _springArmComponent;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera", meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* _cameraComponent;

};
// Implementacja konstruktora
APlayerAvatar::APlayerAvatar()
{
	// Dodanie komponentu SpringArmComponent
	_springArmComponent = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArmComponent"));

	// Dodanie komponentu CameraComponent
	_cameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComponent"));

	// Dodatkowa konfiguracja mo�e by� tu dodana w razie potrzeby
}

// Dodanie funkcji zgodnej z podanym szablonem:
template<class TReturnType>
TReturnType* CreateDefaultSubobject
(FName SubobjectName, bool bTransient)
{
	// Implementacja lub wywo�anie inicjalizacji zdefiniowanych powy�ej!
}