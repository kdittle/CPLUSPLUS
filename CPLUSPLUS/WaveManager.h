#ifndef WAVEMANAGER_H
#define WAVEMANAGER_H

#include "Headers.h"
#include "Enemy.h"
#include <vector>

class WaveManager : public Enemy
{
	typedef Enemy Base;

public:
	//Enemy enemy;
	std::vector<Enemy> Wave;

	static WaveManager* Instance();

	WaveManager();
	~WaveManager();

	void InitializeWave();
	void Update(float deltaTime);
	void Draw(float deltaTime);


private:


protected:


};



#endif