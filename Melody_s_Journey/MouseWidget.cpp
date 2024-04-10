#include "MouseWidget.h"
#include "HUD.h"
#include "TextureManager.h"

#define MOUSE_PATH "Assets/Textures/Mouse_Cursor.png"

void MouseWidget::Init()
{
	shape = new RectangleShape(Vector2f(29.0f, 36.0f));
	TextureManager::GetInstance().Load(shape, MOUSE_PATH);
}
