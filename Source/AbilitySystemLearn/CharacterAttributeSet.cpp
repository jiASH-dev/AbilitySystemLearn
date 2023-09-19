#include "CharacterAttributeSet.h"
#include "GameplayEffectExtension.h"
#include "CharacterEntity.h"
#include "GameplayEffect.h"
#include "GameFramework/CharacterMovementComponent.h"

UCharacterAttributeSet::UCharacterAttributeSet() :
	Health(100.f), Mana(100.f) {}

void UCharacterAttributeSet::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{
	ACharacterEntity* OwningCharacter = Cast<ACharacterEntity>(GetOwningActor());
	if (Data.EvaluatedData.Attribute.GetName() == TEXT("Speed"))
	{
		OwningCharacter->GetCharacterMovement()->MaxWalkSpeed = Speed.GetCurrentValue();
	}
	else if (Data.EvaluatedData.Attribute.GetName() == TEXT("Health"))
	{
		float CurrentHealth = FMath::Clamp(Health.GetCurrentValue(), 0.f, Health.GetBaseValue());
		Health.SetCurrentValue(CurrentHealth);

		if (CurrentHealth > 0)
		{
			OnHealthChange.Execute(CurrentHealth);
		}
		else if (!OwningCharacter->GetDead())
		{
			OwningCharacter->SetDead(true);
			OnKill.Execute();
		}
	}
	else if (Data.EvaluatedData.Attribute.GetName() == TEXT("Mana"))
	{
		float CurrentMana = FMath::Clamp(Mana.GetCurrentValue(), 0.f, Mana.GetBaseValue());
		OnManaChange.Execute(CurrentMana);
	}
}
