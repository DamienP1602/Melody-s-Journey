#include "Canva.h"
#include "Macro.h"
#include "HUD.h"

Canva::Canva(const string& _name) : IManagable(_name)
{
	Register();
}

void Canva::Register()
{
	HUD::GetInstance().Add(id, this);
}

void Canva::AddWidget(Widget* _widget)
{
	elements.push_back(_widget);
}

void Canva::SetCanvaToDrawable(bool _set)
{
	drawCanva = _set;

	for (int i = 0; i < SIZE(elements); i++)
	{
		elements[i]->SetDrawable(_set);
	}
}
