#pragma once
#include "EventObserver.h"
#include "BaseComponent.h"

class TextComponent;
class LiveObserver final : public BaseComponent, public EventObserver
{
public:
	LiveObserver(TextComponent* pTextComponent);
	LiveObserver(const LiveObserver& other) = delete;
	LiveObserver& operator=(const LiveObserver& other) = delete;
	LiveObserver(LiveObserver&& other) = delete;
	LiveObserver& operator=(LiveObserver&& other) = delete;
	~LiveObserver() = default;
	
	void SetTextComponent(TextComponent* pTextComponent);

	virtual void OnNotify(BaseComponent* pBaseComponent) override;
private:
	TextComponent* m_pTextComponent = nullptr;
};

