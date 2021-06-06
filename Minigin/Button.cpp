#include "MiniginPCH.h"
#include "Button.h"
#include "Commands.h"
#include "GameObject.h"

Button::Button(Command* pOnPressDownCommand)
	: UIElement{}
	, m_pOnClickCommand{ pOnPressDownCommand }
{
}

Button::Button(std::function<void()>& onPressDownFunction)
{
	FunctionCommand* funcCommand = new FunctionCommand{};
	funcCommand->SetFunctionOnPressDown(onPressDownFunction);
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
		m_pOnClickCommand->OnPressDown();
	}
}
