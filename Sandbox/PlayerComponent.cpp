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
#include "MoveCommand.h"
using namespace dae;

PlayerComponent::PlayerComponent(Score* pScore, Lives* pLives, dae::ControllerButton up, dae::ControllerButton left, dae::ControllerButton down, dae::ControllerButton right, dae::Scene* pScene)
	: BaseComponent()
	, m_pScore{ pScore }
	, m_pLives{ pLives }
	, m_FacingDirection{ FacingDirection::downLeft }
{
	dae::InputManager::GetInstance().AddOnRelease(up, new MoveCommand(m_pGameObject, {0,1,0}), pScene);
	dae::InputManager::GetInstance().AddOnRelease(left, new MoveCommand(m_pGameObject, { -1,0,0 }), pScene);
	dae::InputManager::GetInstance().AddOnRelease(down, new MoveCommand(m_pGameObject, { 0,-1,0 }), pScene);
	dae::InputManager::GetInstance().AddOnRelease(right, new MoveCommand(m_pGameObject, { 1,0,0 }), pScene);
}

PlayerComponent::PlayerComponent(Score* pScore, Lives* pLives, SDL_Scancode up, SDL_Scancode left, SDL_Scancode down, SDL_Scancode right, dae::Scene* pScene)
	: BaseComponent()
	, m_pScore{ pScore }
	, m_pLives{ pLives }
	, m_FacingDirection{ FacingDirection::downLeft }
{
	dae::InputManager::GetInstance().AddOnRelease(up, new MoveCommand(m_pGameObject, { 0,1,0 }), pScene);
	dae::InputManager::GetInstance().AddOnRelease(left, new MoveCommand(m_pGameObject, { -1,0,0 }), pScene);
	dae::InputManager::GetInstance().AddOnRelease(down, new MoveCommand(m_pGameObject, { 0,-1,0 }), pScene);
	dae::InputManager::GetInstance().AddOnRelease(right, new MoveCommand(m_pGameObject, { 1,0,0 }), pScene);
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
