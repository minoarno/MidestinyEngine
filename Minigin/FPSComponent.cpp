#include "MiniginPCH.h"
#include "FPSComponent.h"
#include "MeTime.h"

FPSComponent::FPSComponent(dae::Font* font, float refreshRate)
	: TextComponent{ font," " }
	, m_RefreshRate{ refreshRate }
	, m_TotalTime{ 0.f }
{
	SetText("FPS: ");
}

void FPSComponent::Update()
{
	const double elapsedSec = Time::GetInstance().GetElapsedSeconds();
	m_TotalTime += elapsedSec;
	if (m_TotalTime >= m_RefreshRate)
	{
		const int fpsValue = static_cast<int>(1.0 / elapsedSec);
		SetText("FPS: " + std::to_string(fpsValue));
		m_TotalTime -= m_RefreshRate;
	}
}