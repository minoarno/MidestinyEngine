#pragma once
#include <vector>
#include "BaseComponent.h"

class Tile;
class Grid : public BaseComponent
{
public:
	Grid(unsigned int size, float tileSize);
	Grid(const Grid& other) = delete;
	Grid& operator=(const Grid& other) = delete;
	Grid(Grid&& other) = delete;
	Grid& operator=(Grid&& other) = delete;
	~Grid();

	virtual void Initialize() override;

	void MoveUpRight(int& r, int& w);
	void MoveUpLeft(int& r, int& w);
	void MoveDownRight(int& r, int& w);
	void MoveDownLeft(int& r, int& w);

	Tile* GetTile(int r, int w);
private:
	std::vector<std::vector<Tile*>> m_Grid;
	unsigned int m_Size;
	float m_TileSize;
};

