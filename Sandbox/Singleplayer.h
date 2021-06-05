#pragma once
#include "Scene.h"

class Singleplayer final : public dae::Scene
{
public:
	Singleplayer();
	Singleplayer& operator=(const Singleplayer& other) = delete;
	Singleplayer(const Singleplayer& other) = delete;
	Singleplayer& operator=(Singleplayer&& other) = delete;
	Singleplayer(Singleplayer&& other) = delete;
	~Singleplayer();
private:

};

