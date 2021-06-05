#pragma once
#include "BaseComponent.h"

class Tile : public BaseComponent
{
public:
	Tile(float tileSize);
	Tile(const Tile& other) = delete;
	Tile& operator=(const Tile& other) = delete;
	Tile(Tile&& other) = delete;
	Tile& operator=(Tile&& other) = delete;
	~Tile();

	void SetHasBeenWalkedOn(bool value);
private:
	bool m_HasBeenWalkedOn = false;
	float m_TileSize = 20.f;
};

