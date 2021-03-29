#include "MiniginPCH.h"
#include "Audio.h"

Mixer_Sound_System::~Mixer_Sound_System()
{
	StopAllSounds();

	Mix_CloseAudio();
}

void Mixer_Sound_System::AddSound(const std::string& file)
{
	m_Sounds.push_back(std::make_pair(Mix_LoadWAV(file.c_str()),-1));
}

void Mixer_Sound_System::AddMusic(const std::string& file)
{
	m_Music.push_back(Mix_LoadMUS(file.c_str()));
}

void Mixer_Sound_System::Play(int soundID)
{
	m_Sounds[soundID].second = Mix_PlayChannel(-1, m_Sounds[soundID].first, false);
}

void Mixer_Sound_System::Stop(int soundID)
{
	Mix_HaltChannel(m_Sounds[soundID].second);
}

void Mixer_Sound_System::StopAllSounds()
{
	for (int i = 0; i < m_AmountOfChannels; i++)
	{
		Mix_HaltChannel(i);
	}
}
