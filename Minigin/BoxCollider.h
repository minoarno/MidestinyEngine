#pragma once
#include "BaseComponent.h"
#include "Transform.h"

class BoxCollider final : public BaseComponent
{
public:
	BoxCollider(float width, float height);
	BoxCollider(const BoxCollider& other) = delete;
	BoxCollider& operator=(const BoxCollider& other) = delete;
	BoxCollider(BoxCollider&& other) = delete;
	BoxCollider& operator=(BoxCollider&& other) = delete;
	~BoxCollider();

	bool IsColliding(const dae::Transform& transform, float width, float height);
private:
	float m_Width;
	float m_Height;
};

