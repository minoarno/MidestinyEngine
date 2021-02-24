#include "MiniginPCH.h"
#include "GameObject.h"
#include "ResourceManager.h"
#include "Renderer.h"
#include "BaseComponent.h"
#include "Transform.h"
#include "Texture2D.h"

dae::GameObject::GameObject()
	: m_pTransform{new Transform{}}
	, m_pTexture{ nullptr }
{
}

dae::GameObject::~GameObject()
{
	for (BaseComponent* baseComponent : m_pBaseComponents)
	{
		delete baseComponent;
		baseComponent = nullptr;
	}
	m_pBaseComponents.clear();

	for (GameObject* child : m_pChildren)
	{
		delete child;
		child = nullptr;
	}
	m_pChildren.clear();

	delete m_pTransform;
	m_pTransform = nullptr;

	if (m_pTexture == nullptr)
	{
		//delete m_pTexture;
		//m_pTexture = nullptr;
	}
}

void dae::GameObject::AddComponent(BaseComponent* newComponent)
{
	m_pBaseComponents.push_back(newComponent);
	newComponent->SetGameObject(this);
}

void dae::GameObject::AddChild(GameObject* newChildObject)
{
	//GameObject* oldParent = newChildObject->GetParent();

	//Checking if the the newChildObject isn't one of this object's parents
	GameObject* pObject = this;
	while (pObject != nullptr && pObject != newChildObject)
	{
		pObject = this->GetParent();
	}
}

void dae::GameObject::SetParent(GameObject* newParentObject)
{
	//GameObject* oldParent = this->GetParent();

	//Checking if the the newParentObject isn't one of this object's children
	GameObject* pObject = newParentObject;
	while (pObject != nullptr && pObject != this)
	{
		pObject = newParentObject->GetParent();
	}

	
}

void dae::GameObject::RemoveChild(GameObject* childObject)
{
	for (int i = int(m_pChildren.size()) - 1; i >= 0; i--)
	{
		if (m_pChildren[i] == childObject)
		{
			delete m_pChildren[i];
			m_pChildren[i] = nullptr;
			m_pChildren.erase(m_pChildren.begin() + i);
		}
	}
}

dae::GameObject* dae::GameObject::GetChild(int index)
{
	if (index >= int(m_pChildren.size()))
	{
		return nullptr;
	}

	return m_pChildren[index];
}

void dae::GameObject::Initialize()
{
	for (size_t i = 0; i < m_pBaseComponents.size(); i++)
	{
		m_pBaseComponents[i]->Initialize();
	}

	for (size_t i = 0; i < m_pChildren.size(); i++)
	{
		m_pChildren[i]->Initialize();
	}
}

void dae::GameObject::FixedUpdate()
{
	for (size_t i = 0; i < m_pBaseComponents.size(); i++)
	{
		m_pBaseComponents[i]->FixedUpdate();
	}

	for (size_t i = 0; i < m_pChildren.size(); i++)
	{
		m_pChildren[i]->FixedUpdate();
	}
}

void dae::GameObject::Update()
{
	for (size_t i = 0; i < m_pBaseComponents.size(); i++)
	{
		m_pBaseComponents[i]->Update();
	}

	for (size_t i = 0; i < m_pChildren.size(); i++)
	{
		m_pChildren[i]->Update();
	}
}

void dae::GameObject::LateUpdate()
{
	for (size_t i = 0; i < m_pBaseComponents.size(); i++)
	{
		m_pBaseComponents[i]->LateUpdate();
	}

	for (size_t i = 0; i < m_pChildren.size(); i++)
	{
		m_pChildren[i]->LateUpdate();
	}
}

void dae::GameObject::Render() const
{
	const glm::vec3 pos = m_pTransform->GetPosition();
	Renderer::GetInstance().RenderTexture(*m_pTexture, pos.x, pos.y);

	for (size_t i = 0; i < m_pBaseComponents.size(); i++)
	{
		m_pBaseComponents[i]->Render();
	}

	for (size_t i = 0; i < m_pChildren.size(); i++)
	{
		m_pChildren[i]->Render();
	}
}

void dae::GameObject::SetTexture(const std::string& filename)
{
	m_pTexture = ResourceManager::GetInstance().LoadTexture(filename);
}

void dae::GameObject::SetPosition(float x, float y)
{
	m_pTransform->SetPosition(x, y, 0.0f);
}
