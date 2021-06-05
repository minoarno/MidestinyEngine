#pragma once
#include "BaseComponent.h"

#pragma warning(push)
#pragma warning (disable:4201)
#include <glm/glm.hpp>
#pragma warning(pop)

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
	glm::vec3 GetPosition()const;
private:
	bool m_HasBeenWalkedOn = false;
	float m_TileSize = 20.f;
};

