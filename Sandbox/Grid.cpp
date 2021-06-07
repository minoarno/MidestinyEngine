#include "Grid.h"
#include "Tile.h"
#include "GameObject.h"

#include "Transform.h"
#include "Scene.h"
#include "TextureSpriteSheet.h"

#include "Log.h"

Grid::Grid(int size, float tileSize)
	: BaseComponent{}
	, m_TileSize{tileSize}
	, m_Size{size}
{
	if (size < 1)
	{
		size = 1;
		ME_WARN("GRID ONLY HAS 1 SIZE");
	}
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
	CreateGrid();
}

void Grid::CreateGrid()
{
	dae::Transform* pTransform = m_pGameObject->GetComponent<dae::Transform>();
	glm::vec3 pos = pTransform->GetPosition();

	float tileWidth = float(sqrt(3) * m_TileSize);
	float tileHeight = 2.f * m_TileSize;

	m_Grid.resize(m_Size);
	for (int r = 0; r < m_Size; r++)
	{
		std::vector<Tile*> rowOfTiles;
		int sizeCols = r + 1;
		rowOfTiles.resize(sizeCols);

		for (int c = 0; c < sizeCols; c++)
		{
			dae::GameObject* pTile = new dae::GameObject{};
			rowOfTiles[c] = new Tile{ m_TileSize };
			pTile->AddComponent(rowOfTiles[c]);

			dae::Transform* transform = pTile->GetComponent<dae::Transform>();

			transform->SetPosition(pos.x + tileWidth * (0.5f * ((m_Size - 1) - r) + c), pos.y + tileHeight * r, pos.z);
			pTile->SetTexture("Blocks.png", 1, 3);
			pTile->GetComponent<dae::TextureSpriteSheet>()->SetSize(tileWidth, tileHeight);

			m_pGameObject->AddChild(pTile);
		}
		m_Grid[r] = rowOfTiles;
	}
}

bool Grid::MoveUpRight(int& r, int& w) const
{
	if (int(m_Grid.size()) < 1)
	{
		ME_WARN("The grid is 0 rows big");
		return false;
	}

	if (r > 0 && w < int(m_Grid[r - 1].size()))
	{
		r--;
		return true;
	}
	return false;
}

bool Grid::MoveUpLeft(int& r, int& w) const
{
	if (int(m_Grid.size()) < 1)
	{
		ME_WARN("The grid is 0 rows big");
		return false;
	}

	if (r > 0 && w > 0)
	{
		r--;
		w--;
		return true;
	}
	return false;
}

bool Grid::MoveDownRight(int& r, int& w) const
{
	if (int(m_Grid.size()) < 1)
	{
		ME_WARN("The grid is 0 rows big");
		return false;
	}

	if (r < (m_Size - 1) && w < int(m_Grid[r].size()))
	{
		r++;
		w++;
		return true;
	}
	return false;
}

bool Grid::MoveDownLeft(int& r, int&) const
{
	if (int(m_Grid.size()) < 1)
	{
		ME_WARN("The grid is 0 rows big");
		return false;
	}

	if (r < (m_Size - 1))
	{
		r++;
		return true;
	}
	return false;
}

Tile* Grid::GetTile(int r, int w) const
{
	return m_Grid[r][w];
}
