#pragma once
#include "Transform.h"
#include "SceneObject.h"

class BaseComponent;
namespace dae
{
	class Texture2D;
	class GameObject final : public SceneObject
	{
	public:
		void Initialize() override;
		void FixedUpdate() override;
		void Update() override;
		void LateUpdate() override;

		void Render() const override;

		void SetTexture(const std::string& filename);
		void SetPosition(float x, float y);

		GameObject() = default;
		virtual ~GameObject();
		GameObject(const GameObject& other) = delete;
		GameObject(GameObject&& other) = delete;
		GameObject& operator=(const GameObject& other) = delete;
		GameObject& operator=(GameObject&& other) = delete;

		void AddComponent(BaseComponent* newComponent);
		template<class T>
		T* GetComponent()const;
	private:
		Transform m_Transform;
		std::shared_ptr<Texture2D> m_Texture{};
		std::vector<BaseComponent*> m_pBaseComponents;
	};

	template<class T>
	inline T* GameObject::GetComponent() const
	{
		for (BaseComponent* c : m_pBaseComponents)
		{
			if (typeid(T) == typeid(*c))
			{
				return static_cast<T*>(c);
			}
		}
		return nullptr;
	}
}
