#pragma once
#include <SFML/Graphics.hpp>
#include "Singleton.h"

using namespace sf;

#define WINDOW GameWindow::GetInstance().GetWindow()
#define WINDOW_SIZE GameWindow::GetInstance().GetWindowSize()

class GameWindow : public Singleton<GameWindow>
{
	RenderWindow* window;
	Vector2i windowSize;
	
public:
	RenderWindow* GetWindow() const
	{
		return window;
	}
	Vector2i GetWindowSize() const
	{
		return windowSize;
	}

public:
	GameWindow();
	~GameWindow();
};
