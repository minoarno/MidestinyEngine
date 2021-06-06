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

	GameObject* player1 = new GameObject();
	Lives* pLives1 = new Lives(3);
	Score* pScore1 = new Score();
	pLives1->AddObserver(observerL1);
	pScore1->AddObserver(observerS1);
	PlayerComponent* playerComponent = new PlayerComponent(pScore1, pLives1, SDL_SCANCODE_UP, SDL_SCANCODE_RIGHT, SDL_SCANCODE_DOWN, SDL_SCANCODE_LEFT, 6, 0);
	player1->AddComponent(playerComponent);
	Add(player1);

	dae::GameObject* levelGrid = new dae::GameObject();
	levelGrid->AddComponent(new Grid{ 7, 20.f });
	levelGrid->SetPosition(860, 200);
	Add(levelGrid);
}

Singleplayer::~Singleplayer()
{
}
