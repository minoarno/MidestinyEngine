#pragma once
#include "TextComponent.h"
class FPSComponent final : public TextComponent
{
public:
	FPSComponent(dae::Font* font, float refreshRate = 1.f);
	FPSComponent(const FPSComponent& other) = default;
	FPSComponent& operator=(const FPSComponent& other) = default;
	FPSComponent(FPSComponent&& other) = default;
	FPSComponent& operator=(FPSComponent&& other) = default;
	~FPSComponent() = default;

	void Update() override;
private:
	double m_RefreshRate;
	double m_TotalTime;
};

