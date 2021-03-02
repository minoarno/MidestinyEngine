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
#include "Time.h"

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
}

/**
 * Code constructing the scene world starts here
 */
void dae::Minigin::LoadGame() const
{
	Scene& scene = SceneManager::GetInstance().CreateScene("Demo");

	GameObject* go = new GameObject();
	go->SetTexture("background.jpg");
	scene.Add(go);

	GameObject* go2 = new GameObject();
	go2->SetTexture("logo.png");
	go2->SetPosition(216, 180);
	scene.Add(go2);

	Font* font = ResourceManager::GetInstance().LoadFont("Lingua.otf", 36);
	GameObject* to = new GameObject();
	to->AddComponent(new TextComponent{font,"Midestiny Engine" });
	to->SetPosition(80, 20);
	scene.Add(to);
	
	GameObject* to2 = new GameObject();
	to2->AddComponent(new FPSComponent{font});
	to2->SetPosition(80, 80);
	scene.Add(to2);
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
	Initialize();

	// tell the resource manager where he can find the game data
	ResourceManager::GetInstance().Init("../Data/");

	LoadGame();

	{
		Renderer& renderer = Renderer::GetInstance();
		SceneManager& sceneManager = SceneManager::GetInstance();
		InputManager& input = InputManager::GetInstance();

		double lag = 0.0f;

		time_point<high_resolution_clock> lastTime = high_resolution_clock::now();
		
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
