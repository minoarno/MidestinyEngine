#pragma once
#include "Scene.h"

class EnemyManager;
class Versus final : public dae::Scene
{
public:
	Versus();
	Versus& operator=(const Versus& other) = delete;
	Versus(const Versus& other) = delete;
	Versus& operator=(Versus&& other) = delete;
	Versus(Versus&& other) = delete;
	~Versus();

	virtual void Initialize();

	virtual void FixedUpdate();
	virtual void Update();
	virtual void LateUpdate();
	virtual void Render() const;

	virtual void Unload();
private:
	EnemyManager* m_pEnemyManager = nullptr;
};
