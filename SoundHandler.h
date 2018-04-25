#pragma once
#include <exception>

#include <allegro5/allegro.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>

#include "SoundMap.h"

class SoundHandler
{
private:
	const double SOUND_SPEED_VARIATION = 0.2;
	const double SOUND_VOLUME_VARIATION = 0.1;
	ALLEGRO_SAMPLE* sounds[SoundMap::SoundMapEnd];
public:
	SoundHandler()
	{
		if (!al_install_audio())
		{
			throw new std::exception("Unable to install audio!");
		}
		if (!al_init_acodec_addon())
		{
			throw new std::exception("Unable to initialize codec addon!");
		}
		if (!al_reserve_samples(SoundMap::SoundMapEnd))
		{
			throw new std::exception("Unable to reserve sample spaces!");
		}
		/*
		sounds[SoundIndexes::Hitsound]= al_load_sample("resources/sound/hitsound.wav");
		if (!sounds[SoundIndexes::Hitsound])
		{
			throw new std::exception("Unable to load hitsound.wav");
		}
		*/
	}
	void playSound(unsigned short soundID)
	{
		double randomSpeed = ((rand() / RAND_MAX) * SOUND_SPEED_VARIATION) + (1.0 - SOUND_SPEED_VARIATION / 2.0);
		double randomVolume = ((rand() / RAND_MAX) * SOUND_VOLUME_VARIATION) + (1.0 - SOUND_VOLUME_VARIATION / 2.0);
		al_play_sample(sounds[soundID], randomVolume, 0.0, randomSpeed, ALLEGRO_PLAYMODE_ONCE, NULL);
	}
	void playBGM()
	{

	}
	~SoundHandler()
	{
		for (int x = 0; x < SoundMap::SoundMapEnd; x++)
		{
			al_destroy_sample(sounds[x]);
		}
	}
};