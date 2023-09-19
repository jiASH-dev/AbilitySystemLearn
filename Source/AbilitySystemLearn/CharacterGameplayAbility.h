// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "CharacterGameplayAbility.generated.h"

/**
 * 
 */
UCLASS()
class ABILITYSYSTEMLEARN_API UCharacterGameplayAbility : public UGameplayAbility
{
	GENERATED_BODY()
	
public:
	UCharacterGameplayAbility();
	uint8 GetGameplayTaskDefaultPriority() const override;

};
