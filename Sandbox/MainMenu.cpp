#include "MainMenu.h"
#include "SceneManager.h"
#include "Button.h"
#include "ResourceManager.h"
#include "FunctionCommand.h"
#include "GameObject.h"
#include "TextComponent.h"

using namespace dae;

MainMenu::MainMenu()
	:Scene{"MainMenu"}
{
	Font* font = ResourceManager::GetInstance().LoadFont("Lingua.otf", 36);

	GameObject* pSinglePlayer = new GameObject{};
	pSinglePlayer->GetComponent<dae::Transform>()->SetPosition(400,100,0);
	FunctionCommand* pStartSingleplayerCommand = new FunctionCommand{};
	pStartSingleplayerCommand->SetFunction(std::bind(&MainMenu::StartSinglePlayer, this));
	Button* pButtonSingleplayer = new Button{pStartSingleplayerCommand};
	pButtonSingleplayer->SetSize(220, 60);
	pSinglePlayer->AddComponent(pButtonSingleplayer);
	pSinglePlayer->AddComponent(new TextComponent{ font,"SinglePlayer" });
	Add(pSinglePlayer);

	GameObject* pMultiPlayer = new GameObject{};
	pMultiPlayer->GetComponent<dae::Transform>()->SetPosition(400,300,0);
	FunctionCommand* pStartMultiplayer = new FunctionCommand{};
	pStartMultiplayer->SetFunction(std::bind(&MainMenu::StartMultiplayer, this));
	Button* pButtonMultiplayer = new Button{ pStartMultiplayer };
	pButtonMultiplayer->SetSize(200, 60);
	pMultiPlayer->AddComponent(pButtonMultiplayer);
	pMultiPlayer->AddComponent(new TextComponent{ font,"Multiplayer" });
	Add(pMultiPlayer);

	GameObject* pVersus = new GameObject{};
	pVersus->GetComponent<dae::Transform>()->SetPosition(400,500,0);
	FunctionCommand* pStartVersus = new FunctionCommand{};
	pStartVersus->SetFunction(std::bind(&MainMenu::StartVersus, this));
	Button* pButtonVersus = new Button{ pStartVersus };
	pButtonVersus->SetSize(120, 60);
	pVersus->AddComponent(new TextComponent{ font,"Versus" });
	pVersus->AddComponent(pButtonVersus);
	Add(pVersus);
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
