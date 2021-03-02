#pragma once
#include "Core.h"
#include "BaseComponent.h"

class EventObserver;

class EventSubject : public BaseComponent
{
public:
	EventSubject() = default;
	~EventSubject() = default;

	EventSubject(const EventSubject& other) = delete;
	EventSubject& operator=(const EventSubject& other) = delete;
	EventSubject(EventSubject&& other) = delete;
	EventSubject& operator=(EventSubject&& other) = delete;
	
	void AddObserver(EventObserver* observer);
	void RemoveObserver(EventObserver* observer);
protected:
	void Notify(BaseComponent* pBaseComponent);

private:
	EventObserver* m_pObservers[MAX_OBSERVERS]{};
	int m_AmountObservers = 0;
};

