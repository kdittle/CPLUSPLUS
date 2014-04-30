#include "WaveManager.h"

WaveManager* WaveManager::Instance()
{
	static WaveManager* instance = nullptr;

	if (instance == nullptr)
		instance = new WaveManager();

	return instance;
}

WaveManager::WaveManager()
{

}

WaveManager::~WaveManager()
{

}

void WaveManager::InitializeWave()
{
	int xPos;
	srand(time(NULL));

	for (int i = 0; i < 50; i++)
	{
		Enemy enemy;

		for (int y = 0; y < 50; y++)
			xPos = (float)(rand() % 501);

		enemy.Location = Vector2f<float>(xPos, 0.0f);

		Wave.push_back(enemy);

	}
}

void WaveManager::Update(float deltaTime)
{
	Draw(deltaTime);
}

void WaveManager::Draw(float deltaTime)
{
	if (!Wave.empty)
	{
		for (list_it = Wave.begin(); list_it != Wave.end(); list_it++)
		{
			Wave.back().Update(deltaTime);
			Wave.pop_back();
		}
	}
}