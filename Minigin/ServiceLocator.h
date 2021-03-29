#pragma once
class Audio;
class NullAudio;
class ServiceLocator
{
public:
	static void initialize()
	{
		audioService = &nullService;
	}

	static Audio& GetAudio()
	{
		return *audioService;
	}

private:
	static Audio* audioService;
	static NullAudio* nullService;
};

