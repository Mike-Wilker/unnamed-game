#pragma once
#include "Projectile.h"
#include "Playable.h"
#include "ImageMap.h"
const static int DAMAGE = 10;
const static double SIZE = 20.0;
class Bullet : public Projectile
{
public:
	Bullet(Playable* user, Point* target)
	{
		hitbox->setSize(SIZE);
		hitbox->setX(user->getHitbox()->getCenterX());
		hitbox->setY(user->getHitbox()->getCenterY());
	}
	void hit(Playable* enemy)
	{
		enemy->modifyHealth(-DAMAGE);
	}
	const unsigned short getSpriteIndex()
	{
		return ImageMap::BulletSprite;
	}
};