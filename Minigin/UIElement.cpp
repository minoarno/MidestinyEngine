#include "MiniginPCH.h"
#include "UIElement.h"
#include "UIManager.h"

UIElement::UIElement()
	: BaseComponent{}
{
	UIManager::GetInstance().Add(this);
}

UIElement::~UIElement()
{
}