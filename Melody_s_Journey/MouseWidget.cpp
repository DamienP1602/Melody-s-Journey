#include "MouseWidget.h"
#include "HUD.h"
#include "TextureManager.h"

#define MOUSE_PATH "Assets/Texture/Mouse_Texture.png"

void MouseWidget::Init()
{
	shape = new RectangleShape(Vector2f(36.0f, 45.0f));
	TextureManager::GetInstance().Load(shape, MOUSE_PATH);
}
