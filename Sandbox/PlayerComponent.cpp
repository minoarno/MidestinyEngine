#include "PlayerComponent.h"
#include "Input.h"
#include <functional>
#include "ServiceLocator.h"
#include "Audio.h"

#include "Lives.h"
#include "Score.h"

#include "GameObject.h"
#include "TextureSpriteSheet.h"
#include "MeTime.h"
#include "Scene.h"

using namespace dae;

<<<<<<< Updated upstream
PlayerComponent::PlayerComponent(Score* pScore, Lives* pLives, dae::ControllerButton upRight, dae::ControllerButton upLeft, dae::ControllerButton downRight, dae::ControllerButton downLeft, int startR, int startC, dae::Scene* pScene)
	: BaseComponent()
	, m_pScore{ pScore }
	, m_pLives{ pLives }
	, m_Col{ startC }
	, m_Row{ startR }
	, m_FacingDirection{ FacingDirection::downLeft }
{
	FunctionCommand* commandUpRight = new FunctionCommand();
	commandUpRight->SetFunctionOnRelease(std::bind(&PlayerComponent::MoveUpRight, this));
	dae::InputManager::GetInstance().AddInput(upRight, commandUpRight, pScene);

	FunctionCommand* commandUpLeft = new FunctionCommand();
	commandUpLeft->SetFunctionOnRelease(std::bind(&PlayerComponent::MoveUpLeft, this));
	dae::InputManager::GetInstance().AddInput(upLeft, commandUpLeft, pScene);

	FunctionCommand* commandDownRight = new FunctionCommand();
	commandDownRight->SetFunctionOnRelease(std::bind(&PlayerComponent::MoveDownRight, this));
	dae::InputManager::GetInstance().AddInput(downRight, commandDownRight, pScene);

	FunctionCommand* commandDownLeft = new FunctionCommand();
	commandDownLeft->SetFunctionOnRelease(std::bind(&PlayerComponent::MoveDownLeft, this));
	dae::InputManager::GetInstance().AddInput(downLeft, commandDownLeft, pScene);
}

PlayerComponent::PlayerComponent(Score* pScore, Lives* pLives, SDL_Scancode upRight, SDL_Scancode upLeft, SDL_Scancode downRight, SDL_Scancode downLeft, int startR, int startC, dae::Scene* pScene)
	: BaseComponent()
	, m_pScore{ pScore }
	, m_pLives{ pLives }
	, m_Col{ startC }
	, m_Row{ startR }
	, m_FacingDirection{ FacingDirection::downLeft }
{
	FunctionCommand* commandUpRight = new FunctionCommand();
	commandUpRight->SetFunctionOnRelease(std::bind(&PlayerComponent::MoveUpRight, this));
	InputManager::GetInstance().AddInput(upRight, commandUpRight, pScene);

	FunctionCommand* commandUpLeft = new FunctionCommand();
	commandUpLeft->SetFunctionOnRelease(std::bind(&PlayerComponent::MoveUpLeft, this));
	InputManager::GetInstance().AddInput(upLeft, commandUpLeft, pScene);

	FunctionCommand* commandDownRight = new FunctionCommand();
	commandDownRight->SetFunctionOnRelease(std::bind(&PlayerComponent::MoveDownRight, this));
	dae::InputManager::GetInstance().AddInput(downRight, commandDownRight, pScene);

	FunctionCommand* commandDownLeft = new FunctionCommand();
	commandDownLeft->SetFunctionOnRelease(std::bind(&PlayerComponent::MoveDownLeft, this));
	dae::InputManager::GetInstance().AddInput(downLeft, commandDownLeft, pScene);
=======
PlayerComponent::PlayerComponent(Score* pScore, Lives* pLives, dae::ControllerButton upRight, dae::ControllerButton upLeft, dae::ControllerButton downRight, dae::ControllerButton downLeft, dae::Scene* pScene)
	: BaseComponent()
	, m_pScore{ pScore }
	, m_pLives{ pLives }
	, m_FacingDirection{ FacingDirection::downLeft }
{
	FunctionCommand* commandUpRight = new FunctionCommand();
	commandUpRight->SetFunction(std::bind(&PlayerComponent::MoveUpRight, this));
	dae::InputManager::GetInstance().AddOnRelease(upRight, commandUpRight, pScene);

	FunctionCommand* commandUpLeft = new FunctionCommand();
	commandUpLeft->SetFunction(std::bind(&PlayerComponent::MoveUpLeft, this));
	dae::InputManager::GetInstance().AddOnRelease(upLeft, commandUpLeft, pScene);

	FunctionCommand* commandDownRight = new FunctionCommand();
	commandDownRight->SetFunction(std::bind(&PlayerComponent::MoveDownRight, this));
	dae::InputManager::GetInstance().AddOnRelease(downRight, commandDownRight, pScene);

	FunctionCommand* commandDownLeft = new FunctionCommand();
	commandDownLeft->SetFunction(std::bind(&PlayerComponent::MoveDownLeft, this));
	dae::InputManager::GetInstance().AddOnRelease(downLeft, commandDownLeft, pScene);
}

PlayerComponent::PlayerComponent(Score* pScore, Lives* pLives, SDL_Scancode upRight, SDL_Scancode upLeft, SDL_Scancode downRight, SDL_Scancode downLeft, dae::Scene* pScene)
	: BaseComponent()
	, m_pScore{ pScore }
	, m_pLives{ pLives }
	, m_FacingDirection{ FacingDirection::downLeft }
{
	FunctionCommand* commandUpRight = new FunctionCommand();
	commandUpRight->SetFunction(std::bind(&PlayerComponent::MoveUpRight, this));
	InputManager::GetInstance().AddOnRelease(upRight, commandUpRight, pScene);

	FunctionCommand* commandUpLeft = new FunctionCommand();
	commandUpLeft->SetFunction(std::bind(&PlayerComponent::MoveUpLeft, this));
	InputManager::GetInstance().AddOnRelease(upLeft, commandUpLeft, pScene);

	FunctionCommand* commandDownRight = new FunctionCommand();
	commandDownRight->SetFunction(std::bind(&PlayerComponent::MoveDownRight, this));
	dae::InputManager::GetInstance().AddOnRelease(downRight, commandDownRight, pScene);

	FunctionCommand* commandDownLeft = new FunctionCommand();
	commandDownLeft->SetFunction(std::bind(&PlayerComponent::MoveDownLeft, this));
	dae::InputManager::GetInstance().AddOnRelease(downLeft, commandDownLeft, pScene);
>>>>>>> Stashed changes
}

void PlayerComponent::Initialize()
{
	m_pSpriteSheet = m_pGameObject->GetComponent<dae::TextureSpriteSheet>();
	glm::vec3 pos = {};
	m_pGameObject->GetComponent<dae::Transform>()->SetPosition(pos.x, pos.y, pos.z);
}

void PlayerComponent::IncrementScore()
{
	m_pScore->IncreaseScore(50);
	ServiceLocator::GetAudio().Play(0,1);
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
	glm::vec3 pos = {};
	m_pGameObject->GetComponent<dae::Transform>()->SetPosition(pos.x, pos.y, pos.z);
	
	if (m_pSpriteSheet)
	{
		m_pSpriteSheet->SetIndex(int(m_FacingDirection) + m_SpriteCounter);
	}
}

void PlayerComponent::MoveUpLeft()
{
	glm::vec3 pos = {};
	m_pGameObject->GetComponent<dae::Transform>()->SetPosition(pos.x, pos.y, pos.z);
}

void PlayerComponent::MoveDownRight()
{
	glm::vec3 pos = {};
	m_pGameObject->GetComponent<dae::Transform>()->SetPosition(pos.x, pos.y, pos.z);
}

void PlayerComponent::MoveDownLeft()
{
<<<<<<< Updated upstream
	if (m_pGrid->MoveDownLeft(m_Row, m_Col))
	{
		Tile* pTile = m_pGrid->GetTile(m_Row, m_Col);
		pTile->SetHasBeenWalkedOn(true);
		glm::vec3 pos = pTile->GetPosition();
		m_pGameObject->GetComponent<dae::Transform>()->SetPosition(pos.x,pos.y,pos.z);
	}
	if (m_pSpriteSheet)
	{
		m_pSpriteSheet->SetIndex(int(m_FacingDirection) + m_SpriteCounter);
	}
}

void PlayerComponent::SetGrid(Grid* pGrid)
{
	m_pGrid = pGrid;
}

void PlayerComponent::SetRowAndCol(int row, int col)
{
	m_Row = row;
	m_Col = col;
}
=======
	glm::vec3 pos = {};
	m_pGameObject->GetComponent<dae::Transform>()->SetPosition(pos.x,pos.y,pos.z);
}
>>>>>>> Stashed changes
