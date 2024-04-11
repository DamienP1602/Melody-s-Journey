#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;

class Widget
{
protected:
	Shape* shape = nullptr;
	bool isDrawable = true;

public:
	Shape* GetShape() const
	{
		return shape;
	}

	void SetDrawable(bool _set)
	{
		isDrawable = _set;
	}
public:
	~Widget();
};

