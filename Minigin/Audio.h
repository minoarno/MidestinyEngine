#pragma once
#include <vector>
#include <iostream>


class Audio
{
public:
	virtual void AddSound(const std::string& file) = 0;
	virtual void AddMusic(const std::string& file) = 0;

	virtual bool Play(int soundID, int loops) = 0;
	virtual bool PlayMusic(int soundID, bool repeat = false) = 0;
	virtual void Stop(int soundID) = 0;
	virtual void StopMusic() = 0;
	virtual void StopAllSounds() = 0;

	//Pause
	virtual void Pause(int channelID) = 0;
	virtual void PauseAll() = 0;
	virtual void PauseMusic() = 0;

	//Resume
	virtual void Resume(int channelID) = 0;
	virtual void ResumeAll() = 0;
	virtual void ResumeMusic() = 0;

	virtual int GetVolumeMusic()const = 0;
	virtual void SetVolumeMusic(int value) = 0;
	virtual bool IsPlaying() = 0;
};

struct Mix_Chunk;
typedef struct _Mix_Music Mix_Music;
class Mixer_Sound_System : public Audio
{
public:
	Mixer_Sound_System() = default;
	~Mixer_Sound_System();

	virtual void AddSound(const std::string& file) override;
	virtual void AddMusic(const std::string& file) override;

	virtual bool Play(int soundID, int loops) override;
	virtual bool PlayMusic(int soundID, bool repeat = false) override;
	
	virtual void Stop(int channelID) override;
	virtual void StopMusic() override;
	virtual void StopAllSounds() override;

	//Pause
	virtual void Pause(int channelID) override;
	virtual void PauseAll() override;
	virtual void PauseMusic() override;
	
	//Resume
	virtual void Resume(int channelID) override;
	virtual void ResumeAll() override;
	virtual void ResumeMusic() override;

	virtual int GetVolumeMusic()const override;
	virtual void SetVolumeMusic(int value) override;
	virtual bool IsPlaying() override;
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

	virtual bool Play(int,int) override { return false; }
	virtual bool PlayMusic(int, bool) override { return false; }

	virtual void Stop(int) override { }
	virtual void StopMusic() override { }
	virtual void StopAllSounds() override { }

	//Pause
	virtual void Pause(int) override { };
	virtual void PauseAll() override { };
	virtual void PauseMusic() override { };

	//Resume
	virtual void Resume(int) override { };
	virtual void ResumeAll() override { };
	virtual void ResumeMusic() override { };

	virtual int GetVolumeMusic()const override { return 0; };
	virtual void SetVolumeMusic(int) override { };
	virtual bool IsPlaying() override { return false; };
};
