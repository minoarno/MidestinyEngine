#pragma once
#include "Core.h"

namespace midestiny
{
	class MIDESTINYENGINE_API Application
	{
	public:
		Application();
		Application(const Application& other) = delete;
		Application& operator=(const Application& other) = delete;
		Application(Application&& other) = delete;
		Application& operator=(Application&& other) = delete;
		virtual ~Application();

		static void Run();
	};

	//TO BE DEFINED IN CLIENT
	Application* CreateApplication();
}