#include "Multiplayer.h"

#include "Score.h"
#include "ScoreObserver.h"
#include "Lives.h"
#include "LiveObserver.h"
#include "PlayerComponent.h"
#include "GameObject.h"
#include "FPSComponent.h"
#include "Font.h"
#include "ResourceManager.h"

#include "EnemyManager.h"

using namespace dae;

Multiplayer::Multiplayer()
	:Scene{ "Multiplayer" }
{
	GameObject* go = new GameObject();
	go->SetTexture("background.jpg");
	go->GetComponent<dae::Texture2D>()->SetSize(1280, 960);
	Add(go);

	GameObject* go2 = new GameObject();
	go2->SetTexture("logo.png");
	go2->SetPosition(216, 180);
	Add(go2);

	Font* font = ResourceManager::GetInstance().LoadFont("Lingua.otf", 36);
	GameObject* to = new GameObject();
	to->AddComponent(new TextComponent{ font,"Midestiny Engine" });
	to->SetPosition(80, 20);
	Add(to);

	GameObject* to2 = new GameObject();
	to2->AddComponent(new FPSComponent{ font });
	to2->SetPosition(80, 80);
	Add(to2);

	GameObject* lives1 = new GameObject();
	TextComponent* textL1 = new TextComponent{ font , "Lives: 3" };
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

	PlayerComponent* playerComponent = new PlayerComponent{ pScore1, pLives1, SDL_SCANCODE_W, SDL_SCANCODE_A, SDL_SCANCODE_S, SDL_SCANCODE_D, this, player1 };
	player1->AddComponent(playerComponent);
	playerComponent->SetGameObject(player1);
	player1->SetTexture("SpaceShip.png", 2, 1);
	player1->SetPosition(400, 700);
	Add(player1);

	GameObject* lives2 = new GameObject();
	TextComponent* textL2 = new TextComponent{ font , "Lives: 3" };
	LiveObserver* observerL2 = new LiveObserver(textL2);
	lives2->AddComponent(textL2);
	lives2->AddComponent(observerL2);
	lives2->SetPosition(300, 420);
	Add(lives2);

	GameObject* score2 = new GameObject();
	TextComponent* textS2 = new TextComponent{ font , "Score: 0" };
	ScoreObserver* observerS2 = new ScoreObserver(textS2);
	score2->AddComponent(textS2);
	score2->AddComponent(observerS2);
	score2->SetPosition(300, 500);
	Add(score2);

	GameObject* player2 = new GameObject();
	Lives* pLives2 = new Lives(3);
	Score* pScore2 = new Score();
	pLives2->AddObserver(observerL2);
	pScore2->AddObserver(observerS2);

	PlayerComponent* playerComponent2 = new PlayerComponent{pScore2, pLives2, dae::ControllerButton::DPadUp, dae::ControllerButton::DPadLeft, dae::ControllerButton::DPadDown, dae::ControllerButton::DPadRight, this,player2 };
	player2->AddComponent(playerComponent2);
	player2->SetTexture("SpaceShip.png", 2, 1);
	player2->SetPosition(700, 700);

	Add(player2);

	m_pEnemyManager = new EnemyManager(this, 500, 300);
	m_pEnemyManager->LoadFromFile("../Data/Waves/Wave1.txt");
}

Multiplayer::~Multiplayer()
{
}

void Multiplayer::Update()
{
	m_pEnemyManager->Update();
}
