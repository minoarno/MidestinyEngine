#pragma once
#include "Enemy.h"
class BossGalaga final : public Enemy
{
public:
	BossGalaga();
	BossGalaga(const BossGalaga& other) = delete;
	BossGalaga& operator=(const BossGalaga& other) = delete;
	BossGalaga(BossGalaga&& other) = delete;
	BossGalaga& operator=(BossGalaga&& other) = delete;
	~BossGalaga();

	void Dive() override;
private:

};

