#include "Singleplayer.h"
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

	PlayerComponent* playerComponent = new PlayerComponent{ pScore, pLives, dae::ControllerButton::DPadUp, dae::ControllerButton::DPadLeft, dae::ControllerButton::DPadDown, dae::ControllerButton::DPadRight,this };

	player->AddComponent(playerComponent);
	player->SetTexture("Qbert.png",8,1);
	Add(player);
}

Singleplayer::~Singleplayer()
{
}
