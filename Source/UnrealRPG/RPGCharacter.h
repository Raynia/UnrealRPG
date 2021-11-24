// ⓒFox Tales Studio, All rights reserved

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/Character.h"
#include "RPGCharacter.generated.h"

UCLASS()
class UNREALRPG_API ARPGCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ARPGCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	/* Character Movement Setting */

	bool isSprint;
	float DefaultWalkSpeed;
	float SprintWalkSpeed;
	UCharacterMovementComponent* PlayerMovementComponent;

	UFUNCTION(BlueprintCallable)
	void MoveForward(float Value);
	UFUNCTION(BlueprintCallable)
	void MoveRight(float Value);
	UFUNCTION(BlueprintCallable)
	void StartJump();
	UFUNCTION(BlueprintCallable)
	void StopJump();
	UFUNCTION(BlueprintCallable)
	void StartSprint();
	UFUNCTION(BlueprintCallable)
	void StopSprint();
	UFUNCTION(BlueprintCallable)
	void Interact();

	/* Character Ability & State Setting */

	const uint16 MIN_HEALTH_POINT = 0;
	uint16 MaxHealthPoint = 2000;

	const uint16 MIN_MANA_POINT = 0;
	uint16 MaxManaPoint = 25000;

	const int16 MIN_STAMINA_POINT = -100;
	const uint16 MAX_STAMINA_POINT = 1000;

	const uint16 MIN_FOOD_POINT = 0;
	const uint16 MAX_FOOD_POINT = 1000;

	const uint16 MIN_WATER_POINT = 0;
	const uint16 MAX_WATER_POINT = 1000;

	const uint16 MAX_REST_COUNT = 5;

	const float DEFAULT_HEALTH_RESTORATION = 5.0F;
	const float DEFAULT_MANA_RESTORATION = 140.0F;
	const float DEFAULT_STAMINA_REDUCATION = 0.31F;
	const float DEFAULT_FOOD_REDUCATION = 0.47F;
	const float DEFAULT_WATER_REDUCATION = 0.47F;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character Status")
	uint32 HealthPoint;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character Status")
	uint32 ManaPoint;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character Status")
	int32 StaminaPoint;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character Status")
	uint16 FoodPoint;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character Status")
	uint16 WaterPoint;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character Status")
	float HealthRestoration;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character Status")
	float ManaRestoration;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character Status")
	float StaminaReduction;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character Status")
	float FoodReduction;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character Status")
	float WaterReduction;

	uint16 RestCount;

	UFUNCTION(BlueprintCallable, Category = "Character Condition")
	void AwakeCondition();
	UFUNCTION(BlueprintCallable, Category = "Character Condition")
	void WaitCondition();
	UFUNCTION(BlueprintCallable, Category = "Character Condition")
	void SleepCondition();
	UFUNCTION(BlueprintCallable, Category = "Character Condition")
	void RestCondition();
	UFUNCTION(BlueprintCallable, Category = "Character Condition")
	void BlackOutCondition();

	UFUNCTION(BlueprintCallable, Category = "Character Condition")
	void HungerCondition();
	UFUNCTION(BlueprintCallable, Category = "Character Condition")
	void ThirstCondition();
};
