#pragma once
#include <iostream>

using namespace std;

typedef unsigned short usV; // unsigned short value
typedef short sV; // short value

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

class Character
{
	string name = "DefaultCharacterName";
		
	usV maxHealth = 0;
	usV currentHealth = 0;

	usV strength = 0;
	usV intelligence = 0;
	usV agility = 0;

	usV damage = 0;
	usV speed = 0;

	sV damageDeal = 0;
	sV damageReceive = 0;
	sV endTurnDamage = 0;
	sV healthDeal = 0;
	sV healthReceive = 0;
	usV cooldownReduction = 0;

	CharacterType type = CT_NONE;
	DominantStat dominantStat = DS_NONE;

};

