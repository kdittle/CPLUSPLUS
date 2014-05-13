#include "Wave.h"

Wave::Wave()
{
	enemiesPerWave = 100;
	enemyCount = 0;
}

Wave::~Wave()
{
	Enemies.clear();
	enemyCount = 0;
}

void Wave::CreateWave()
{
	if (enemyCount < enemiesPerWave)
		AddEnemy();

	if (enemyCount >= enemiesPerWave)
		waveReady = true;
}

void Wave::AddEnemy()
{

	for (enemyCount = 0; enemyCount < enemiesPerWave; enemyCount++)
	{
		int xPos = 0, yPos = 0, randThing;
		srand(time(NULL));

		randThing = rand() % 50;

		for (int y = 0; y < randThing; y++)
		{
			xPos = (float)(rand() % 501);
		}

		Enemy* enemy = new Enemy;

		enemy->Location = Vector2f <float>(xPos, 0.0f);

		Enemies.push_back(*enemy);
	}
}

void Wave::Update(float deltaTime)
{
	if (!waveReady)
		CreateWave();

	if (waveReady)
	{
		if (!Enemies.empty())
		{
			for (list_it = Enemies.begin(); list_it != Enemies.end(); list_it++)
			{
				this->list_it->Update(deltaTime);
			}
			Draw();
		}
	}

	//if (!Enemies.empty())
	//{

	//	for (list_it = Enemies.begin(); list_it != Enemies.end(); list_it++)
	//	{
	//		if (list_it->Location._y > WINDOW_HEIGHT)
	//		{
	//			list_it++;
	//			Enemies.erase(list_it--);
	//		}
	//	}
	//}
}

void Wave::Draw()
{
	if (!Enemies.empty())
	{
		for (list_it = Enemies.begin(); list_it != Enemies.end(); list_it++)
		{
			this->list_it->Draw();
		}
	}
}