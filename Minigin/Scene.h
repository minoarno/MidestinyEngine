#pragma once
#include <string>
#include <vector>
namespace dae
{
	class GameObject;
	class Scene
	{
	public:
		explicit Scene(const std::string& name);
		Scene(const Scene& other) = delete;
		Scene(Scene&& other) = delete;
		Scene& operator=(const Scene& other) = delete;
		Scene& operator=(Scene&& other) = delete;
		virtual ~Scene();

		void Add(GameObject* object);

		virtual void Initialize();
		
		virtual void FixedUpdate();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render() const;

		virtual void Unload();
	private: 
		std::string m_Name;
		std::vector <GameObject*> m_Objects{};

		static unsigned int m_IdCounter; 
	};
}
