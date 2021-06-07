#pragma once
#include "Scene.h"

class Grid;
class Multiplayer final : public dae::Scene
{
public:
	Multiplayer();
	~Multiplayer();
	Multiplayer(const Multiplayer& other) = delete;
	Multiplayer& operator=(const Multiplayer& other) = delete;
	Multiplayer(Multiplayer&& other) = delete;
	Multiplayer& operator=(Multiplayer&& other) = delete;

private:
	Grid* m_pGrid = nullptr;
};

