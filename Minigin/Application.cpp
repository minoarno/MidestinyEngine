#include "MiniginPCH.h"
#include "Application.h"
#include "Minigin.h"

namespace midestiny
{
	Application::Application() = default;

	Application::~Application() = default;
	
	void Application::Run()
	{
		dae::Minigin engine{};
		engine.Initialize();
		IntializeGame();
		engine.Run();
	}
}
