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

	float GetWidth() { return m_Width; };
	float GetHeight() { return m_Height; };

	bool IsColliding(const dae::Transform& transform, float width, float height);
	bool IsColliding(BoxCollider* other);
private:
	float m_Width;
	float m_Height;
};

