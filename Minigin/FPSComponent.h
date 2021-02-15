#pragma once
#include "TextComponent.h"
class FPSComponent final : public TextComponent
{
public:
	FPSComponent(dae::Font* font, float refreshRate = 1.f);
	~FPSComponent() = default;

	void Update() override;
private:
	double m_RefreshRate;
	double m_TotalTime;
};

