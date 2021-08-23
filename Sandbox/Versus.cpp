#pragma once
#include "Versus.h"
#include "GameObject.h"

#include "Score.h"
#include "ScoreObserver.h"
#include "Lives.h"
#include "LiveObserver.h"
#include "PlayerComponent.h"
#include "FPSComponent.h"
#include "Font.h"
#include "ResourceManager.h"
#include "BoxCollider.h"

#include "EnemyManager.h"

using namespace dae;

Versus::Versus()
	: dae::Scene{"Versus"}
{
	float size = 50.f;

	Font* font = ResourceManager::GetInstance().LoadFont("Lingua.otf", 36);

	GameObject* go = new GameObject();
	go->SetTexture("background.jpg");
	go->GetComponent<dae::Texture2D>()->SetSize(1280, 960);
	Add(go);

	GameObject* go2 = new GameObject();
	go2->SetTexture("logo.png");
	go2->SetPosition(216, 180);
	Add(go2);

	GameObject* lives = new GameObject();
	TextComponent* textL = new TextComponent{ font , "Lives: 3" };
	LiveObserver* observerL = new LiveObserver(textL);
	lives->AddComponent(textL);
	lives->AddComponent(observerL);
	lives->SetPosition(80, 420);
	Add(lives);

	GameObject* score = new GameObject();
	TextComponent* textS = new TextComponent{ font , "Score: 0" };
	ScoreObserver* observerS = new ScoreObserver(textS);
	score->AddComponent(textS);
	score->AddComponent(observerS);
	score->SetPosition(80, 500);
	Add(score);

	GameObject* player = new GameObject();
	Lives* pLives = new Lives(3);
	Score* pScore = new Score();
	pLives->AddObserver(observerL);
	pScore->AddObserver(observerS);

	PlayerComponent* playerComponent = new PlayerComponent{ pScore, pLives, dae::ControllerButton::DPadUp, dae::ControllerButton::DPadLeft, dae::ControllerButton::DPadDown, dae::ControllerButton::DPadRight,dae::ControllerButton::ButtonA,  this, player };
	player->AddComponent(playerComponent);
	playerComponent->SetGameObject(player);
	player->SetTexture("SpaceShip.png", 2, 1);
	player->SetPosition(500, 700);
	player->AddComponent(new BoxCollider(size, size));
	Add(player);

	m_pEnemyManager = new EnemyManager(this, 500, 300);
	m_pEnemyManager->LoadFromFile("../Data/Waves/Wave1.txt");
}

Versus::~Versus()
{
}

void Versus::Initialize()
{
}

void Versus::FixedUpdate()
{
}

void Versus::Update()
{
	m_pEnemyManager->Update();
}

void Versus::LateUpdate()
{
}

void Versus::Render() const
{
}

void Versus::Unload()
{
}
