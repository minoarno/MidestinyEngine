#pragma once
#include "Scene.h"

class EnemyManager;
class Multiplayer final : public dae::Scene
{
public:
	Multiplayer();
	~Multiplayer();
	Multiplayer(const Multiplayer& other) = delete;
	Multiplayer& operator=(const Multiplayer& other) = delete;
	Multiplayer(Multiplayer&& other) = delete;
	Multiplayer& operator=(Multiplayer&& other) = delete;

	void Update() override;
private:
	EnemyManager* m_pEnemyManager = nullptr;
};

