#pragma once
#include "Audio.h"

class ServiceLocator
{
public:
	static void Initialize()
	{
		audioService = &nullService;
	}

	static void RegisterSoundSystem(Audio* soundSystem)
	{
		if (soundSystem == nullptr)
		{
			audioService = &nullService;
		}
		else
		{
			audioService = soundSystem;
		}
	}

	static Audio& GetAudio()
	{
		return *audioService;
	}

private:
	static Audio* audioService;
	static NullAudio nullService;
};

