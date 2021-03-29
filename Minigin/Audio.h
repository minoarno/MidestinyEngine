#pragma once
#include <SDL_mixer.h>
#include <vector>
#include <iostream>

class Audio
{
public:
	virtual void AddSound(const std::string& file) = 0;
	virtual void AddMusic(const std::string& file) = 0;

	virtual void Play(int soundID) = 0;
	virtual void Stop(int soundID) = 0;
	virtual void StopAllSounds() = 0;
};

class Mixer_Sound_System : public Audio
{
public:
	Mixer_Sound_System() = default;
	~Mixer_Sound_System();

	virtual void AddSound(const std::string& file) override;
	virtual void AddMusic(const std::string& file) override;

	virtual void Play(int soundID) override;
	virtual void Stop(int soundID) override;
	virtual void StopAllSounds() override;
private:
	std::vector<std::pair<Mix_Chunk*,int>> m_Sounds;
	std::vector<Mix_Music*> m_Music;

	const int m_AmountOfChannels = 16;
};

class NullAudio : public Audio
{
public:
	virtual void AddSound(const std::string&) override {};
	virtual void AddMusic(const std::string&) override {};

	virtual void Play(int) override { }
	virtual void Stop(int) override { }
	virtual void StopAllSounds() override { }
};
