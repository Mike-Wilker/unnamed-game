#pragma once
#include <vector>

#include "DoublyLinkedList.h"
#include "Item.h"
#include "Point.h"
#include "IController.h"
#include "InputFlags.h"
const static double ROLL_SPEED_MULTIPLIER = 2.0;
const static double ROLL_DURATION = 0.5;
const static double ROLL_COOLDOWN = 1.0;
const static double DIAGONAL = std::sqrt(2.0) / 2.0;
class Playable : public GameObject
{
protected:
	DoublyLinkedList<Item>* items;
	Point* movementVector;
	IController* controller;
	int health;
	double rollingTime;
public:
	Playable()
	{
		rollingTime = 0;
		items = new DoublyLinkedList<Item>();
		movementVector = new Point(0.0, 0.0);
	}
	void modifyHealth(int change)
	{
		health += change;
	}
	void processControls(std::vector<Playable*> enemies)
	{
		unsigned short inputFlags = controller->getInputFlags(this, enemies);
		Point* target = controller->getTarget(this, enemies);
		switch (inputFlags & ~InputFlags::Roll)
		{
		case InputFlags::UpLeft:
			moveUpLeft();
			break;
		case InputFlags::UpRight:
			moveUpRight();
			break;
		case InputFlags::DownLeft:
			moveDownLeft();
			break;
		case InputFlags::DownRight:
			moveDownRight();
			break;
		case InputFlags::Up:
			moveUp();
			break;
		case InputFlags::Down:
			moveDown();
			break;
		case InputFlags::Left:
			moveLeft();
			break;
		case InputFlags::Right:
			moveRight();
			break;
		}
		if (((inputFlags & InputFlags::Roll) > 0) && (rollingTime <= 0))
		{
			roll();
		}
	}
	void addToInventory(Item* item)
	{
		items->append(new Node<Item>(item));
	}
	void roll()
	{
		if (movementVector->getX() != 0 || movementVector->getY() != 0)
		{
			rollingTime = ROLL_DURATION + ROLL_COOLDOWN;
			movementVector->multiply(ROLL_SPEED_MULTIPLIER);
		}
	}
	void moveUp()
	{
		movementVector->addY(-getSpeed());
	}
	void moveDown()
	{
		movementVector->addY(getSpeed());
	}
	void moveLeft()
	{
		movementVector->addX(-getSpeed());
	}
	void moveRight()
	{
		movementVector->addX(getSpeed());
	}
	void moveUpLeft()
	{
		movementVector->addX(-getSpeed() * DIAGONAL);
		movementVector->addY(-getSpeed() * DIAGONAL);
	}
	void moveUpRight()
	{
		movementVector->addX(getSpeed() * DIAGONAL);
		movementVector->addY(-getSpeed() * DIAGONAL);
	}
	void moveDownLeft()
	{
		movementVector->addX(-getSpeed() * DIAGONAL);
		movementVector->addY(getSpeed() * DIAGONAL);
	}
	void moveDownRight()
	{
		movementVector->addX(getSpeed() * DIAGONAL);
		movementVector->addY(getSpeed() * DIAGONAL);
	}
	virtual const double getSpeed() = 0;
	virtual void update(std::vector<Playable*> enemies, double time) = 0;
	~Playable()
	{
		items->clear();
		delete items;
		delete movementVector;
		delete controller;
	}

	const unsigned short getSpriteIndex()
	{
		return 0;
	};
};