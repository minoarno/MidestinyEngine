#pragma once
#include "Singleton.h"
class UIElement;
class UIManager final: public dae::Singleton<UIManager>
{
public:
	~UIManager();

	void Add(UIElement* newElement);

	void OnMouseDown(int mouseX, int mouseY);
private:
	friend class Singleton<UIManager>;
	UIManager() = default;
	std::vector<UIElement*> m_pElements;
};

