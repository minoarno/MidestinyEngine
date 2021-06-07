#pragma once
#include <vector>
#include "BaseComponent.h"

class Tile;
class Grid final: public BaseComponent
{
public:
	Grid(int size, float tileSize);
	Grid(const Grid& other) = delete;
	Grid& operator=(const Grid& other) = delete;
	Grid(Grid&& other) = delete;
	Grid& operator=(Grid&& other) = delete;
	~Grid();

	void Initialize() override;
	void CreateGrid();

	bool MoveUpRight(int& r, int& w)const;
	bool MoveUpLeft(int& r, int& w)const;
	bool MoveDownRight(int& r, int& w)const;
	bool MoveDownLeft(int& r, int& w)const;

	Tile* GetTile(int r, int w)const;
private:
	std::vector<std::vector<Tile*>> m_Grid;
	int m_Size = 7;
	float m_TileSize;
};

