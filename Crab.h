#pragma once
#include "Playable.h"
#include "Point.h"
#include "Game.h"
#include "AI.h"
const static double MOVEMENT_SPEED = 100.0;
const static double SIZE = 100.0;
const static double HEALTH = 100;
class Crab : public Playable
{
public:
	Crab()
	{
		health = HEALTH;
		hitbox->setSize(SIZE);
	}
	Crab(Point* location)
	{
		hitbox->setOrigin(location);
		hitbox->setSize(SIZE);
		controller = new AI();
	}
	void update(std::vector<Playable*> gameObjects, double time)
	{
		if (rollingTime > 0.0)
		{
			rollingTime -= time;
		}
		if (rollingTime <= ROLL_COOLDOWN)
		{
			processControls(gameObjects);
		}
		hitbox->setX(hitbox->getX() + movementVector->getX() * time);
		hitbox->setY(hitbox->getY() + movementVector->getY() * time);
		if (rollingTime <= ROLL_COOLDOWN)
		{
			movementVector->setX(0.0);
			movementVector->setY(0.0);
		}
	}
	const double getSpeed()
	{
		return MOVEMENT_SPEED;
	}
	const unsigned short getSpriteIndex()
	{
		return ImageMap::CrabSprite;
	}
	~Crab()
	{
		
	}
};