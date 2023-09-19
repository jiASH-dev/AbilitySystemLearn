#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "CharacterAttributeSet.generated.h"

DECLARE_DELEGATE_OneParam(FOnHealthChange, float)
DECLARE_DELEGATE_OneParam(FOnManaChange, float)
DECLARE_DELEGATE(FOnKill)

UCLASS()
class ABILITYSYSTEMLEARN_API UCharacterAttributeSet : public UAttributeSet
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FGameplayAttributeData Health;
	UPROPERTY()
	FGameplayAttributeData Mana;
	UPROPERTY()
	FGameplayAttributeData Speed;
	FOnHealthChange OnHealthChange;
	FOnManaChange OnManaChange;
	FOnKill OnKill;

public:
	UCharacterAttributeSet();
	void PostGameplayEffectExecute(const struct FGameplayEffectModCallbackData& Data) override;

};
