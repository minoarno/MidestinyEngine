#include "FireCommand.h"
#include "GameObject.h"
#include "Scene.h"
#include "BoxCollider.h"
#include "Score.h"
#include "BulletComponent.h"

FireCommand::FireCommand(dae::GameObject* pOwnerGameObject, dae::Scene* pScene, const glm::vec3& direction, const std::string& bulletTextureFilepath, Score* pScore)
	: m_pOwnerObject{ pOwnerGameObject }
	, m_pScene{ pScene }
	, m_Direction{ direction }
	, m_FilepathTexture{ bulletTextureFilepath }
	, m_pScore{ pScore }
{
}

FireCommand::~FireCommand()
{
}

void FireCommand::Execute() const
{
	glm::vec3 pos = m_pOwnerObject->GetComponent<dae::Transform>()->GetPosition();

	dae::GameObject* pBullet = new dae::GameObject();
	pBullet->SetTag(m_pOwnerObject->GetTag());
	pBullet->SetTexture(m_FilepathTexture);
	pBullet->GetComponent<dae::Texture2D>()->SetSize(8, 16);
	pBullet->AddComponent(new BoxCollider(8, 16));
	pBullet->SetPosition(pos.x, pos.y);
	pBullet->AddComponent(new BulletComponent(m_pOwnerObject,pBullet, m_pScene, m_Direction, m_pScore));
	m_pScene->Add(pBullet);
}
