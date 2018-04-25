#pragma once
#include <vector>

#include "Playable.h"
class IController
{
public:
	virtual const unsigned short getInputFlags(Playable* me, std::vector<Playable*> enemies) = 0;
	virtual Point* getTarget(Playable* me, std::vector<Playable*> enemies) = 0;
};