#ifndef WAVEMANAGER_H
#define WAVEMANAGER_H

#include "Headers.h"
#include "Enemy.h"
#include <list>

class WaveManager : public Enemy
{
	typedef Enemy Base;

public:
	std::list<Enemy> Wave;
	std::list<Enemy>::iterator list_it;

	static WaveManager* Instance();

	WaveManager();
	~WaveManager();

	void InitializeWave();
	void AddEnemy();
	void Update(float deltaTime);
	void Draw(float deltaTime);


private:


protected:


};

#endif