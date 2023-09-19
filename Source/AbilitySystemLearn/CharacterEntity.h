#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AbilitySystemInterface.h"
#include "AbilitySystemComponent.h"
#include "CharacterAttributeSet.h"
#include "CharacterEntity.generated.h"

UCLASS()
class ABILITYSYSTEMLEARN_API ACharacterEntity : public ACharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()

private:
	bool IsDead;

protected:
	UPROPERTY(BlueprintReadOnly, Category = "GAS")
		UAbilitySystemComponent* AbilitySystemComponent;

public:
	UPROPERTY()
		UCharacterAttributeSet* AttributeSetComponent;

public:
	ACharacterEntity();

	UFUNCTION(BlueprintCallable, BlueprintPure)
		bool GetDead();

	void SetDead(bool Dead);

	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable)
		virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const;

protected:
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "GAS")
		void SetupAbility(TSubclassOf<UGameplayAbility> Ability);

	UFUNCTION(BlueprintImplementableEvent)
		void ChangeHealth(float Health);

	UFUNCTION(BlueprintImplementableEvent)
		void ChangeMana(float Mana);

	UFUNCTION(BlueprintImplementableEvent)
		void Kill();

};
