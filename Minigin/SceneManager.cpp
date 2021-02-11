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

dae::Scene& dae::SceneManager::CreateScene(const std::string& name)
{
	const std::shared_ptr<Scene>& scene = std::shared_ptr<Scene>(new Scene(name));
	m_Scenes.push_back(scene);
	return *(scene);
}