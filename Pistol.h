#pragma once
#include "Point.h"
#include "Playable.h"
#include "Item.h"
#include "Bullet.h"
class Pistol : public Item
{
	Pistol()
	{

	}
	void use(Playable* me, Point* target, std::vector<Projectile*> projectiles)
	{
		if (cooldownTimer <= 0)
		{
			ammo--;
		}
		projectiles.push_back(new Bullet(me, target));
	}
	~Pistol()
	{

	}
};