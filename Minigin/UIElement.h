#pragma once
#include "BaseComponent.h"
class UIElement : public BaseComponent
{
public:
	UIElement();
	UIElement(const UIElement& other) = delete;
	UIElement& operator=(const UIElement& other) = delete;
	UIElement(UIElement&& other) = delete;
	UIElement& operator=(UIElement&& other) = delete;
	~UIElement();

	virtual void Initialize() override {};
	virtual void FixedUpdate() override {};
	virtual void Update() override {};
	virtual void LateUpdate() override {};
	virtual void Render() const override {};

	virtual void OnMouseDown(int mouseX, int mouseY) const = 0;
};

