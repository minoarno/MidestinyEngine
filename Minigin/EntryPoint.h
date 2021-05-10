#pragma once
#include "Application.h"

#if _DEBUG
// ReSharper disable once CppUnusedIncludeDirective
#include <vld.h>
#endif

#include <iostream>

extern midestiny::Application* midestiny::CreateApplication();

int main(int, char**)
{
	midestiny::Application* app = midestiny::CreateApplication();
	app->Run();
	delete app;
	std::cin.get();
	return 0;
}