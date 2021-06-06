#pragma once
#include <vector>
#include "BaseComponent.h"

class Tile;
class Grid : public BaseComponent
{
public:
	Grid(int size, float tileSize);
	Grid(const Grid& other) = delete;
	Grid& operator=(const Grid& other) = delete;
	Grid(Grid&& other) = delete;
	Grid& operator=(Grid&& other) = delete;
	~Grid();

	virtual void Initialize() override;

	bool MoveUpRight(int& r, int& w);
	bool MoveUpLeft(int& r, int& w);
	bool MoveDownRight(int& r, int& w);
	bool MoveDownLeft(int& r, int& w);

	Tile* GetTile(int r, int w);
private:
	std::vector<std::vector<Tile*>> m_Grid;
	int m_Size;
	float m_TileSize;
};

