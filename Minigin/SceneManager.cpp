#include "MiniginPCH.h"
#include "SceneManager.h"
#include "Scene.h"

void dae::SceneManager::FixedUpdate()
{
	for (std::shared_ptr<Scene>& scene : m_Scenes)
	{
		scene->FixedUpdate();
	}
}

void dae::SceneManager::Update()
{
	for(std::shared_ptr<Scene>& scene : m_Scenes)
	{
		scene->Update();
	}
}

void dae::SceneManager::LateUpdate()
{
	for (std::shared_ptr<Scene>& scene : m_Scenes)
	{
		scene->LateUpdate();
	}
}

void dae::SceneManager::Render()
{
	for (const std::shared_ptr<Scene>& scene : m_Scenes)
	{
		scene->Render();
	}
}

void dae::SceneManager::NextScene()
{
	if (m_Scenes.size() > 1)
	{
		m_Scenes[m_CurrentIndex]->Unload();
		m_CurrentIndex = ++m_CurrentIndex % m_Scenes.size();
		m_Scenes[m_CurrentIndex]->Initialize();
	}
}


void dae::SceneManager::LoadScene(int index)
{
	if (index != m_CurrentIndex)
	{
		if (index >= 0 && index < int(m_Scenes.size()))
		{
			m_Scenes[m_CurrentIndex]->Unload();
			m_CurrentIndex = index;
			m_Scenes[m_CurrentIndex]->Initialize();
		}
		else
		{
			// out of range
		}
	}
	else
	{
		// Same scene	
	}
}

void dae::SceneManager::AddGameObject(int index, dae::GameObject* go)
{
	m_Scenes[index]->Add(go);
}

dae::Scene& dae::SceneManager::CreateScene(const std::string& name)
{
	const std::shared_ptr<Scene>& scene = std::shared_ptr<Scene>(new Scene(name));
	m_Scenes.push_back(scene);
	return *(scene);
}

std::shared_ptr<dae::Scene> dae::SceneManager::GetActiveScene() const
{
	return m_Scenes[m_CurrentIndex];
}

void dae::SceneManager::InitializeActiveScene()
{
	m_Scenes[m_CurrentIndex]->Initialize();
}
