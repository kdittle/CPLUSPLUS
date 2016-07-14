#ifndef WAVE_H
#define WAVE_H

#include "Enemy.h"

class Wave : public Enemy
{

public:
	std::vector<Enemy> Enemies;				//List of enemies
	std::vector<Enemy>::iterator list_it;	//List iterator
	int enemiesPerWave, enemyCount;			//Controls size of lise
	bool waveReady;					//Determine if the wave is ready to update/render

	Wave();									//Constructor
	~Wave();								//Deconstructor

	void CreateWave();						//Creat wave (add enemies to list)
	void AddEnemy();						//Creates list of enemies
	//Enemy* GetEnemy(int index);				//Get an enemy
	void Update(float deltaTime);			//Updates wave
	void Draw();							//Draw Wave
	

protected:

private:


};


#endif