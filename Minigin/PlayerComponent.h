#pragma once
#include "InputManager.h"
#include "BaseComponent.h"
#include "Lives.h"
#include "Score.h"
class PlayerComponent final : public BaseComponent
{
public:
	PlayerComponent(Score* pScore, Lives* pLives, dae::ControllerButton incrementScore, dae::ControllerButton die);
	PlayerComponent(const PlayerComponent& other) = delete;
	PlayerComponent& operator=(const PlayerComponent& other) = delete;
	PlayerComponent(PlayerComponent&& other) = delete;
	PlayerComponent& operator=(PlayerComponent&& other) = delete;
	~PlayerComponent() = default;

	void IncrementScore();
	void GainLife();
	void LoseLife();
private:
	Score* m_pScore = nullptr;
	Lives* m_pLives = nullptr;
};