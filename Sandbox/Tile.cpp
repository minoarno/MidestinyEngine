#include "Tile.h"
#include "GameObject.h"
#include <SDL_opengl.h>
#define  _USE_MATH_DEFINES
#include <math.h>


Tile::Tile(float tileSize)
	: BaseComponent{}
	, m_TileSize{tileSize}
{
}

Tile::~Tile()
{
}

void Tile::SetHasBeenWalkedOn(bool value)
{
	m_HasBeenWalkedOn = value;
}