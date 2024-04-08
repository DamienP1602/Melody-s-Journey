#include "Trinket.h"

void Trinket::Init(usV _bonusHealth, usV _strength, usV _intelligence, usV _agility, usV _damage, usV _speed, sV _damageDeal, sV _damageReceive, sV _endTurnDamage, sV _healDeal, sV _healReceive, usV _cooldownReduction)
{
	bonusHealth = _bonusHealth;
	strength = _strength;
	intelligence = _intelligence;
	agility = _agility;
	damage = _damage;
	speed = _speed;
	damageDeal = _damageDeal;
	damageReceive = _damageReceive;
	endTurnDamage = _endTurnDamage;
	healDeal = _healDeal;
	healReceive = _healReceive;
	cooldownReduction = _cooldownReduction;
}
