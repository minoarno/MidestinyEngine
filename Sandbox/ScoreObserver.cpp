#include "ScoreObserver.h"
#include "TextComponent.h"
#include "Score.h"
#include <string>

ScoreObserver::ScoreObserver(TextComponent* pTextComponent)
	: EventObserver()
	, m_pTextComponent(pTextComponent)
{
}

void ScoreObserver::OnNotify(BaseComponent* pBaseComponent)
{
	Score* score = dynamic_cast<Score*>(pBaseComponent);
	std::string temp = "Score: " + std::to_string(score->GetScore());
	m_pTextComponent->SetText(temp);
}