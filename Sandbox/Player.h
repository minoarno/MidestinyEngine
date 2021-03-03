#pragma once
//#include "BaseComponent.h"
class Player final //: public BaseComponent
{
public:
	Player() = default;
	Player(const Player& other) = delete;
	Player& operator=(const Player& other) = delete;
	Player(Player&& other) = delete;
	Player& operator=(Player&& other) = delete;
	~Player() = default;

	void IncrementScore() { m_Score++; }
private:
	int m_Score = 0;
};

