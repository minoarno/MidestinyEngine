#include "MiniginPCH.h"
#include "EventSubject.h"
#include "EventObserver.h"

void EventSubject::AddObserver(EventObserver* observer)
{
	if (m_AmountObservers < MAX_OBSERVERS)
	{
		for (int i = 0; i < m_AmountObservers; i++)
		{
			if (observer == m_pObservers[i])
			{
				std::cout << "This observer already is added to the subject\n";
				return;
			}
		}
		
		m_pObservers[m_AmountObservers] = observer;
		m_AmountObservers++;
	}
	else
	{
		std::cout << "You already have the max amount of observers you can have on a single subject.\n";
	}
}

void EventSubject::RemoveObserver(EventObserver* observer)
{
	for (int i = 0; i < m_AmountObservers; i++)
	{
		if (observer == m_pObservers[i])
		{
			m_pObservers[i] = m_pObservers[m_AmountObservers - 1];
			m_pObservers[m_AmountObservers - 1] = nullptr;
			m_AmountObservers--;
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