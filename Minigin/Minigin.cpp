#include "MiniginPCH.h"
#include "Minigin.h"
#include <chrono>
#include <thread>
#include "InputManager.h"
#include "SceneManager.h"
#include "Renderer.h"
#include "ResourceManager.h"

#include "GameObject.h"
#include "Scene.h"
#include "TextComponent.h"
#include "FPSComponent.h"
#include "MeTime.h"

#include "Audio.h"
#include "ServiceLocator.h"

using namespace std;
using namespace std::chrono;

dae::Minigin::~Minigin()
{
	Cleanup();
}

void dae::Minigin::Initialize()
{
	if (SDL_Init(SDL_INIT_VIDEO) != 0) 
	{
		throw std::runtime_error(std::string("SDL_Init Error: ") + SDL_GetError());
	}

	m_Window = SDL_CreateWindow(
		"Programming 4 assignment - Poppe Arno",
		SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,
		1280,
		960,
		SDL_WINDOW_OPENGL
	);
	if (m_Window == nullptr) 
	{
		throw std::runtime_error(std::string("SDL_CreateWindow Error: ") + SDL_GetError());
	};
	
	Renderer::GetInstance().Init(m_Window);
	ServiceLocator::Initialize();

	m_pSoundSystem = new Mixer_Sound_System{};
	ServiceLocator::RegisterSoundSystem(m_pSoundSystem);

	// tell the resource manager where he can find the game data
	ResourceManager::GetInstance().Init("../Data/");
}

void dae::Minigin::Cleanup()
{
	Renderer::GetInstance().Destroy();
	ResourceManager::GetInstance().CleanUp();
	SDL_DestroyWindow(m_Window);
	m_Window = nullptr;
	SDL_Quit();
}

void dae::Minigin::Run()
{
	{
		Renderer& renderer = Renderer::GetInstance();
		SceneManager& sceneManager = SceneManager::GetInstance();
		InputManager& input = InputManager::GetInstance();

		double lag = 0.0f;

		time_point<high_resolution_clock> lastTime = high_resolution_clock::now();
		
		sceneManager.InitializeActiveScene();

		bool doContinue = true;
		while (doContinue)
		{
			const time_point<high_resolution_clock> currentTime = high_resolution_clock::now();
			const double elapsed = duration_cast<duration<double>>(currentTime - lastTime).count();

			//Saves the current elapsed time inside of the time singleton.
			Time::GetInstance().SetElapsedSeconds(elapsed);
			double elapsedFromTime = Time::GetInstance().GetElapsedSeconds();
			lastTime = currentTime;
			lag += elapsedFromTime;
			
			doContinue = input.ProcessInput();
			
			while (lag >= MsPerFrame)
			{
				sceneManager.FixedUpdate();
				lag -= MsPerFrame;
			}
			sceneManager.Update();
			sceneManager.LateUpdate();
			
			renderer.Render();

			auto sleepTime = duration_cast<duration<double>>(currentTime + milliseconds(MsPerFrame) - high_resolution_clock::now());
			this_thread::sleep_for(sleepTime);
		}
	}
}
