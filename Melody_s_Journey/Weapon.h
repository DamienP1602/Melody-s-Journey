#pragma once
#include <functional>
#include "Macro.h"

using namespace std;


enum Trigger
{
	T_NONE,T_PERMANENT,T_ON_KILL,T_ON_HEAL,T_ON_DEBUFF,T_ON_TURN,T_ON_HITTED,T_ON_HIT
};

struct Weapon
{
	usV weaponDamage = 0;

	usV bonusHealth = 0;

	usV strength = 0;
	usV intelligence = 0;
	usV agility = 0;

	usV damage = 0;
	usV speed = 10;

	sV damageDeal = 0;
	sV damageReceive = 0;
	sV endTurnDamage = 0;
	sV healDeal = 0;
	sV healReceive = 0;
	usV cooldownReduction = 0;

	usV token = 0;
	usV maxToken = 0;

	Trigger trigger = T_NONE;

	function<void()> callback = nullptr;

public:

	void Init(usV _weaponDamage, usV _bonusHealth, usV _strength, usV _intelligence, usV _agility,
		usV _damage, usV _speed, sV _damageDeal, sV _damageReceive, sV _endTurnDamage,
		sV _healDeal, sV _healReceive, usV _cooldownReduction, usV _tokenMax,
		const function<void()>& _callback, const Trigger& _trigger);
};

