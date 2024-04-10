#pragma once
#include <vector>
#include "Singleton.h"
#include "IManager.h"
#include "Canva.h"
#include "MouseWidget.h"

class HUD : public Singleton<HUD>, public IManager<string,Canva>
{
	MouseWidget* mouse = new MouseWidget();

public:
	MouseWidget* GetMouse() const
	{
		return mouse;
	}


public:
	~HUD();
public:
	vector<Drawable*> GetActualCanvaInVector();
	void Update(const Event& _event);
};

