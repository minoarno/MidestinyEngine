#pragma once
#include "BaseComponent.h"

class EventObserver : public BaseComponent
{
public:
	EventObserver() = default;
	~EventObserver() = default;
	EventObserver(const EventObserver& other) = delete;
	EventObserver& operator=(const EventObserver& other) = delete;
	EventObserver(EventObserver&& other) = delete;
	EventObserver& operator=(EventObserver&& other) = delete;

	virtual void OnNotify(BaseComponent* pBaseComponent) = 0;
};

