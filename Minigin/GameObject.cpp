#include "MiniginPCH.h"
#include "GameObject.h"
#include "ResourceManager.h"
#include "Renderer.h"
#include "BaseComponent.h"

dae::GameObject::~GameObject()
{
	for (BaseComponent* baseComponent : m_pBaseComponents)
	{
		delete baseComponent;
		baseComponent = nullptr;
	}
	m_pBaseComponents.clear();
}

void dae::GameObject::AddComponent(BaseComponent* newComponent)
{
	m_pBaseComponents.push_back(newComponent);
}

void dae::GameObject::Initialize()
{
}

void dae::GameObject::FixedUpdate()
{
}

void dae::GameObject::Update()
{
}

void dae::GameObject::LateUpdate()
{
}

void dae::GameObject::Render() const
{
	const glm::vec3 pos = m_Transform.GetPosition();
	Renderer::GetInstance().RenderTexture(*m_Texture, pos.x, pos.y);
}

void dae::GameObject::SetTexture(const std::string& filename)
{
	m_Texture = ResourceManager::GetInstance().LoadTexture(filename);
}

void dae::GameObject::SetPosition(float x, float y)
{
	m_Transform.SetPosition(x, y, 0.0f);
}
