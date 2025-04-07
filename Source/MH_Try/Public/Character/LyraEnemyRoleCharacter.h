// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Character/RoleBaseCharacter.h"
#include "LyraEnemyRoleCharacter.generated.h"

/**
 * 
 */
UCLASS(Abstract)
class MH_TRY_API ALyraEnemyRoleCharacter : public ARoleBaseCharacter
{
	GENERATED_BODY()
public:
	ALyraEnemyRoleCharacter();
	virtual void BeginPlay() override;
	
};
