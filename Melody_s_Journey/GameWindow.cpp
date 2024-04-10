#include "GameWindow.h"

GameWindow::GameWindow()
{
	window = new RenderWindow();
	windowSize = Vector2i(1200,800);
	window->create(VideoMode(windowSize.x,windowSize.y),"Melody's Journey");
	window->setMouseCursorVisible(false);
}

GameWindow::~GameWindow()
{
	delete window;
}
