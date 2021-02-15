#pragma once
#include "Singleton.h"

namespace dae
{
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
		
		void Render();
	private:
		friend class Singleton<SceneManager>;
		SceneManager() = default;
		std::vector<std::shared_ptr<Scene>> m_Scenes;
		int m_CurrentIndex = 0;
	};
}
