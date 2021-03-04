#pragma once
#include "BaseComponent.h"

class EventObserver
{
public:
	~EventObserver() = default;

	virtual void OnNotify(BaseComponent* pBaseComponent) = 0;
};

