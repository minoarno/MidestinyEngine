#include "MiniginPCH.h"
#include <SDL_mixer.h>
#include "Audio.h"
#include "Log.h"

Mixer_Sound_System::~Mixer_Sound_System()
{
	StopAllSounds();
	Mix_CloseAudio();

	for (size_t i = 0; i < m_Music.size(); i++)
	{
		Mix_FreeMusic(m_Music[i]); 
		m_Music[i] = nullptr;
	}
	m_Music.clear();

	for (size_t i = 0; i < m_Sounds.size(); i++)
	{
		Mix_FreeChunk(m_Sounds[i].first);
		m_Sounds[i].first = nullptr;
	}
	m_Sounds.clear();
}

void Mixer_Sound_System::AddSound(const std::string& file)
{
	m_Sounds.push_back(std::make_pair(Mix_LoadWAV(file.c_str()),-1));
}

void Mixer_Sound_System::AddMusic(const std::string& file)
{
	m_Music.push_back(reinterpret_cast<Mix_Music*>(Mix_LoadMUS(file.c_str())));
}

bool Mixer_Sound_System::Play(int soundID, int loops)
{
	// Don't save the channel as a data member, 
	// because when it stops playing the channel becomes free
	// and available for usage by other effects
	if (soundID > m_Sounds.size())
	{
		ME_CORE_WARN("soundID {0} is out of vector reach.");
		return false;
	}
	if (m_Sounds[soundID].first != nullptr)
	{
		int channel{ Mix_PlayChannel(-1, m_Sounds[soundID].first, loops) };
		return channel != -1;
	}
	return false;
}

bool Mixer_Sound_System::PlayMusic(int soundID, bool repeat)
{
	if (soundID > m_Music.size())
	{
		ME_CORE_WARN("soundID {0} is out of vector reach.");
		return false;
	}
	if (m_Music[soundID] != nullptr)
	{
		int result = Mix_PlayMusic(m_Music[soundID],(repeat)? -1 : 1);
		return (result == 0);
	}
	return false;
}

void Mixer_Sound_System::Stop(int soundID)
{
	if (m_Sounds.size() > soundID)
	{
		Mix_HaltChannel(m_Sounds[soundID].second);
	}
}

void Mixer_Sound_System::StopMusic()
{
	Mix_HaltMusic();
}

void Mixer_Sound_System::Pause(int channelID)
{
	Mix_Pause(channelID);
}

void Mixer_Sound_System::PauseAll()
{
	Mix_Pause(-1);
}

void Mixer_Sound_System::PauseMusic()
{
	Mix_PauseMusic();
}

void Mixer_Sound_System::Resume(int channelID)
{
	Mix_Resume(channelID);
}

void Mixer_Sound_System::ResumeAll()
{
	Mix_Resume(-1);
}

void Mixer_Sound_System::ResumeMusic()
{
	Mix_ResumeMusic();
}

void Mixer_Sound_System::StopAllSounds()
{
	Mix_HaltChannel(-1);
}

int Mixer_Sound_System::GetVolumeMusic() const
{
	return Mix_VolumeMusic(-1);
}

int Mixer_Sound_System::GetVolumeSound(int soundID) const
{
	if (m_Sounds[soundID].first != nullptr)
	{
		return Mix_VolumeChunk(m_Sounds[soundID].first, -1);
	}
	else
	{
		return -1;
	}
}

void Mixer_Sound_System::SetVolumeMusic(int value)
{
	Mix_VolumeMusic(value);
}

void Mixer_Sound_System::SetVolumeSound(int soundID, int value)
{
	if (m_Sounds[soundID].first != nullptr)
	{
		Mix_VolumeChunk(m_Sounds[soundID].first, value);
	}
}

bool Mixer_Sound_System::IsPlaying()
{
	return Mix_PlayingMusic() != 0;
}
