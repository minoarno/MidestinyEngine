#pragma once
#include "Application.h"
#include "Log.h"

#if _DEBUG
// ReSharper disable once CppUnusedIncludeDirective
#include <vld.h>
#endif

#include <iostream>

extern midestiny::Application* midestiny::CreateApplication();

int main(int, char**)
{
	midestiny::Log::Initialize();
	ME_CORE_INFO("Intilialized Log!");

	midestiny::Application* app = midestiny::CreateApplication();
	app->Run();
	delete app;
	std::cin.get();
	return 0;
}