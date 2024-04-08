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
	default:
		break;
	}
}

void Character::GainXP()
{
}

void Character::LevelUp()
{
}

void Character::CalculExperienceCap()
{
}
