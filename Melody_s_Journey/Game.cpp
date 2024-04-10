#include "Game.h"
#include "HUD.h"
#include "Macro.h"

Game::~Game()
{
	delete player;
}

void Game::Start()
{
	Init();

	Update();
}

void Game::Init()
{
	InitMouse();
}

void Game::InitMouse()
{
	HUD::GetInstance().GetMouse()->Init();
}

void Game::Update()
{
	while (WINDOW->isOpen())
	{
		Event _event;
		while (WINDOW->pollEvent(_event))
		{
			if (_event.type == Event::Closed) WINDOW->close();
		}
		HUD::GetInstance().Update(_event);
		Display();
	}

}

void Game::Display()
{
	WINDOW->clear();

	vector<Drawable*> _drawables = HUD::GetInstance().GetActualCanvaInVector();
	for (int i = 0; i < SIZE(_drawables); i++)
	{
		WINDOW->draw(*_drawables[i]);
	}

	WINDOW->display();
}
