#pragma once
#include "Scene.h"

class EnemyManager;
class Singleplayer final : public dae::Scene
{
public:
	Singleplayer();
	Singleplayer& operator=(const Singleplayer& other) = delete;
	Singleplayer(const Singleplayer& other) = delete;
	Singleplayer& operator=(Singleplayer&& other) = delete;
	Singleplayer(Singleplayer&& other) = delete;
	~Singleplayer();

	void Update() override;

private:
	EnemyManager* m_pEnemyManager = nullptr;
	std::vector<std::string> m_WaveNames;
	int m_CurrentWaveIndex = 0;
};

