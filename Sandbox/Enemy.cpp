#include "Enemy.h"

Enemy::Enemy(int scoreInformation, int scoreDiving)
	: m_ScoreInformation{ scoreInformation }
	, m_ScoreDiving{ scoreDiving }
{
}

Enemy::~Enemy()
{
}

Enemy::EnemyState Enemy::GetEnemyState() const
{
	return m_EnemyState;
}

int Enemy::GetScoreFromKilling() const
{
	return (m_EnemyState == EnemyState::InFormation)? m_ScoreInformation : m_ScoreDiving;
}

int Enemy::GetHit()
{
	return GetScoreFromKilling();
}
