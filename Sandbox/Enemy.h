#pragma once
#include "BaseComponent.h"
class Enemy : public BaseComponent
{
public:
	enum class EnemyState
	{
		InFormation = 0,
		Diving = 1
	};

	Enemy(int scoreInformation, int scoreDiving);
	Enemy(const Enemy& other) = delete;
	Enemy& operator=(const Enemy& other) = delete;
	Enemy(Enemy&& other) = delete;
	Enemy& operator=(Enemy&& other) = delete;
	~Enemy();

	int GetScoreFromKilling()const;
	virtual int GetHit();
	EnemyState GetEnemyState()const;

	virtual void Dive() = 0;
private:
	int m_ScoreInformation;
	int m_ScoreDiving;

	EnemyState m_EnemyState;
};

