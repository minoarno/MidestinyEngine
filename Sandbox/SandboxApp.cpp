#include <Midestiny.h>

#include "MainMenu.h"
#include "Multiplayer.h"
#include "Singleplayer.h"

class Sandbox final : public midestiny::Application
{
public:
	Sandbox() = default;
	~Sandbox() = default;

	void IntializeGame() override
	{
		SceneManager::GetInstance().AddScene(new MainMenu{});
		SceneManager::GetInstance().AddScene(new Multiplayer{});
		SceneManager::GetInstance().AddScene(new Singleplayer{});

		SceneManager::GetInstance().SetActiveScene(0);

		//ServiceLocator::GetAudio().AddSound("../Data/Cork.wav");

		InputManager::GetInstance().ProcessInput();
	}

	Sandbox(const Sandbox& other) = delete;
	Sandbox& operator=(const Sandbox& other) = delete;
	Sandbox(Sandbox&& other) = delete;
	Sandbox& operator=(Sandbox&& other) = delete;
};

midestiny::Application* midestiny::CreateApplication()
{
	return new Sandbox();
}