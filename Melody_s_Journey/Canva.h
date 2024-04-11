#pragma once
#include <iostream>
#include <vector>
#include "Widget.h"
#include "IManagable.h"

using namespace std;

class Canva : public IManagable<string>
{
	vector<Widget*> elements = vector<Widget*>();
	bool drawCanva = false;

public:
	bool IsDraw() const
	{
		return drawCanva;
	}
	vector<Widget*> GetVector() const
	{
		return elements;
	}
public:
	Canva(const string& _name);
	virtual void Register() override;

private:
	void AddWidget(Widget* _widget);

public:
	void SetCanvaToDrawable(bool _set);

};

