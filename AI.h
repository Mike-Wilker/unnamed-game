#pragma once
#include <vector>

#include "Playable.h"
#include "IController.h"
#include "InputFlags.h"
class AI: public IController
{
private:
	Playable* findClosestEnemy(Playable* me, std::vector<Playable*> enemies)
	{
		double closestDistance = INFINITY;
		Playable* closestEnemy = nullptr;
		for (Playable* enemy : enemies)
		{
			if (enemy->getHitbox()->distanceTo(me->getHitbox()) < closestDistance)
			{
				closestDistance = enemy->getHitbox()->distanceTo(me->getHitbox());
				closestEnemy = enemy;
			}
			if (closestEnemy == nullptr)
			{
				throw new std::exception("Enemy has no target!");
			}
		}
		return closestEnemy;
	}
public:
	const unsigned short getInputFlags(Playable* me, std::vector<Playable*> enemies)
	{
		unsigned short inputFlags = 0;
		Playable* closestEnemy = findClosestEnemy(me, enemies);
		if (closestEnemy->getHitbox()->getCenterY() < me->getHitbox()->getCenterY())
		{
			inputFlags += InputFlags::Up;
		}
		else if (closestEnemy->getHitbox()->getCenterY() > me->getHitbox()->getCenterY())
		{
			inputFlags += InputFlags::Down;
		}
		if (closestEnemy->getHitbox()->getCenterX() < me->getHitbox()->getCenterX())
		{
			inputFlags += InputFlags::Left;
		}
		else if (closestEnemy->getHitbox()->getCenterX() > me->getHitbox()->getCenterX())
		{
			inputFlags += InputFlags::Right;
		}
		return inputFlags;
	}
	Point* getTarget(Playable* me, std::vector<Playable*> enemies)
	{
		Playable* closestEnemy = findClosestEnemy(me, enemies);
		return new Point(closestEnemy->getHitbox()->getCenterX(), closestEnemy->getHitbox()->getCenterY());
	}
};