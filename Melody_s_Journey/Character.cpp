#include "Character.h"


Character::Character(const string& _name, const CharacterType& _type, const DominantStat& _dominantStat)
{
	name = _name;
	type = _type;
	dominantStat = _dominantStat;

	Init();
}

void Character::Init()
{
	switch (dominantStat)
	{
	case DS_STRENGTH:
		strength += 3;
		break;
	case DS_INTELLIGENCE:
		intelligence += 3;
		break;
	case DS_AGILITY:
		agility += 3;
		break;
	}

	CalculExperienceCap();
}

void Character::GainXP(usV _xp)
{
	while (_xp != 0)
	{
		experience++;
		_xp--;

		if (experience == experienceCap)
		{
			LevelUp();
			CalculExperienceCap();
			experience = 0;
		}
	}
}

void Character::BasicDamage(Character* _target)
{
	// une méthode pour récupérer un ennemy sur le terrain

	_target->ReduceHealth(GetDamage());
}

void Character::LevelUp()
{
	level++;
	if (level % 2 == 0)
	{
		strength++;
		intelligence++;
		agility++;
	}
	maxHealth += 10;
}

void Character::CalculExperienceCap()
{
	experienceCap = 100 * (2 + level);
}

usV Character::GetDamage()
{
	switch (dominantStat)
	{
	case DS_STRENGTH:
		return strength / 2;
		break;
	case DS_INTELLIGENCE:
		return intelligence / 2;
		break;
	case DS_AGILITY:
		return agility / 2;
		break;
	}

	return usV();
}

bool Character::ReduceHealth(const usV& _damage)
{
	currentHealth -= _damage;

	if (currentHealth == 0)
		return true;

	return false;
}

BasicStat Character::GetBasicStat() const
{
	usV _maxHealth = maxHealth + weapon->bonusHealth + trinket->bonusHealth;
	usV _currentHealth = _maxHealth;
	usV _strength = strength + weapon->strength + trinket->strength;
	usV _intelligence = intelligence + weapon->intelligence + trinket->intelligence;
	usV _agility = agility + weapon->agility + trinket->agility;
	usV _damage = damage + weapon->damage + weapon->weaponDamage + trinket->damage;
	usV _speed = speed + weapon->speed + trinket->speed;	
	
	return BasicStat(_maxHealth, _currentHealth, _strength, _intelligence, _agility, _damage, _speed);
}

SpecialStat Character::GetSpecialStat() const
{
	sV _damageDeal = damageDeal + weapon->damageDeal + trinket->damageDeal;
	sV _damageReceive = damageReceive + weapon->damageReceive + trinket->damageReceive;
	sV _endTurnDamage = endTurnDamage + weapon->endTurnDamage + trinket->endTurnDamage;
	sV _healDeal = healDeal + weapon->healDeal + trinket->healDeal;
	sV _healReceive = healReceive + weapon->healReceive + trinket->healReceive;
	usV _cooldownReduction = cooldownReduction + weapon->cooldownReduction + trinket->cooldownReduction;
	
	return SpecialStat(_damageDeal, _damageReceive, _endTurnDamage, _healDeal, _healReceive, _cooldownReduction);
}