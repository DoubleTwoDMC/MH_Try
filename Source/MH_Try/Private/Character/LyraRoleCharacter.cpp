// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/LyraRoleCharacter.h"
#include "Player/GasPlayerState.h"
#include "AbilitySystemComponent.h"
#include "AbilitySystem/GasAttributeSet.h"

ALyraRoleCharacter::ALyraRoleCharacter()
{
	Pistol = CreateDefaultSubobject<USkeletalMeshComponent>("Pistol");
	Rifle = CreateDefaultSubobject<USkeletalMeshComponent>("Rifle");

	Pistol->SetupAttachment(GetMesh(), FName("PistolUnequipment"));
	Rifle->SetupAttachment(GetMesh(), FName("RifleUnequipment"));

	Pistol->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	Rifle->SetCollisionEnabled(ECollisionEnabled::NoCollision);

}

void ALyraRoleCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);

	//DS logic
	InitASCInfo();
}

void ALyraRoleCharacter::OnRep_PlayerState()
{
	Super::OnRep_PlayerState();

	//Client logic
	InitASCInfo();
}

float ALyraRoleCharacter::GetHealth()
{
	UGasAttributeSet* GasAttributeSet = Cast<UGasAttributeSet>(AttributeSet);
	if (GasAttributeSet)
	{
		return GasAttributeSet->GetHealth();
	}
	return 0.0f;
}

float ALyraRoleCharacter::GetMaxHealth()
{
	UGasAttributeSet* GasAttributeSet = Cast<UGasAttributeSet>(AttributeSet);
	if (GasAttributeSet)
	{
		return GasAttributeSet->GetMaxHealth();
	}
	return 0.0f;
}

float ALyraRoleCharacter::GetMana()
{
	UGasAttributeSet* GasAttributeSet = Cast<UGasAttributeSet>(AttributeSet);
	if (GasAttributeSet)
	{
		return GasAttributeSet->GetMana();
	}
	return 0.0f;
}

float ALyraRoleCharacter::GetMaxMana()
{
	UGasAttributeSet* GasAttributeSet = Cast<UGasAttributeSet>(AttributeSet);
	if (GasAttributeSet)
	{
		return GasAttributeSet->GetMaxMana();
	}
	return 0.0f;
}

void ALyraRoleCharacter::InitASCInfo()
{
	AGasPlayerState* GasPlayerState = GetPlayerState<AGasPlayerState>();
	check(GasPlayerState);
	GasPlayerState->GetAbilitySystemComponent()->InitAbilityActorInfo(GasPlayerState, this);
	AbilitySystemComponent = GasPlayerState->GetAbilitySystemComponent();
	AttributeSet = GasPlayerState->GetAttributeSet();
}
