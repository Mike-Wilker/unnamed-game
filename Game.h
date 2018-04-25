#pragma once

#include <vector>
#include <iostream>

#include <allegro5/allegro.h>
#include <allegro5/timer.h>

#include "SoundHandler.h"
#include "RenderHandler.h"
#include "Crab.h"
#include "StartingPlayer.h"
class Game
{
private:
	std::vector<Playable*> players;
	std::vector<Playable*> enemies;
	std::vector<Projectile*> playerProjectiles;
	std::vector<Projectile*> enemyProjectiles;
	std::vector<Pickup*> pickups;
	RenderHandler* renderHandler;
	SoundHandler* soundHandler;
	ALLEGRO_TIMER* timer;
public:
	Game()
	{
		renderHandler = new RenderHandler();
		soundHandler = new SoundHandler();
		players.push_back(new StartingPlayer(new Point(0, 0)));
		enemies.push_back(new Crab(new Point(500, 500)));
		startLoop();
	}
	void startLoop()
	{
		double lastTime = al_get_time();
		while (true)
		{
			double passedTime = al_get_time() - lastTime;
			lastTime = al_get_time();
			for (auto player : players)
			{
				player->update(enemies, passedTime);
			}
			for (auto enemy : enemies)
			{
				enemy->update(players, passedTime);
			}
			for (auto projectile : playerProjectiles)
			{
				projectile->update(enemies, passedTime);
			}
			for (auto projectile : enemyProjectiles)
			{
				projectile->update(players, passedTime);
			}
			for (auto pickup : pickups)
			{
				pickup->update(players, passedTime);
			}
			renderHandler->render(players, enemies, playerProjectiles, enemyProjectiles, pickups);
		}
	}
	~Game()
	{
		delete renderHandler;
		delete soundHandler;
		players.clear();
		std::vector<Playable*>().swap(players);
		enemies.clear();
		std::vector<Playable*>().swap(enemies);
		playerProjectiles.clear();
		std::vector<Projectile*>().swap(playerProjectiles);
		enemyProjectiles.clear();
		std::vector<Projectile*>().swap(enemyProjectiles);
		pickups.clear();
		std::vector<Pickup*>().swap(pickups);
		al_destroy_timer(timer);
	}
};