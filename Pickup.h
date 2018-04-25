#pragma once
#include <vector>

#include "GameObject.h"
#include "Playable.h"
#include "Rectangle.h"
class Pickup: public GameObject
{
public:
	void update(std::vector<Playable*> players, double passedTime)
	{
		for (Playable* player : players)
		{
			if (hitbox->checkCollision(player->getHitbox()))
			{
				addTo(player);
			}
		}
	}
	virtual void addTo(Playable* player) = 0;
};