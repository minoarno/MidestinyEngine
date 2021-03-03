#include "MiniginPCH.h"
#include "LiveObserver.h"

#include "Lives.h"
#include "TextComponent.h"
LiveObserver::LiveObserver(TextComponent* pTextComponent)
	:m_pTextComponent(pTextComponent)
{	
}
void LiveObserver::SetTextComponent(TextComponent* pTextComponent)
{
	m_pTextComponent = pTextComponent;
}

void LiveObserver::OnNotify(BaseComponent* pBaseComponent)
{
	Lives* lives = dynamic_cast<Lives*>(pBaseComponent);
	std::string temp = "Lives: " + std::to_string(lives->GetLives());
	m_pTextComponent->SetText(temp);
}