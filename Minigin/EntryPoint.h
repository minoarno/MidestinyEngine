#pragma once
#include "Application.h"
#include <iostream>
#ifdef ME_PLATFORM_WINDOWS

extern midestiny::Application* midestiny::CreateApplication();

int main(int argc, char** argv)
{
	midestiny::Application* app = midestiny::CreateApplication();
	app->Run();
	delete app;
	std::cin.get();
	return 0;
}

#endif