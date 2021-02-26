#pragma once
#include "Core.h"

namespace Midestiny
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

		void Run();
	private:
		
	};

	//TO BE DEFINED IN CLIENT
	Application* CreateApplication();
}