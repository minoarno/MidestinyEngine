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

	//void FixedUpdate() override;
	//void Update() override;
	//void LateUpdate() override;
	//void Render() const override;
private:
	EnemyManager* m_pEnemyManager = nullptr;
};

