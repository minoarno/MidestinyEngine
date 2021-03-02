#pragma once
#include "Singleton.h"
#include <vector>

namespace dae
{
	class GameObject;
	class Scene;
	class SceneManager final : public Singleton<SceneManager>
	{
	public:
		Scene& CreateScene(const std::string& name);

		void FixedUpdate();
		void Update();
		void LateUpdate();

		void NextScene();
		void LoadScene(int index);

		void AddGameObject(int index, GameObject* go);
		
		void Render();
	private:
		friend class Singleton<SceneManager>;
		SceneManager() = default;
		std::vector<std::shared_ptr<Scene>> m_Scenes;
		int m_CurrentIndex = 0;
	};
}
