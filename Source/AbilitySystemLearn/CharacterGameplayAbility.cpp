// Fill out your copyright notice in the Description page of Project Settings.


#include "CharacterGameplayAbility.h"
#include "GameplayTagContainer.h"
#include "Abilities/Tasks/AbilityTask_WaitGameplayEvent.h"

UCharacterGameplayAbility::UCharacterGameplayAbility()
{
    //UAbilityTask_WaitGameplayEvent* SkillMeleeDamageEvent = UAbilityTask_WaitGameplayEvent::WaitGameplayEvent(this, FGameplayTag::RequestGameplayTag("skill.melee.damage"), nullptr, false, true);
    //SkillMeleeDamageEvent->EventReceived.AddDynamic(this, &UCharacterGameplayAbility::DelegateTest);
}

uint8 UCharacterGameplayAbility::GetGameplayTaskDefaultPriority() const
{
    return uint8();
}