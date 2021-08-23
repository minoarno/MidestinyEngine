#include "BulletComponent.h"
#include "MoveCommand.h"
#include "Scene.h"
#include "GameObject.h"
#include "Score.h"
#include "Enemy.h"

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

void BulletComponent::Update()
{
	m_pMove->Execute();

	std::vector<dae::GameObject*> temp = m_pScene->Collision(m_pGameObject);
	for (dae::GameObject* go : temp)
	{
		if (go->GetTag() != m_pGameObject->GetTag())
		{
			if (m_pScore != nullptr)
			{
				Enemy* pEnemy = go->GetComponent<Enemy>();
				if (pEnemy != nullptr)
				{
					m_pScore->IncreaseScore(pEnemy->GetHit());
				}
			}
		}
	}
}
