#include "HUD.h"

HUD::HUD()
{
    mouse->Init();
}

HUD::~HUD()
{
    delete mouse;
}

vector<Drawable*> HUD::GetActualCanvaInVector()
{
    vector<Drawable*> _drawables;

    _drawables.push_back(mouse->GetShape());
    
    return vector<Drawable*>();
}
