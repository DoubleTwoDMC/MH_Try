// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Character/RoleBaseCharacter.h"
#include "LyraRoleCharacter.generated.h"

/**
 * 
 */
UCLASS(Abstract)
class MH_TRY_API ALyraRoleCharacter : public ARoleBaseCharacter
{
	GENERATED_BODY()
public:
	ALyraRoleCharacter();
	virtual void PossessedBy(AController* NewController) override;
	virtual void OnRep_PlayerState() override;
	UFUNCTION(BlueprintCallable)
	float GetHealth();
	UFUNCTION(BlueprintCallable)
	float GetMaxHealth();
	UFUNCTION(BlueprintCallable)
	float GetMana();
	UFUNCTION(BlueprintCallable)
	float GetMaxMana();
protected:
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Weapon")
	TObjectPtr<USkeletalMeshComponent> Pistol;
	
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Weapon")
	TObjectPtr<USkeletalMeshComponent> Rifle;
private:
	void InitASCInfo();
};
