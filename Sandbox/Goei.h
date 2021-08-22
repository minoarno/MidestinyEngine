#pragma once
#include "Enemy.h"
class Goei final : public Enemy
{
public:
	Goei();
	Goei(const Goei& other) = delete;
	Goei& operator=(const Goei& other) = delete;
	Goei(Goei&& other) = delete;
	Goei& operator=(Goei&& other) = delete;
	~Goei();

	void Dive()override;
private:

};

