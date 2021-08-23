#pragma once
#include "EnemyManager.h"
#include "MiniginPCH.h"
#include <fstream>
#include <iostream>

#include "BinaryDataType.h"
#include "BinaryReader.h"
#include "BinaryWriter.h"

#include "Enemy.h"
#include "Zako.h"
#include "Goei.h"
#include "BossGalaga.h"

#include "GameObject.h"
#include "Scene.h"
#include "TextureSpriteSheet.h"

#include "Log.h"

EnemyManager::EnemyManager(dae::Scene* pScene,float xSpawner, float ySpawner)
	: m_pScene{ pScene }
	, m_SpawnerX{ xSpawner }
	, m_SpawnerY{ ySpawner }
{
}

EnemyManager::~EnemyManager()
{
}

void EnemyManager::LoadFromFile(const std::string& filename)
{
	std::ifstream in{ };
	in.open(filename);
	if (!in)
	{
		//ME_WARN(L"No such file");
	}
	BinaryReader::ReadDataTypeFromBin(in);
	float enemySize = BinaryReader::ReadFloatFromBin(in);

	int count{ 0 };
	while (!in.eof())
	{

		BinaryReader::ReadDataTypeFromBin(in);
		EnemyType et = EnemyType(BinaryReader::ReadIntFromBin(in));
		BinaryReader::ReadDataTypeFromBin(in);
		int cols = BinaryReader::ReadIntFromBin(in);
		BinaryReader::ReadDataTypeFromBin(in);
		int rows = BinaryReader::ReadIntFromBin(in);

		for (int r = count; r < count + rows; r++)
		{
			for (int c = 0; c < cols; c++)
			{
				dae::GameObject* pObject = new dae::GameObject();


				pObject->GetComponent<dae::Transform>()->Translate({m_SpawnerX + (c - cols * .5f) * enemySize, m_SpawnerY - r * enemySize,0});
				Enemy* pEnemy = nullptr;
				switch (et)
				{
				case EnemyType::Goei:
					pEnemy = new Goei();
					pObject->AddComponent(pEnemy);
					pObject->SetTexture("Goei.png");
					pObject->GetComponent<dae::Texture2D>()->SetSize(enemySize, enemySize);
					break;
				case EnemyType::Galaga:
					pEnemy = new BossGalaga();
					pObject->AddComponent(pEnemy);
					pObject->SetTexture("GalagaBoss.png",1,2);
					pObject->GetComponent<dae::TextureSpriteSheet>()->SetSize(enemySize, enemySize);
					break;
				case EnemyType::Zako:
					pEnemy = new Zako();
					pObject->AddComponent(pEnemy);
					pObject->SetTexture("Zako.png");
					pObject->GetComponent<dae::Texture2D>()->SetSize(enemySize, enemySize);
					break;
				default:
					break;
				}
				m_pEnemies.push_back(pEnemy);

				m_pScene->Add(pObject);
			}
		}
		count += rows;
	}
}

void EnemyManager::SaveToFiile(const std::string& filename, float monsterSize, int amountOfColsZako, int amountOfRowsZako, int amountOfColsGoei, int amountOfRowsGoei, int amountOfColsGalaga, int amountOfRowsGalaga)
{
	std::ofstream out{};
	out.open(filename);

	BinaryWriter::SaveToBin(out, monsterSize);

	BinaryWriter::SaveToBin(out,int(EnemyType::Zako));
	BinaryWriter::SaveToBin(out,amountOfColsZako);
	BinaryWriter::SaveToBin(out,amountOfRowsZako);

	BinaryWriter::SaveToBin(out, int(EnemyType::Goei));
	BinaryWriter::SaveToBin(out, amountOfColsGoei);
	BinaryWriter::SaveToBin(out, amountOfRowsGoei);

	BinaryWriter::SaveToBin(out, int(EnemyType::Galaga));
	BinaryWriter::SaveToBin(out, amountOfColsGalaga);
	BinaryWriter::SaveToBin(out, amountOfRowsGalaga);

	out.close();
}
