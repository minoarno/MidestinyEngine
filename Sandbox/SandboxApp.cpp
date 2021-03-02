#include <Midestiny.h>
//#include <SceneManager.h>
class Sandbox final : public midestiny::Application
{
public:
	Sandbox()
		:Application()
	{
		//dae::Scene& scene = dae::SceneManager::GetInstance().CreateScene("StartScene");

	}
	~Sandbox()
	{
		
	}

	Sandbox(const Sandbox& other) = delete;
	Sandbox& operator=(const Sandbox& other) = delete;
	Sandbox(Sandbox&& other) = delete;
	Sandbox& operator=(Sandbox&& other) = delete;
};

midestiny::Application* midestiny::CreateApplication()
{
	return new Sandbox();
}