// Fill out your copyright notice in the Description page of Project Settings.

#include "PlayerCharacter_Base.h"
#include "AbilitySystemComponent.h"
#include "CharacterAttributeSet.h"


FName  APlayerCharacter_Base::AbilitySystemComponentName(TEXT("AbilitySystemComponent0"));

APlayerCharacter_Base::APlayerCharacter_Base(const FObjectInitializer& ObjectInitializer)
: Super(ObjectInitializer)
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	AbilitySystemComponent = CreateDefaultSubobject<UAbilitySystemComponent>(APlayerCharacter_Base::AbilitySystemComponentName);

	AbilitySystemComponent->SetIsReplicated(true);
}

// Called when the game starts or when spawned
void APlayerCharacter_Base::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APlayerCharacter_Base::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void APlayerCharacter_Base::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void APlayerCharacter_Base::PostInitializeComponents()
{	
	Super::PostInitializeComponents();

	AbilitySystemComponent->InitStats(UCharacterAttributeSet::StaticClass(), NULL);
}

UAbilitySystemComponent* APlayerCharacter_Base::GetAbilitySystemComponent() const
{
	return FindComponentByClass<UAbilitySystemComponent>();
}
