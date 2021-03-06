#include "Lives.h"

Lives::Lives(const int amount)
	: EventSubject()
	, m_AmountOfLives(amount)
{
}

void Lives::LoseLife()
{
	m_AmountOfLives--;
	Notify(this);
}
void Lives::GainLife()
{
	m_AmountOfLives++;
	Notify(this);
}