#include "MiniginPCH.h"
#include "BoxCollider.h"
#include "GameObject.h"


BoxCollider::BoxCollider(float width, float height)
	: BaseComponent()
	, m_Width{ width }
	, m_Height{ height }
{
}

BoxCollider::~BoxCollider()
{
}

bool BoxCollider::IsColliding(const dae::Transform& transform, float width2, float height2)
{
	glm::vec3 pos1 = m_pGameObject->GetComponent<dae::Transform>()->GetPosition();
	glm::vec3 pos2 = transform.GetPosition();

	//One is on the left of the other
	if (pos1.x + m_Width < pos2.x || pos2.x + width2 < pos1.x) return false;

	//One is above the other
	if (pos1.y + m_Height < pos2.y || pos2.y + height2 < pos1.y) return false;
	
	return true;
}

bool BoxCollider::IsColliding(BoxCollider* other)
{
	glm::vec3 pos1 = m_pGameObject->GetComponent<dae::Transform>()->GetPosition();
	glm::vec3 pos2 = other->GetGameObject()->GetComponent<dae::Transform>()->GetPosition();;

	//One is on the left of the other
	if (pos1.x + m_Width < pos2.x || pos2.x + other->GetWidth() < pos1.x) return false;

	//One is above the other
	if (pos1.y + m_Height < pos2.y || pos2.y + other->GetHeight() < pos1.y) return false;

	return true;
}
