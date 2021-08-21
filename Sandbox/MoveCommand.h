#pragma once
#include <Commands.h>

#include "Transform.h"

namespace dae
{
	class GameObject;
}

class MoveCommand : public Command
{
public:
	MoveCommand(dae::GameObject* pAffectedGameObject, const glm::vec3& direction, float speed = 1.f);
	MoveCommand(const MoveCommand& other) = delete;
	MoveCommand& operator=(const MoveCommand& other) = delete;
	MoveCommand(MoveCommand&& other) = delete;
	MoveCommand& operator=(MoveCommand&& other) = delete;

	virtual ~MoveCommand() = default;
	virtual void Execute() const;

	void SetDirection(const glm::vec3& direction);
	void SetSpeed(float speed);
	void SetGameObject(dae::GameObject* pAffectedGameObject);
private:
	glm::vec3 m_Direction;
	float m_Speed = 1.f;
	dae::GameObject* m_pAffectedGameObject;
};

