#pragma once
#include "EventSubject.h"
class Score final : public EventSubject
{
public:
	Score() = default;
	Score(const Score& other) = delete;
	Score& operator=(const Score& other) = delete;
	Score(Score&& other) = delete;
	Score& operator=(Score&& other) = delete;
	~Score() = default;

	void IncreaseScore(int amount);

	int GetScore()const { return m_Score; }
private:
	int m_Score = 0;
};

