#include "MiniginPCH.h"
#include "PlayerComponent.h"
#include "Input.h"
#include <functional>
#include "ServiceLocator.h"
#include "Audio.h"
PlayerComponent::PlayerComponent(Score* pScore, Lives* pLives, dae::ControllerButton incrementScore, dae::ControllerButton die)
	: BaseComponent()
	, m_pScore(pScore)
	, m_pLives(pLives)
{
	FunctionCommand* commandIncreaseScore = new FunctionCommand();
	commandIncreaseScore->SetFunctionOnRelease(std::bind(&PlayerComponent::IncrementScore, this));
	dae::InputManager::GetInstance().AddInput(incrementScore, commandIncreaseScore);
	
	FunctionCommand* commandDie = new FunctionCommand();
	commandDie->SetFunctionOnRelease(std::bind(&PlayerComponent::LoseLife, this));
	dae::InputManager::GetInstance().AddInput(die, commandDie);
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