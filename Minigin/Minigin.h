#pragma once
class Mixer_Sound_System;
struct SDL_Window;
namespace dae
{
	class Minigin
	{
	public:
		~Minigin();
		void Initialize();
		void Cleanup();
		void Run();
	private:
		static const int MsPerFrame = 16; //16 for 60 fps, 33 for 30 fps
		SDL_Window* m_Window{};
		Mixer_Sound_System* m_pSoundSystem = nullptr;
	};
}