#pragma once
#include "Trinket.h"
#include "Weapon.h"
#include "Character.h"
#include <vector>

class Player
{
	usV gold = 0;
	vector<Trinket*> trinkets = vector<Trinket*>();
	vector<Weapon*> weapons = vector<Weapon*>();
	vector<Character*> characters = vector<Character*>();

public:
	~Player();
};

