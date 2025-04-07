// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "LyraRolePlayerController.generated.h"

class UInputMappingContext;

/**
 * 
 */
UCLASS()
class MH_TRY_API ALyraRolePlayerController : public APlayerController
{
	GENERATED_BODY()
public:
	ALyraRolePlayerController();
protected:
	virtual void BeginPlay() override;
private:
	UPROPERTY(EditAnywhere, Category = "Input");
	TObjectPtr<UInputMappingContext> GameInputContext;
};
