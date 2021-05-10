#include "MiniginPCH.h"
#include "EventSubject.h"
#include "EventObserver.h"

void EventSubject::AddObserver(EventObserver* observer)
{
	m_pObservers.push_back(observer);
	m_AmountObservers++;
}

void EventSubject::RemoveObserver(EventObserver* observer)
{
	auto it = m_pObservers.begin();
	while (it != m_pObservers.end())
	{
		if (*it == observer)
		{
			it = m_pObservers.erase(it);
		}
		else
		{
			++it;
		}
	}
}

void EventSubject::Notify(BaseComponent* pBaseComponent)
{
	for (int i = 0; i < m_AmountObservers; i++)
	{
		m_pObservers[i]->OnNotify(pBaseComponent);
	}
}