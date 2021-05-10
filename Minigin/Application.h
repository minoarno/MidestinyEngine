#pragma once

namespace midestiny
{
	class Application
	{
	public:
		Application();
		Application(const Application& other) = delete;
		Application& operator=(const Application& other) = delete;
		Application(Application&& other) = delete;
		Application& operator=(Application&& other) = delete;
		virtual ~Application();

		virtual void IntializeGame() {};

		void Run();
	};


	//TO BE DEFINED IN CLIENT
	Application* CreateApplication();
}