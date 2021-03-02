#pragma once
#include "SceneManager.h"

namespace dae
{
	class GameObject;
	class Scene
	{
		friend Scene& SceneManager::CreateScene(const std::string& name);
	public:
		void Add(GameObject* object);

		void Initialize();
		
		void FixedUpdate();
		void Update();
		void LateUpdate();
		void Render() const;

		void Unload();
		
		~Scene();
		Scene(const Scene& other) = delete;
		Scene(Scene&& other) = delete;
		Scene& operator=(const Scene& other) = delete;
		Scene& operator=(Scene&& other) = delete;
	private: 
		explicit Scene(const std::string& name);

		std::string m_Name;
		std::vector < GameObject*> m_Objects{};

		static unsigned int m_IdCounter; 
	};

}
