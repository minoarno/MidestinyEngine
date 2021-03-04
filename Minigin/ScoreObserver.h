#pragma once
#include "EventObserver.h"
#include "BaseComponent.h"

class TextComponent;
class ScoreObserver final: public BaseComponent, public EventObserver
{
public:
	ScoreObserver(TextComponent* pTextComponent);
	ScoreObserver(const ScoreObserver& other) = delete;
	ScoreObserver& operator=(const ScoreObserver& other) = delete;
	ScoreObserver(ScoreObserver&& other) = delete;
	ScoreObserver& operator=(ScoreObserver&& other) = delete;
	~ScoreObserver() = default;

	virtual void OnNotify(BaseComponent* pBaseComponent) override;
private:
	TextComponent* m_pTextComponent = nullptr;
};

