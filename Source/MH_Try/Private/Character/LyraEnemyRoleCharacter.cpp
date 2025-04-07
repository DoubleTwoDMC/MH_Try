// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/LyraEnemyRoleCharacter.h"
#include "AbilitySystem/GasAbilitySystemComponent.h"
#include "AbilitySystem/GasAttributeSet.h"

ALyraEnemyRoleCharacter::ALyraEnemyRoleCharacter()
{
	AbilitySystemComponent = CreateDefaultSubobject<UGasAbilitySystemComponent>("AbilitySystemComponent");
	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Minimal);

	AttributeSet = CreateDefaultSubobject<UGasAttributeSet>("AttributeSet");
}

void ALyraEnemyRoleCharacter::BeginPlay()
{
	Super::BeginPlay();
	AbilitySystemComponent->InitAbilityActorInfo(this, this);
}
