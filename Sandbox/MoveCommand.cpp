#include "MoveCommand.h"
#include "GameObject.h"
#include "MeTime.h"

MoveCommand::MoveCommand(dae::GameObject* pAffectedGameObject, const glm::vec3& direction, float speed)
	: m_pAffectedGameObject{ pAffectedGameObject }
	, m_Direction{ direction }
	, m_Speed{ speed }
{
}

void MoveCommand::Execute() const
{
	m_pAffectedGameObject->GetComponent<dae::Transform>()->Translate(m_Direction * (m_Speed * float(Time::GetInstance().GetFixedElapsedSeconds())));
}

void MoveCommand::SetDirection(const glm::vec3& direction)
{
	m_Direction = direction;
}

void MoveCommand::SetSpeed(float speed)
{
	m_Speed = speed;
}

void MoveCommand::SetGameObject(dae::GameObject* pAffectedGameObject)
{
	m_pAffectedGameObject = pAffectedGameObject;
}
