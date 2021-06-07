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
	dae::Transform* pTransform = m_pGameObject->GetComponent<dae::Transform>();
	glm::vec3 pos = pTransform->GetPosition();

	float tileWidth = float(sqrt(3) * m_TileSize);
	float tileHeight = 2.f * m_TileSize;

	m_Grid.resize(m_Size);
	for (int r = 0; r < m_Size; r++)
	{
		std::vector<Tile*> vector;
		int sizeCols = r + 1;
		vector.resize(sizeCols);
		for (int c = 0; c < sizeCols; c++)
		{
			dae::GameObject* pObject = new dae::GameObject{};
			vector[c] = new Tile{ m_TileSize };
			pObject->AddComponent(vector[c]);
			dae::Transform* transform = pObject->GetComponent<dae::Transform>();
			transform->SetPosition(pos.x + tileWidth * (0.5f * ((m_Size - 1) - r) + c), pos.y + tileHeight * r, pos.z);
			pObject->SetTexture("Blocks.png", 1, 3);
			pObject->GetComponent<dae::TextureSpriteSheet>()->SetSize(tileWidth,tileHeight);
			m_pGameObject->AddChild(pObject);
		}
		m_Grid[r] = vector;
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

	if (r < (m_Size - 1) && w < int(m_Grid[r].size() - 1))
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
