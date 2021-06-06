#include "MainMenu.h"
#include "SceneManager.h"

using namespace dae;

MainMenu::MainMenu()
	:Scene{"MainMenu"}
{
}

MainMenu::~MainMenu()
{
}

void MainMenu::Initialize()
{
}

void MainMenu::StartSinglePlayer()
{
	SceneManager::GetInstance().SetActiveScene(1);
}

void MainMenu::StartMultiplayer()
{
	SceneManager::GetInstance().SetActiveScene(2);
}

void MainMenu::StartVersus()
{
	SceneManager::GetInstance().SetActiveScene(3);
}

void MainMenu::QuitGame()
{
}
