#include <Midestiny.h>

class Sandbox : public Midestiny::Application
{
public:
	Sandbox()
	{
		
	}
	~Sandbox()
	{
		
	}
};

Midestiny::Application* Midestiny::CreateApplication()
{
	return new Sandbox();
}