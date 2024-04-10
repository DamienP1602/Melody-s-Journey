#include "Player.h"

Player::~Player()
{
	for (int i = 0; i < SIZE(trinkets); i++)
	{
		delete trinkets[i];
	}
	for (int i = 0; i < SIZE(weapons); i++)
	{
		delete weapons[i];
	}
	for (int i = 0; i < SIZE(characters); i++)
	{
		delete characters[i];
	}
}
