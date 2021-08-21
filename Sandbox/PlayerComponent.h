#pragma once
#include "InputManager.h"
#include "BaseComponent.h"

namespace dae
{
	class TextureSpriteSheet;
	class Scene;
}
class Lives;
class Score;
class PlayerComponent final : public BaseComponent
{
public:
	enum class FacingDirection : int
	{
		upRight = 0,
		upLeft = 2,
		downRight = 4,
		downLeft = 6
	};

	PlayerComponent(Score* pScore, Lives* pLives, dae::ControllerButton up, dae::ControllerButton left, dae::ControllerButton down, dae::ControllerButton right, dae::Scene* pScene);
	PlayerComponent(Score* pScore, Lives* pLives, SDL_Scancode up, SDL_Scancode left, SDL_Scancode down, SDL_Scancode right, dae::Scene* pScene);
	PlayerComponent(const PlayerComponent& other) = delete;
	PlayerComponent& operator=(const PlayerComponent& other) = delete;
	PlayerComponent(PlayerComponent&& other) = delete;
	PlayerComponent& operator=(PlayerComponent&& other) = delete;
	~PlayerComponent() {};

	void Initialize() override;

	void IncrementScore();
	void GainLife();
	void LoseLife();

	void Update() override;
private:
	Score* m_pScore = nullptr;
	Lives* m_pLives = nullptr;

	dae::TextureSpriteSheet* m_pSpriteSheet = nullptr;

	int m_SpriteCounter = 0;
	float m_SpriteTimerCounter = 0.f;
	float m_SpriteTimer = 0.5f;
	FacingDirection m_FacingDirection;
};