#include "PlayerComponent.h"
#include "Input.h"
#include <functional>
#include "ServiceLocator.h"
#include "Audio.h"

#include "Lives.h"
#include "Score.h"

#include "Grid.h"
#include "Tile.h"

#include "GameObject.h"
#include "TextureSpriteSheet.h"
#include "MeTime.h"

using namespace dae;

PlayerComponent::PlayerComponent(Score* pScore, Lives* pLives, dae::ControllerButton upRight, dae::ControllerButton upLeft, dae::ControllerButton downRight, dae::ControllerButton downLeft, int startR, int startC)
	: BaseComponent()
	, m_pScore{ pScore }
	, m_pLives{ pLives }
	, m_Col{ startC }
	, m_Row{ startR }
	, m_pGrid{ nullptr }
{
	FunctionCommand* commandUpRight = new FunctionCommand();
	commandUpRight->SetFunctionOnRelease(std::bind(&PlayerComponent::MoveUpRight, this));
	dae::InputManager::GetInstance().AddInput(upRight, commandUpRight);

	FunctionCommand* commandUpLeft = new FunctionCommand();
	commandUpLeft->SetFunctionOnRelease(std::bind(&PlayerComponent::MoveUpLeft, this));
	dae::InputManager::GetInstance().AddInput(upLeft, commandUpLeft);

	FunctionCommand* commandDownRight = new FunctionCommand();
	commandDownRight->SetFunctionOnRelease(std::bind(&PlayerComponent::MoveDownRight, this));
	dae::InputManager::GetInstance().AddInput(downRight, commandDownRight);

	FunctionCommand* commandDownLeft = new FunctionCommand();
	commandDownLeft->SetFunctionOnRelease(std::bind(&PlayerComponent::MoveDownLeft, this));
	dae::InputManager::GetInstance().AddInput(downLeft, commandDownLeft);
}

PlayerComponent::PlayerComponent(Score* pScore, Lives* pLives, SDL_Scancode upRight, SDL_Scancode upLeft, SDL_Scancode downRight, SDL_Scancode downLeft, int startR, int startC)
	: BaseComponent()
	, m_pScore{ pScore }
	, m_pLives{ pLives }
	, m_Col{ startC }
	, m_Row{ startR }
	, m_pGrid{ nullptr }
{
	FunctionCommand* commandUpRight = new FunctionCommand();
	commandUpRight->SetFunctionOnRelease(std::bind(&PlayerComponent::MoveUpRight, this));
	InputManager::GetInstance().AddInput(upRight, commandUpRight);

	FunctionCommand* commandUpLeft = new FunctionCommand();
	commandUpLeft->SetFunctionOnRelease(std::bind(&PlayerComponent::MoveUpLeft, this));
	InputManager::GetInstance().AddInput(upLeft, commandUpLeft);

	FunctionCommand* commandDownRight = new FunctionCommand();
	commandDownRight->SetFunctionOnRelease(std::bind(&PlayerComponent::MoveDownRight, this));
	dae::InputManager::GetInstance().AddInput(downRight, commandDownRight);

	FunctionCommand* commandDownLeft = new FunctionCommand();
	commandDownLeft->SetFunctionOnRelease(std::bind(&PlayerComponent::MoveDownLeft, this));
	dae::InputManager::GetInstance().AddInput(downLeft, commandDownLeft);
}

void PlayerComponent::Initialize()
{
	m_pSpriteSheet = m_pGameObject->GetComponent<dae::TextureSpriteSheet>();
	glm::vec3 pos = m_pGrid->GetTile(m_Row, m_Col)->GetPosition();
	m_pGameObject->GetComponent<dae::Transform>()->SetPosition(pos.x, pos.y, pos.z);
}

void PlayerComponent::IncrementScore()
{
	m_pScore->IncreaseScore(50);
	ServiceLocator::GetAudio().Play(0);
}
void PlayerComponent::GainLife()
{
	m_pLives->GainLife();
}
void PlayerComponent::LoseLife()
{
	m_pLives->LoseLife();
}

void PlayerComponent::Update()
{
	m_SpriteTimerCounter += float(Time::GetInstance().GetElapsedSeconds());
	if (m_SpriteTimerCounter > m_SpriteTimer)
	{
		++m_SpriteCounter %= 2;
		m_SpriteTimerCounter = 0.f;
		m_pSpriteSheet->SetIndex(int(m_FacingDirection) + m_SpriteCounter);
	}
}

void PlayerComponent::MoveUpRight()
{
	if (m_pGrid->MoveUpRight(m_Row,m_Col))
	{
		Tile* pTile = m_pGrid->GetTile(m_Row, m_Col);
		pTile->SetHasBeenWalkedOn(true);
		glm::vec3 pos = pTile->GetPosition();
		m_pGameObject->GetComponent<dae::Transform>()->SetPosition(pos.x, pos.y, pos.z);
	}
	m_pSpriteSheet->SetIndex(int(m_FacingDirection) + m_SpriteCounter);
}

void PlayerComponent::MoveUpLeft()
{
	if (m_pGrid->MoveUpLeft(m_Row, m_Col))
	{
		Tile* pTile = m_pGrid->GetTile(m_Row, m_Col);
		pTile->SetHasBeenWalkedOn(true);
		glm::vec3 pos = pTile->GetPosition();
		m_pGameObject->GetComponent<dae::Transform>()->SetPosition(pos.x, pos.y, pos.z);
	}
	m_pSpriteSheet->SetIndex(int(m_FacingDirection) + m_SpriteCounter);
}

void PlayerComponent::MoveDownRight()
{
	if (m_pGrid->MoveDownRight(m_Row, m_Col))
	{
		Tile* pTile = m_pGrid->GetTile(m_Row, m_Col);
		pTile->SetHasBeenWalkedOn(true);
		glm::vec3 pos = pTile->GetPosition();
		m_pGameObject->GetComponent<dae::Transform>()->SetPosition(pos.x, pos.y, pos.z);
	}
	m_pSpriteSheet->SetIndex(int(m_FacingDirection) + m_SpriteCounter);
}

void PlayerComponent::MoveDownLeft()
{
	if (m_pGrid->MoveDownLeft(m_Row, m_Col))
	{
		Tile* pTile = m_pGrid->GetTile(m_Row, m_Col);
		pTile->SetHasBeenWalkedOn(true);
		glm::vec3 pos = pTile->GetPosition();
		m_pGameObject->GetComponent<dae::Transform>()->SetPosition(pos.x,pos.y,pos.z);
	}
	m_pSpriteSheet->SetIndex(int(m_FacingDirection) + m_SpriteCounter);
}

void PlayerComponent::SetGrid(Grid* pGrid)
{
	m_pGrid = pGrid;
}
