#include "Wave.h"

Wave::Wave()
{
	//Set enemy count and enemies per wave
	enemiesPerWave = 1000;
	enemyCount = 0;
	waveReady = false;
}

Wave::~Wave()
{
	Enemies.clear();
	enemyCount = 0;
}

//Creates the wave of enemies
void Wave::CreateWave()
{
	//If the wave list isn't full, add enemies
	if (enemyCount < enemiesPerWave)
		AddEnemy();

	//If there are enough enemies, the wave is ready
	if (enemyCount >= enemiesPerWave)
		waveReady = true;
}

void Wave::AddEnemy()
{
	srand(time(NULL));

	//Loop to add enemies to the wave
	for (enemyCount; enemyCount < enemiesPerWave; enemyCount++)
	{
		int xPos = 0, yPos = 0, randThing;

		randThing = rand() % 50;

		//loop ensures better random position
		//for starting x location of enemy
		for (int y = 0; y < randThing; y++)
		{
			xPos = (float)(rand() % 601);
			yPos = (float)(rand() % 10001);
		}

		yPos *= -1;

		//Create new enemy for the list
		Enemy* enemy = new Enemy();

		//Edit the enemy location
		enemy->Location = Vector2f <float>(xPos, yPos);

		//Add the enemy to the list
		Enemies.push_back(*enemy);
	}
}

//Enemy* Wave::GetEnemy(int index)
//{
//	for (int i = 0; i < Enemies.size; i++)
//	{
//		return &Enemies.at(index);
//	}
//}

//Update Wave
void Wave::Update(float deltaTime)
{
	//Checks if the wave is ready
	//If it isn't, create the wave
	if (!waveReady)
		CreateWave();

	//If the wave is ready, spawn enemies
	if (waveReady)
	{
		//Check to make sure the wave isn't empty
		if (!Enemies.empty())
		{
			//Iterate through the list of enemies and update them
			for (list_it = Enemies.begin(); list_it != Enemies.end(); list_it++)
			{
				list_it->Update(deltaTime);
			}
			//Call Draw
			//This isn't really necessary, but it doesn't hurt anything either
			//Draw();
		}
	}
}

//Draw Wave
//Draw doesn't seem to be necessary.
void Wave::Draw()
{
	//Check if the wave is empty
	if (!Enemies.empty())
	{
		//Ierate through the list and draw the enemies
		for (list_it = Enemies.begin(); list_it != Enemies.end(); list_it++)
		{
			list_it->Draw();
		}
	}
}