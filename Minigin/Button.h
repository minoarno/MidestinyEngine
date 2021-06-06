#pragma once
#include "UIElement.h"
#include <functional>

class Command;
class Button : public UIElement
{
public:
	Button(Command* pOnPressDownCommand);
	Button(std::function<void()>& onPressDownFunction);
	Button(const Button& other) = delete;
	Button& operator=(const Button& other) = delete;
	Button(Button&& other) = delete;
	Button& operator=(Button&& other) = delete;
	~Button();

	void Initialize() override;
	void FixedUpdate() override;
	void Update() override;
	void LateUpdate() override;
	void Render() const override;

	void SetSize(float width, float height);

	virtual void OnMouseDown(int mouseX, int mouseY) const override;
private:
	Command* m_pOnClickCommand;
	float m_Width;
	float m_Height;
};

