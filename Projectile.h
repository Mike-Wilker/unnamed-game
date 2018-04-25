#pragma once
#include <vector>

#include "Playable.h"
#include "GameObject.h"
#include "Rectangle.h"
class Projectile : public GameObject
{
protected:
	Point* movementVector;
public:
	Projectile()
	{
		movementVector = new Point(0,0);
	}
	void update(std::vector<Playable*> enemies, double passedTime)
	{
		hitbox->setX(hitbox->getX() + movementVector->getX() * passedTime);
		hitbox->setY(hitbox->getY() + movementVector->getY() * passedTime);
		for (Playable* enemy : enemies)
		{
			if (hitbox->checkCollision(enemy->getHitbox()))
			{
				hit(enemy);
			}
		}
	}
	virtual void hit(Playable* enemy) = 0;
	~Projectile()
	{
		delete movementVector;
	}
};