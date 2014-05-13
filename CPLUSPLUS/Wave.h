#ifndef WAVE_H
#define WAVE_H

#include "Enemy.h"

class Wave : public Enemy
{

public:
	std::list<Enemy> Enemies;				//List of enemies
	std::list<Enemy>::iterator list_it;		//List iterator
	int enemiesPerWave, enemyCount;			//Controls size of lise
	bool waveReady = false;					//Determine if the wave is ready to update/render

	Wave();									//Constructor
	~Wave();								//Deconstructor

	void CreateWave();						//Creat wave (add enemies to list)
	void AddEnemy();						//Creates list of enemies
	void Update(float deltaTime);			//Updates wave
	void Draw();							//Draw Wave
	

protected:

private:


};


#endif