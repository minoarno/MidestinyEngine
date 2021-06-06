#include "Singleplayer.h"
#include "Grid.h"
#include "GameObject.h"
#include "Texture2D.h"
#include "Lives.h"
#include "Score.h"
#include "PlayerComponent.h"
#include "TextComponent.h"
#include "LiveObserver.h"
#include "ScoreObserver.h"
#include "ResourceManager.h"

using namespace dae;

Singleplayer::Singleplayer()
	: Scene{"Singleplayer"}
{
	Font* font = ResourceManager::GetInstance().LoadFont("Lingua.otf", 36);

	GameObject* go = new GameObject();
	go->SetTexture("background.jpg");
	go->GetComponent<dae::Texture2D>()->SetSize(1280, 960);
	Add(go);

	GameObject* go2 = new GameObject();
	go2->SetTexture("logo.png");
	go2->SetPosition(216, 180);
	Add(go2);

	GameObject* levelGrid = new GameObject();
	Grid* pGrid = new Grid{ 7, 20.f };
	levelGrid->AddComponent(pGrid);
	levelGrid->SetPosition(500, 200);
	Add(levelGrid);

	GameObject* lives1 = new GameObject();
	TextComponent* textL1 = new TextComponent{ font , "Lives: 5" };
	LiveObserver* observerL1 = new LiveObserver(textL1);
	lives1->AddComponent(textL1);
	lives1->AddComponent(observerL1);
	lives1->SetPosition(80, 420);
	Add(lives1);

	GameObject* score1 = new GameObject();
	TextComponent* textS1 = new TextComponent{ font , "Score: 0" };
	ScoreObserver* observerS1 = new ScoreObserver(textS1);
	score1->AddComponent(textS1);
	score1->AddComponent(observerS1);
	score1->SetPosition(80, 500);
	Add(score1);

	GameObject* player = new GameObject();
	Lives* pLives = new Lives(3);
	Score* pScore = new Score();
	pLives->AddObserver(observerL1);
	pScore->AddObserver(observerS1);
	PlayerComponent* playerComponent = new PlayerComponent{ pScore, pLives, dae::ControllerButton::DPadUp, dae::ControllerButton::DPadLeft, dae::ControllerButton::DPadRight, dae::ControllerButton::DPadDown,6,6 };
	playerComponent->SetGrid(pGrid);
	player->AddComponent(playerComponent);
	player->SetTexture("Qbert.png",8,1);
	Add(player);
}

Singleplayer::~Singleplayer()
{
}
