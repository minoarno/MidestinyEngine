#pragma once
#include <string>
#include <vector>

namespace dae
{
	class Scene;
}

class Enemy;
class EnemyManager final
{
public:
	enum class EnemyType : int
	{
		Zako = 0,
		Goei = 1,
		Galaga = 2
	};

	EnemyManager(dae::Scene* pScene, float xSpawner, float ySpawner);
	EnemyManager(const EnemyManager& other) = delete;
	EnemyManager& operator=(const EnemyManager& other) = delete;
	EnemyManager(EnemyManager&& other) = delete;
	EnemyManager& operator=(EnemyManager&& other) = delete;
	~EnemyManager();

	void Update();

	void LoadFromFile(const std::string& filename);
	static void SaveToFiile(const std::string& filename, float monsterSize, int amountOfColsZako, int amountOfRowsZako, int amountOfColsGoei, int amountOfRowsGoei, int amountOfColsGalaga, int amountOfRowsGalaga);

	int GetAmountOfEnemiesAlive()const;
private:
	float m_SpawnerX;
	float m_SpawnerY;

	dae::Scene* m_pScene;
	std::vector<Enemy*> m_pEnemies;
};