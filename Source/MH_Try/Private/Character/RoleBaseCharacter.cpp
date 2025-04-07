// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/RoleBaseCharacter.h"


ARoleBaseCharacter::ARoleBaseCharacter()
{
	PrimaryActorTick.bCanEverTick = false;
}

UAbilitySystemComponent* ARoleBaseCharacter::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}
