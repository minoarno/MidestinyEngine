#include "MiniginPCH.h"
#include <SDL_mixer.h>
#include "Audio.h"

Mixer_Sound_System::~Mixer_Sound_System()
{
	StopAllSounds();
	Mix_CloseAudio();

	for (size_t i = 0; i < m_Music.size(); i++)
	{
		Mix_FreeMusic(m_Music[i]); 
		m_Music[i] = nullptr;
	}
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
	if (m_Sounds[soundID].first != nullptr)
	{
		int channel{ Mix_PlayChannel(-1, m_Sounds[soundID].first, loops) };
		return channel != -1;
	}
	return false;
}

bool Mixer_Sound_System::PlayMusic(int soundID, bool repeat)
{
	if (m_Sounds.size() > soundID && m_Sounds[soundID].first != nullptr)
	{
		int result = m_Sounds[soundID].second = Mix_PlayMusic(m_Music[soundID],(repeat)? -1 : 1);
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

void Mixer_Sound_System::SetVolumeMusic(int value)
{
	Mix_VolumeMusic(value);
}

bool Mixer_Sound_System::IsPlaying()
{
	return Mix_PlayingMusic() != 0;
}
