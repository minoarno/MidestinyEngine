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
class Grid;
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

	PlayerComponent(Score* pScore, Lives* pLives, dae::ControllerButton upRight, dae::ControllerButton upLeft, dae::ControllerButton downRight, dae::ControllerButton downLeft, int startR, int startC, dae::Scene* pScene);
	PlayerComponent(Score* pScore, Lives* pLives, SDL_Scancode upRight, SDL_Scancode upLeft, SDL_Scancode downRight, SDL_Scancode downLeft, int startR, int startC, dae::Scene* pScene);
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

	void MoveUpRight();
	void MoveUpLeft();
	void MoveDownRight();
	void MoveDownLeft();

	void SetGrid(Grid* pGrid);

	void SetRowAndCol(int row, int col);
private:
	Score* m_pScore = nullptr;
	Lives* m_pLives = nullptr;
	int m_Row = 6;
	int m_Col = 6;
	Grid* m_pGrid = nullptr;
	dae::TextureSpriteSheet* m_pSpriteSheet = nullptr;

	int m_SpriteCounter = 0;
	float m_SpriteTimerCounter = 0.f;
	float m_SpriteTimer = 0.5f;
	FacingDirection m_FacingDirection;
};