#include <Midestiny.h>

#include "MainMenu.h"
#include "Multiplayer.h"
#include "Singleplayer.h"
#include "Versus.h"

class Sandbox final : public midestiny::Application
{
public:
	Sandbox() = default;
	~Sandbox() = default;

	void IntializeGame() override
	{
		SceneManager::GetInstance().AddScene(new MainMenu{});
		SceneManager::GetInstance().AddScene(new Singleplayer{});
		SceneManager::GetInstance().AddScene(new Multiplayer{});
		SceneManager::GetInstance().AddScene(new Versus{});

		SceneManager::GetInstance().SetActiveScene(0);

		InputManager::GetInstance().ProcessInput();

		ServiceLocator::GetAudio().AddSound("jump.wav");
		ServiceLocator::GetAudio().SetVolumeSound(0,10);
		ServiceLocator::GetAudio().Play(0,1);

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