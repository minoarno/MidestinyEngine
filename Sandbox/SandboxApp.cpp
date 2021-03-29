#include <Midestiny.h>
//#include <SceneManager.h>
#include <iostream>
class Sandbox final : public midestiny::Application
{
public:
	Sandbox()
		:Application()
	{
		std::cout << "Meep\n";
		glm::vec3 pos = { 0,1,2 };
		std::cout << pos.length() << '\n';

		//dae::Scene& scene = dae::SceneManager::GetInstance().CreateScene("StartScene");
		
		//dae::Scene& scene = dae::SceneManager::GetInstance().CreateScene("StartScene");
		//
		//dae::GameObject* to3 = new dae::GameObject();
		////to3->AddComponent(new TextComponent{ font,"Player 1 - Button B : increase score - Button A : lose live" });
		//to3->SetPosition(80, 300);
		//scene.Add(to3);
		//
		//dae::GameObject* to4 = new dae::GameObject();
		////to4->AddComponent(new TextComponent{ font,"Player 2 - DPAD DOWN : increase score - DPAD UP : lose live" });
		//to4->SetPosition(80, 360);
		//scene.Add(to4);
	}
	~Sandbox() = default;

	Sandbox(const Sandbox& other) = delete;
	Sandbox& operator=(const Sandbox& other) = delete;
	Sandbox(Sandbox&& other) = delete;
	Sandbox& operator=(Sandbox&& other) = delete;
};

midestiny::Application* midestiny::CreateApplication()
{
	return new Sandbox();
}