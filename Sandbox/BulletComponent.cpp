#include "BulletComponent.h"
#include "MoveCommand.h"

BulletComponent::BulletComponent(dae::GameObject* pOwner, dae::GameObject* pBullet, dae::Scene* pScene, const glm::vec3& direction, Score* pScore)
	: m_pOwnerGameObject{pOwner}
	, m_pScene{ pScene}
	, m_pScore{ pScore }
	, m_pMove{ new MoveCommand(pBullet,direction,1200)}
{
}

BulletComponent::~BulletComponent()
{
	delete m_pMove;
	m_pMove = nullptr;
}

void BulletComponent::FixedUpdate()
{

}

void BulletComponent::Update()
{
	m_pMove->Execute();
}
