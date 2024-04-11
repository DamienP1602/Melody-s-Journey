#include "HUD.h"
#include "GameWindow.h"
#include "Macro.h"

HUD::~HUD()
{
    delete mouse;
}

vector<Drawable*> HUD::GetActualCanvaInVector()
{
    vector<Drawable*> _drawables;

    _drawables.push_back(mouse->GetShape());

    vector<Canva*> _canvas = GetAllValues();

    for (int i = 0; i < SIZE(_canvas); i++)
    {
        if (_canvas[i]->IsDraw())
        {
            vector<Widget*> _canva = _canvas[i]->GetVector();
            for (int j = 0; j < SIZE(_canva); j++)
            {
                _drawables.push_back(_canva[j]->GetShape());
            }
        }
    }
    
    return _drawables;
}

void HUD::Update(const Event& _event)
{
    const Vector2f& _mousePosition = Vector2f(Mouse::getPosition(*WINDOW));
    mouse->GetShape()->setPosition(_mousePosition);
}
