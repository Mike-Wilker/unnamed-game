#pragma once
#include <vector>

#include "Playable.h"
#include "Projectile.h"
class Item
{
protected:
	int ammo;
	double cooldownTimer;
public:
	virtual void use(Playable* me, Point* target, std::vector<Projectile*> projectiles) = 0;
	const int getAmmo()
	{
		return ammo;
	}
	void update(double passedTime)
	{
		cooldownTimer -= passedTime;
	}
};