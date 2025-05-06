// Fill out your copyright notice in the Description page of Project Settings.


#include "CharacterAttributeSet.h"
#include "GameplayEffectExtension.h"


UCharacterAttributeSet::UCharacterAttributeSet(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	// 攻击力：基础为 50
	AttackPower.SetBaseValue(50.f);
	MAXAttackPower.SetBaseValue(50.f);

	// 生命力：基础为 100，当前也是满血
	Health.SetBaseValue(100.f);
	MAXHealth.SetBaseValue(100.f);

	// 防御力：基础为 30
	Defense.SetBaseValue(30.f);
	MAXDefense.SetBaseValue(30.f);

	// 架势条：比如基础为 0（可以用于架势削减等系统）
	Poise.SetBaseValue(0.0f);
	MAXPoise.SetBaseValue(0.0f);

	// 体力值：比如设定为 150，当前为满值
	Stamina.SetBaseValue(150.f);
	MAXStamina.SetBaseValue(150.f);

	//韧性条：韧性条越低，僵直越明显
	Resilience.SetBaseValue(100.0f);
	MAXResilience.SetBaseValue(100.0f);
}

void UCharacterAttributeSet::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{
	Super::PostGameplayEffectExecute(Data);

	if (Data.EvaluatedData.Attribute == GetStaminaAttribute())
	{
		// 设置最大最小值
		float NewStamina = FMath::Clamp(GetStamina(), 0.f, MAXStamina.GetBaseValue());
		SetStamina(NewStamina);
	}
}