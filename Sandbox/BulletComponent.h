#pragma once
#include "BaseComponent.h"
#include "Transform.h"


namespace dae
{
	class GameObject;
	class Scene;
}
class Score;
class MoveCommand;
class BulletComponent : public BaseComponent
{
public:
	BulletComponent(dae::GameObject* pOwner, dae::GameObject* pBullet, dae::Scene* pScene, const glm::vec3& direction , Score* pScore);
	BulletComponent(const BulletComponent& other) = delete;
	BulletComponent& operator=(const BulletComponent& other) = delete;
	BulletComponent(BulletComponent&& other) = delete;
	BulletComponent& operator=(BulletComponent&& other) = delete;
	~BulletComponent();

	virtual void FixedUpdate() override;
	virtual void Update() override;
private:
	dae::GameObject* m_pOwnerGameObject;
	dae::Scene* m_pScene;
	Score* m_pScore;

	MoveCommand* m_pMove;
};

