#pragma once
#include <allegro5\allegro.h>
#include <allegro5\mouse_cursor.h>

#include "InputFlags.h"
#include "Game.h"
#include "IController.h"
#include "Point.h"
class InputHandler : public IController
{
private:
	ALLEGRO_KEYBOARD_STATE* keyState;
	ALLEGRO_MOUSE_STATE* mouseState;
public:
	InputHandler()
	{
		al_install_keyboard();
		keyState = new ALLEGRO_KEYBOARD_STATE();
	}
	const unsigned short getInputFlags(Playable* me, std::vector<Playable*> enemies)
	{
		unsigned short inputFlags = 0;
		al_get_keyboard_state(keyState);
		if (al_key_down(keyState, ALLEGRO_KEY_W))
		{
			inputFlags += InputFlags::Up;
		}
		if (al_key_down(keyState, ALLEGRO_KEY_S))
		{
			inputFlags += InputFlags::Down;
		}
		if (al_key_down(keyState, ALLEGRO_KEY_A))
		{
			inputFlags += InputFlags::Left;
		}
		if (al_key_down(keyState, ALLEGRO_KEY_D))
		{
			inputFlags += InputFlags::Right;
		}
		if (al_key_down(keyState, ALLEGRO_KEY_LSHIFT))
		{
			inputFlags += InputFlags::Roll;
		}
		return inputFlags;
	}
	Point* getTarget(Playable* me, std::vector<Playable*> enemies)
	{
		al_get_mouse_state(mouseState);
		if (mouseState->buttons & 1)
		{
			return new Point(mouseState->x, mouseState->y);
		}
		return nullptr;
	}
	virtual ~InputHandler()
	{
		al_uninstall_keyboard();
		al_uninstall_mouse();
		delete keyState;
		delete mouseState;
	}
};