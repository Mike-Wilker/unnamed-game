#pragma once
#include <vector>
#include <exception>

#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_native_dialog.h>

#include "GameObject.h"
#include "Pickup.h"
#include "Projectile.h"
#include "Playable.h"
#include "ImageMap.h"
class RenderHandler
{
private:
	ALLEGRO_DISPLAY* display;
	ALLEGRO_DISPLAY_MODE displayData;
	ALLEGRO_BITMAP* crosshair;
	ALLEGRO_MOUSE_CURSOR* cursor;
	ALLEGRO_BITMAP* sprites[ImageMap::ImageMapEnd];
public:
	RenderHandler()
	{
		if (!al_init())
		{
			throw new std::exception("Failed to initialize allegro!");
		}
		if (!al_init_primitives_addon())
		{
			throw new std::exception("Failed to initialize primitives addon!");
		}
		if (!al_init_image_addon())
		{
			throw new std::exception("Failed to initialize image addon!");
		}
		al_get_display_mode(0, &displayData);
		al_set_new_display_flags(ALLEGRO_FULLSCREEN_WINDOW);
		display = al_create_display(displayData.width, displayData.height);
		if (!display)
		{
			throw new std::exception("Failed to initialize display!");
		}
		crosshair = al_load_bitmap("resources/images/crosshair.png");
		if (!crosshair)
		{
			throw new std::exception("Failed to load cursor!");
		}
		cursor = al_create_mouse_cursor(crosshair, al_get_bitmap_width(crosshair) / 2.0, al_get_bitmap_height(crosshair) / 2.0);
		al_set_mouse_cursor(display, cursor);
		sprites[ImageMap::CrabSprite] = al_load_bitmap("resources/images/crab.png");
		if (!sprites[ImageMap::CrabSprite])
		{
			throw new std::exception("Failed to load crab sprite!");
		}
		sprites[ImageMap::BulletSprite] = al_load_bitmap("resources/images/bullet.png");
		if (!sprites[ImageMap::BulletSprite])
		{
			throw new std::exception("Failed to load bullet sprite!");
		}
	}
	void render(std::vector<Playable*> players, std::vector<Playable*> enemies, std::vector<Projectile*> playerProjectiles, std::vector<Projectile*> enemyProjectiles, std::vector<Pickup*> pickups)
	{
		
		al_clear_to_color(al_map_rgb(0, 0, 0));
		for (GameObject* renderTarget : players)
		{
			al_draw_scaled_bitmap(
				sprites[renderTarget->getSpriteIndex()],
				0.0f, 0.0f, al_get_bitmap_width(sprites[renderTarget->getSpriteIndex()]), al_get_bitmap_height(sprites[renderTarget->getSpriteIndex()]),
				renderTarget->getHitbox()->getX(), renderTarget->getHitbox()->getY(), renderTarget->getHitbox()->getWidth(), renderTarget->getHitbox()->getHeight(), 0);
		}
		for (GameObject* renderTarget : enemies)
		{
			al_draw_scaled_bitmap(
				sprites[renderTarget->getSpriteIndex()],
				0.0f, 0.0f, al_get_bitmap_width(sprites[renderTarget->getSpriteIndex()]), al_get_bitmap_height(sprites[renderTarget->getSpriteIndex()]),
				renderTarget->getHitbox()->getX(), renderTarget->getHitbox()->getY(), renderTarget->getHitbox()->getWidth(), renderTarget->getHitbox()->getHeight(), 0);
		}
		for (GameObject* renderTarget : playerProjectiles)
		{
			al_draw_scaled_bitmap(
				sprites[renderTarget->getSpriteIndex()],
				0.0f, 0.0f, al_get_bitmap_width(sprites[renderTarget->getSpriteIndex()]), al_get_bitmap_height(sprites[renderTarget->getSpriteIndex()]),
				renderTarget->getHitbox()->getX(), renderTarget->getHitbox()->getY(), renderTarget->getHitbox()->getWidth(), renderTarget->getHitbox()->getHeight(), 0);
		}
		for (GameObject* renderTarget : enemyProjectiles)
		{
			al_draw_scaled_bitmap(
				sprites[renderTarget->getSpriteIndex()],
				0.0f, 0.0f, al_get_bitmap_width(sprites[renderTarget->getSpriteIndex()]), al_get_bitmap_height(sprites[renderTarget->getSpriteIndex()]),
				renderTarget->getHitbox()->getX(), renderTarget->getHitbox()->getY(), renderTarget->getHitbox()->getWidth(), renderTarget->getHitbox()->getHeight(), 0);
		}
		for (GameObject* renderTarget : pickups)
		{
			al_draw_scaled_bitmap(
				sprites[renderTarget->getSpriteIndex()],
				0.0f, 0.0f, al_get_bitmap_width(sprites[renderTarget->getSpriteIndex()]), al_get_bitmap_height(sprites[renderTarget->getSpriteIndex()]),
				renderTarget->getHitbox()->getX(), renderTarget->getHitbox()->getY(), renderTarget->getHitbox()->getWidth(), renderTarget->getHitbox()->getHeight(), 0);
		}
		al_flip_display();
	}
	~RenderHandler()
	{
		al_destroy_display(display);
	}
};