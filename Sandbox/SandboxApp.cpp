#include <Midestiny.h>

#include "Score.h"
#include "ScoreObserver.h"
#include "Lives.h"
#include "LiveObserver.h"
#include "PlayerComponent.h"
#include "Grid.h"

class Sandbox final : public midestiny::Application
{
public:
	Sandbox() = default;
	~Sandbox() = default;

	void IntializeGame() override
	{
		Scene& scene = SceneManager::GetInstance().CreateScene("StartScene");

		//ServiceLocator::GetAudio().AddSound("../Data/Cork.wav");

		GameObject* go = new GameObject();
		go->SetTexture("background.jpg");
		scene.Add(go);

		GameObject* go2 = new GameObject();
		go2->SetTexture("logo.png");
		go2->SetPosition(216, 180);
		scene.Add(go2);

		Font* font = ResourceManager::GetInstance().LoadFont("Lingua.otf", 36);
		GameObject* to = new GameObject();
		to->AddComponent(new TextComponent{ font,"Midestiny Engine" });
		to->SetPosition(80, 20);
		scene.Add(to);

		GameObject* to2 = new GameObject();
		to2->AddComponent(new FPSComponent{ font });
		to2->SetPosition(80, 80);
		scene.Add(to2);

		GameObject* lives1 = new GameObject();
		TextComponent* textL1 = new TextComponent{ font , "Lives: 5" };
		LiveObserver* observerL1 = new LiveObserver(textL1);
		lives1->AddComponent(textL1);
		lives1->AddComponent(observerL1);
		lives1->SetPosition(80, 420);
		scene.Add(lives1);

		GameObject* lives2 = new GameObject();
		TextComponent* textL2 = new TextComponent{ font , "Lives: 5" };
		LiveObserver* observerL2 = new LiveObserver(textL2);
		lives2->AddComponent(textL2);
		lives2->AddComponent(observerL2);
		lives2->SetPosition(300, 420);
		scene.Add(lives2);

		GameObject* score1 = new GameObject();
		TextComponent* textS1 = new TextComponent{ font , "Score: 0" };
		ScoreObserver* observerS1 = new ScoreObserver(textS1);
		score1->AddComponent(textS1);
		score1->AddComponent(observerS1);
		score1->SetPosition(80, 500);
		scene.Add(score1);

		GameObject* score2 = new GameObject();
		TextComponent* textS2 = new TextComponent{ font , "Score: 0" };
		ScoreObserver* observerS2 = new ScoreObserver(textS2);
		score2->AddComponent(textS2);
		score2->AddComponent(observerS2);
		score2->SetPosition(300, 500);
		scene.Add(score2);

		GameObject* player1 = new GameObject();
		Lives* pLives1 = new Lives(5);
		Score* pScore1 = new Score();
		pLives1->AddObserver(observerL1);
		pScore1->AddObserver(observerS1);
		PlayerComponent* playerComponent = new PlayerComponent(pScore1, pLives1, dae::ControllerButton::ButtonA, dae::ControllerButton::ButtonB);
		player1->AddComponent(playerComponent);
		scene.Add(player1);

		GameObject* player2 = new GameObject();
		Lives* pLives2 = new Lives(5);
		Score* pScore2 = new Score();
		pLives2->AddObserver(observerL2);
		pScore2->AddObserver(observerS2);
		player2->AddComponent(new PlayerComponent(pScore2, pLives2, dae::ControllerButton::DPadUp, dae::ControllerButton::DPadDown));
		scene.Add(player2);

		dae::GameObject* to3 = new dae::GameObject();
		to3->AddComponent(new TextComponent{ font,"Player 1 - Button B : increase score - Button A : lose live" });
		to3->SetPosition(80, 300);
		scene.Add(to3);

		dae::GameObject* to4 = new dae::GameObject();
		to4->AddComponent(new TextComponent{ font,"Player 2 - DPAD DOWN : increase score - DPAD UP : lose live" });
		to4->SetPosition(80, 360);
		scene.Add(to4);

		dae::GameObject* level = new dae::GameObject();
		level->AddComponent(new Grid{ 7, 20.f });
		scene.Add(level);
		

		InputManager::GetInstance().ProcessInput();
	}

	Sandbox(const Sandbox& other) = delete;
	Sandbox& operator=(const Sandbox& other) = delete;
	Sandbox(Sandbox&& other) = delete;
	Sandbox& operator=(Sandbox&& other) = delete;
};

midestiny::Application* midestiny::CreateApplication()
{
	return new Sandbox();
}