#include "Grid.h"
#include "Tile.h"
#include "GameObject.h"

#include "Transform.h"
#include "Scene.h"
#include "TextureSpriteSheet.h"

Grid::Grid(unsigned int size, float tileSize)
	: BaseComponent{}
	, m_TileSize{tileSize}
	, m_Size{size}
{
}

Grid::~Grid()
{
	for (std::vector<Tile*>& vector : m_Grid)
	{
		for (Tile* tile : vector)
		{
			delete tile;
			tile = nullptr;
		}
		vector.clear();
	}
	m_Grid.clear();
}

void Grid::Initialize()
{
	dae::Transform* pTransform = m_pGameObject->GetComponent<dae::Transform>();
	glm::vec3 pos = pTransform->GetPosition();

	int tileWidth = int(float(sqrt(3)) * m_TileSize);
	int tileHeight = int(2 * m_TileSize);

	m_Grid.resize(m_Size);
	for (unsigned int r = 0; r < m_Size; r++)
	{
		std::vector<Tile*> vector;
		unsigned int sizeCols = r + 1;
		vector.resize(sizeCols);
		for (unsigned int c = 0; c < sizeCols; c++)
		{
			dae::GameObject* pObject = new dae::GameObject{};
			vector[c] = new Tile{ m_TileSize };
			pObject->AddComponent(vector[c]);
			dae::Transform* transform = pObject->GetComponent<dae::Transform>();
			transform->SetPosition(pos.x + tileWidth * (0.5f * ((m_Size - 1) - r) + c), pos.y + tileHeight * r, pos.z);
			pObject->SetTexture("Blocks.png", 1, 3);
			pObject->GetComponent<dae::TextureSpriteSheet>()->SetSize(tileWidth,tileHeight - 1);
			m_pGameObject->AddChild(pObject);
		}
		m_Grid[r] = vector;
	}
}

void Grid::MoveUpRight(int& r, int& w)
{
	r--;
}

void Grid::MoveUpLeft(int& r, int& w)
{
	r--;
	w--;
}

void Grid::MoveDownRight(int& r, int& w)
{
	r++;
	w++;
}

void Grid::MoveDownLeft(int& r, int& w)
{
	r++;
}

Tile* Grid::GetTile(int r, int w)
{
	return m_Grid[r][w];
}
