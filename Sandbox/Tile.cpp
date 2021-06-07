#include "Tile.h"
#include "GameObject.h"
#include <SDL_opengl.h>

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
	dae::TextureSpriteSheet* m_pSpriteSheet = m_pGameObject->GetComponent<dae::TextureSpriteSheet>();
	m_pSpriteSheet->SetIndex(int(value));
}

glm::vec3 Tile::GetPosition() const
{
	return m_pGameObject->GetComponent<dae::Transform>()->GetPosition();
}
