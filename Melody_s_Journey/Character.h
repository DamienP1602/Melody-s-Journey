#pragma once
#include <iostream>
#include "Weapon.h"
#include "Trinket.h"
using namespace std;


enum CharacterType
{
	CT_NONE,
	CT_HUMANOID,
	CT_BEAST,
	CT_UNDEAD,
	CT_ELEMENTAL,
	CT_ABERRATION
};

enum DominantStat
{
	DS_NONE,
	DS_STRENGTH,
	DS_INTELLIGENCE,
	DS_AGILITY
};

struct BasicStat
{
	usV maxHealth;
	usV currentHealth;

	usV strength;
	usV intelligence;
	usV agility;

	usV damage;
	usV speed;

	BasicStat() = default;

	BasicStat(usV _maxHealth, usV _currentHealth, usV _strength, usV _intelligence, usV _agility, usV _damage, usV _speed)
	{
		maxHealth = _maxHealth;
		currentHealth = _currentHealth;
		strength = _strength;
		intelligence = _intelligence;
		agility = _agility;
		damage = _damage;
		speed = _speed;
	}
};

struct SpecialStat
{
	sV damageDeal;
	sV damageReceive;
	sV endTurnDamage;
	sV healDeal;
	sV healReceive;
	usV cooldownReduction;

	SpecialStat() = default;

	SpecialStat(sV _damageDeal, sV _damageReceive, sV _endTurnDamage, sV _healDeal, sV _healReceive, usV _cooldownReduction)
	{
		damageDeal = _damageDeal;
		damageReceive = _damageReceive;
		endTurnDamage = _endTurnDamage;
		healDeal = _healDeal;
		healReceive = _healReceive;
		cooldownReduction = _cooldownReduction;
	}
};

struct LevelInformations
{
	usV level;
	usV experience;
	usV experienceCap;

	LevelInformations() = default;

	LevelInformations(usV _level, usV _experience, usV _experienceCap)
	{
		level = _level;
		experience = _experience;
		experienceCap = _experienceCap;
	}
};

class Character
{
	string name = "DefaultCharacterName";
	
	usV level = 1;
	usV experience = 0;
	usV experienceCap = 0;

	usV maxHealth = 100;
	usV currentHealth = 100;

	usV strength = 5;
	usV intelligence = 5;
	usV agility = 5;

	usV damage = 0;
	usV speed = 10;

	sV damageDeal = 0;
	sV damageReceive = 0;
	sV endTurnDamage = 0;
	sV healDeal = 0;
	sV healReceive = 0;
	usV cooldownReduction = 0;

	Weapon* weapon = nullptr;
	Trinket* trinket = nullptr;

	CharacterType type = CT_NONE;
	DominantStat dominantStat = DS_NONE;

	bool mastery = false;

public:
	CharacterType GetType() const
	{
		return type;
	}
	DominantStat GetDominantStat() const
	{
		return dominantStat;
	}
	BasicStat GetBasicStat() const
	{
		return BasicStat(maxHealth, currentHealth, strength, intelligence, agility, damage, speed);
	}
	SpecialStat GetSpecialStat() const
	{
		return SpecialStat(damage, damageReceive, endTurnDamage, healDeal, healReceive, cooldownReduction);
	}

public:
	Character(const string& _name,const CharacterType& _type, const DominantStat& _dominantStat);

private:
	void Init();
	void LevelUp();
	void CalculExperienceCap();

public:
	void GainXP(usV _xp);

};

