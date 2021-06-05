#pragma once
#include "Scene.h"

class MainMenu final : public dae::Scene
{
public:
	MainMenu();
	MainMenu& operator=(const MainMenu& other) = delete;
	MainMenu(const MainMenu& other) = delete;
	MainMenu& operator=(MainMenu&& other) = delete;
	MainMenu(MainMenu&& other) = delete;
	~MainMenu();
private:

};

