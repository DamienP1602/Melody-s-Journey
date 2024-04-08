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
