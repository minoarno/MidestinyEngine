#pragma once
#include <Commands.h>
#include <string>
#include "Transform.h"

namespace dae
{
	class GameObject;
	class Scene;
}

class Score;
class FireCommand : public Command
{
public:
	FireCommand(dae::GameObject* pOwnerGameObject, dae::Scene* pScene, const glm::vec3& direction, const std::string& bulletTextureFilepath, Score* pScore = nullptr);
	FireCommand(const FireCommand& other) = delete;
	FireCommand& operator=(const FireCommand& other) = delete;
	FireCommand(FireCommand&& other) = delete;
	FireCommand& operator=(FireCommand&& other) = delete;
	~FireCommand();

	virtual void Execute() const override;
private:
	dae::GameObject* m_pOwnerObject = nullptr;
	dae::Scene* m_pScene = nullptr;
	std::string m_FilepathTexture = "";
	glm::vec3 m_Direction;
	Score* m_pScore = nullptr;
};

