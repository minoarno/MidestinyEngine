#pragma once
#include "InputManager.h"
#include "BaseComponent.h"
#include "Lives.h"
#include "Score.h"

class Grid;
class PlayerComponent final : public BaseComponent
{
public:
	PlayerComponent(Score* pScore, Lives* pLives, dae::ControllerButton upRight, dae::ControllerButton upLeft, dae::ControllerButton downRight, dae::ControllerButton downLeft, int startR, int startC);
	PlayerComponent(Score* pScore, Lives* pLives, SDL_Scancode upRight, SDL_Scancode upLeft, SDL_Scancode downRight, SDL_Scancode downLeft, int startR, int startC);
	PlayerComponent(const PlayerComponent& other) = delete;
	PlayerComponent& operator=(const PlayerComponent& other) = delete;
	PlayerComponent(PlayerComponent&& other) = delete;
	PlayerComponent& operator=(PlayerComponent&& other) = delete;
	~PlayerComponent() = default;

	void Initialize() override;

	void IncrementScore();
	void GainLife();
	void LoseLife();

	void MoveUpRight();
	void MoveUpLeft();
	void MoveDownRight();
	void MoveDownLeft();

	void SetGrid(Grid* pGrid) { m_pGrid = pGrid; }
private:
	Score* m_pScore = nullptr;
	Lives* m_pLives = nullptr;
	int m_Row;
	int m_Col;
	Grid* m_pGrid;
};