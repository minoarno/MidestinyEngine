#include "MiniginPCH.h"
#pragma once
#include "Application.h"
#include "Minigin.h"
#include <iostream>

namespace midestiny
{
	Application::Application() = default;

	Application::~Application() = default;
	
	void Application::Run()
	{
		dae::Minigin engine{};
		engine.Run();
	}
}
