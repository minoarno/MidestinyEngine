#pragma once
#ifdef ME_PLATFORM_WINDOWS

extern Midestiny::Application* Midestiny::CreateApplication();

int main(int argc, char** argv)
{
	auto* app = Midestiny::CreateApplication();
	app->Run();
	delete app;
	return 0;
}

#endif