#pragma once
#include "Crab.h"
#include "InputHandler.h"
class StartingPlayer : public Crab
{
public:
	StartingPlayer(Point* location)
	{
		hitbox->setOrigin(location);
		controller = new InputHandler();
	}
};