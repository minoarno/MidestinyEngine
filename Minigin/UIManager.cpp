#include "MiniginPCH.h"
#include "UIManager.h"
#include "UIElement.h"
#include "SceneManager.h"
#include "Scene.h"
#include "GameObject.h"

using namespace dae;

UIManager::~UIManager()
{
	for (size_t i = 0; i < m_pElements.size(); i++)
	{
		delete m_pElements[i];
		m_pElements[i] = nullptr;
	}
}

void UIManager::Add(UIElement* newElement)
{
	m_pElements.push_back(newElement);
}

void UIManager::OnMouseDown(int mouseX, int mouseY)
{
	std::shared_ptr<Scene> activeScene = SceneManager::GetInstance().GetActiveScene();
	for (size_t i = 0; i < m_pElements.size(); i++)
	{
		if (m_pElements[i]->GetGameObject()->GetScene() == activeScene.get())
		{
			m_pElements[i]->OnMouseDown(mouseX, mouseY);
		}
	}
}
