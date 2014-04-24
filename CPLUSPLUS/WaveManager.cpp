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

	for (int i = 0; i < 100; i++)
	{
		Enemy enemy;

		for (int y = 0; y < 100; y++)
			xPos = (float)(rand() % 501);

		enemy.Location = Vector2f<float>(xPos, 0.0f);

		Wave.push_back(enemy);

	}
}

void WaveManager::Update(float deltaTime)
{
	std::vector<Enemy*>::iterator vec_it;

	for (auto& vec_it : Wave)
	{
		vec_it.Draw();
	}

	//Base::Update(deltaTime);
}

void WaveManager::Draw(float deltaTime)
{

	std::vector<Enemy*>::iterator vec_it;

	for (auto& vec_it : Wave)
	{
		vec_it.Update(deltaTime);
	}
}