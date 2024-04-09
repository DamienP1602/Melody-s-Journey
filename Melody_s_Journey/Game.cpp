#include "Game.h"
#include "HUD.h"
#include "Macro.h"

void Game::Start()
{
	Init();

	Update();
}

void Game::Init()
{
}

void Game::Update()
{
	while (WINDOW->isOpen())
	{
		Event _event;
		while(WINDOW->pollEvent(_event))
		{
			if (_event.type == Event::Closed) WINDOW->close();
		}
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
