// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/LyraRolePlayerController.h"
#include "EnhancedInputSubsystems.h"

ALyraRolePlayerController::ALyraRolePlayerController()
{
	bReplicates = true;
}

void ALyraRolePlayerController::BeginPlay()
{
	Super::BeginPlay();
	check(GameInputContext);

	UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
	if (Subsystem != nullptr)
	{
		Subsystem->AddMappingContext(GameInputContext, 0);
	}
}
