#include "HUD.h"
#include "GameWindow.h"

HUD::~HUD()
{
    delete mouse;
}

vector<Drawable*> HUD::GetActualCanvaInVector()
{
    vector<Drawable*> _drawables;

    _drawables.push_back(mouse->GetShape());
    
    return _drawables;
}

void HUD::Update(const Event& _event)
{
    const Vector2f& _mousePosition = Vector2f(Mouse::getPosition(*WINDOW));
    mouse->GetShape()->setPosition(_mousePosition);
}
