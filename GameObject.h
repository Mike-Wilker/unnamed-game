#pragma once

#include "Rectangle.h"
class GameObject
{
protected:
	Rectangle* hitbox;
public:
	GameObject()
	{
		hitbox = new Rectangle(0, 0, 0, 0);
	}
	Rectangle* getHitbox()
	{
		return hitbox;
	}
	virtual const unsigned short getSpriteIndex() = 0;

	virtual ~GameObject()
	{
		delete hitbox;
	}
};