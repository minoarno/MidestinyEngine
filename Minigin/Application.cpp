#include "MiniginPCH.h"
#include "Application.h"

#include "Minigin.h"

namespace Midestiny
{
	Application::Application()
	{

	}

	Application::~Application()
	{

	}
	
	void Application::Run()
	{
		dae::Minigin engine{};
		engine.Run();
	}
}
