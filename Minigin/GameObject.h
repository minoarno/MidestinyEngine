#pragma once
#include "Transform.h"
#include "Texture2D.h"
#include <vector>

class BaseComponent;
namespace dae
{
	class Texture2D;
	class GameObject final
	{
	public:
		void Initialize();
		void FixedUpdate();
		void Update();
		void LateUpdate();

		void Render() const;

		void SetTexture(const std::string& filename);
		void SetPosition(float x, float y);

		GameObject();
		virtual ~GameObject();
		GameObject(const GameObject& other) = delete;
		GameObject(GameObject&& other) = delete;
		GameObject& operator=(const GameObject& other) = delete;
		GameObject& operator=(GameObject&& other) = delete;

		void AddComponent(BaseComponent* newComponent);
		void AddChild(GameObject* newChildObject);
		void SetParent(GameObject* newParentObject);
		void RemoveChild(GameObject* childObject);

		
		GameObject* GetParent()const { return m_pParent; };
		GameObject* GetChild(int index);
		const std::vector<GameObject*>& GetChildren()const { return m_pChildren; };
		
		template<class T>
		T* GetComponent();
		template<class T>
		void SetComponent(T* value);
	private:
		Transform* m_pTransform;
		Texture2D* m_pTexture;
		std::vector<BaseComponent*> m_pBaseComponents;
		std::vector<GameObject*> m_pChildren;
		GameObject* m_pParent = nullptr;
	};

	template<class T>
	inline T* GameObject::GetComponent()
	{
		if (typeid(T) == typeid(dae::Transform))
		{
			return reinterpret_cast<T*>(m_pTransform);
		}

		if (typeid(T) == typeid(dae::Texture2D))
		{
			return reinterpret_cast<T*>(m_pTexture);
		}
		
		for (BaseComponent* c : m_pBaseComponents)
		{
			if (typeid(T) == typeid(*c))
			{
				return reinterpret_cast<T*>(c);
			}
		}
		return nullptr;
	}

	template<class T>
	inline void GameObject::SetComponent(T* value)
	{
		if (typeid(T) == typeid(dae::Transform))
		{
			//delete m_pTransform;
			delete m_pTransform;
			m_pTransform = reinterpret_cast<dae::Transform*>(value);
			return;
		}

		if (typeid(T) == typeid(dae::Texture2D))
		{
			delete m_pTexture;
			m_pTexture = reinterpret_cast<dae::Texture2D*>(value);
			return;
		}

		for (BaseComponent*& c : m_pBaseComponents)
		{
			if (typeid(T) == typeid(*c))
			{
				delete c;
				c = reinterpret_cast<BaseComponent*>(value);
				return;
			}
		}
	}
}
