#include "MiniginPCH.h"
#include "Button.h"
#include "FunctionCommand.h"
#include "GameObject.h"
#include <SDL.h>

Button::Button(Command* pOnPressDownCommand)
	: UIElement{}
	, m_pOnClickCommand{ pOnPressDownCommand }
	, m_Width{100}
	, m_Height{100}
{
}

Button::Button(std::function<void()>& onPressDownFunction)
	: UIElement{}
	, m_pOnClickCommand{nullptr}
	, m_Width{ 100 }
	, m_Height{ 100 }
{
	FunctionCommand* funcCommand = new FunctionCommand{};
	funcCommand->SetFunction(onPressDownFunction);
	m_pOnClickCommand = funcCommand;
}

Button::~Button()
{
	delete m_pOnClickCommand;
	m_pOnClickCommand = nullptr;
}

void Button::Initialize()
{
}

void Button::FixedUpdate()
{
}

void Button::Update()
{
}

void Button::LateUpdate()
{
}

void Button::Render() const
{
}

void Button::SetSize(float width, float height)
{
	m_Width = width;
	m_Height = height;
}

void Button::OnMouseDown(int mouseX, int mouseY) const
{
	const glm::vec3 pos = m_pGameObject->GetComponent<dae::Transform>()->GetPosition();
	if (pos.x < mouseX && pos.x + m_Width > mouseX && pos.y < mouseY && pos.y + m_Height > mouseY)
	{
		if (m_pOnClickCommand != nullptr)
		{
			m_pOnClickCommand->Execute();
		}
	}
}
