#include "Score.h"

void Score::IncreaseScore(int amount)
{
	m_Score += amount;
	Notify(this);
}