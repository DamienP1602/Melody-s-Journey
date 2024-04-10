#pragma once
#include "GameWindow.h"
#include "Player.h"

class Game
{
	Player* player = new Player();

public:
	~Game();

public:
	void Start();
	// Init
	void Init();
	void InitMouse();
	//Game
	void Update();
	void Display();
};

