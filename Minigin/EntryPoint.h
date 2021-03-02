#pragma once
#include "Application.h"
#include <iostream>
#ifdef ME_PLATFORM_WINDOWS

extern Midestiny::Application* Midestiny::CreateApplication();

int main(int argc, char** argv)
{
	Midestiny::Application* app = Midestiny::CreateApplication();
	app->Run();
	delete app;
	std::cin.get();
	return 0;
}

#endif