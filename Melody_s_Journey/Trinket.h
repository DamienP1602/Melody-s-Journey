#pragma once

typedef unsigned short usV; // unsigned short value
typedef short sV; // short value

struct Trinket
{
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

public:
	void Init(usV _bonusHealth, usV _strength, usV _intelligence, usV _agility,
		usV _damage, usV _speed, sV _damageDeal, sV _damageReceive, sV _endTurnDamage,
		sV _healDeal, sV _healReceive, usV _cooldownReduction);
};

