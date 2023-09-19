#include "CharacterEntity.h"

ACharacterEntity::ACharacterEntity()
{
	PrimaryActorTick.bCanEverTick = true;

	AbilitySystemComponent = CreateDefaultSubobject<UAbilitySystemComponent>(TEXT("AbilitySystemComponent"));
	AttributeSetComponent = CreateDefaultSubobject<UCharacterAttributeSet>(TEXT("AttributeSetComponent"));

	AttributeSetComponent->OnHealthChange.BindUObject(this, &ACharacterEntity::ChangeHealth);
	AttributeSetComponent->OnManaChange.BindUObject(this, &ACharacterEntity::ChangeMana);
	AttributeSetComponent->OnKill.BindUObject(this, & ACharacterEntity::Kill);
}

bool ACharacterEntity::GetDead()
{
	return IsDead;
}

void ACharacterEntity::SetDead(bool Dead)
{
	IsDead = Dead;
}

void ACharacterEntity::BeginPlay()
{
	Super::BeginPlay();

}

void ACharacterEntity::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACharacterEntity::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

UAbilitySystemComponent* ACharacterEntity::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

void ACharacterEntity::SetupAbility(TSubclassOf<UGameplayAbility> Ability)
{
	if (AbilitySystemComponent)
	{
		if (HasAuthority() && Ability)
		{
			AbilitySystemComponent->GiveAbility(FGameplayAbilitySpec(Ability, 1, 0));
		}
		AbilitySystemComponent->InitAbilityActorInfo(this, this);
	}
}