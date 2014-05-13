#ifndef WAVEMANAGER_H
#define WAVEMANAGER_H

#include "Headers.h"
#include "Wave.h"

class WaveManager : public Wave
{

public:

	static WaveManager* Instance();

	bool waveStarting, waveRunning;
	Wave wave;

	WaveManager();
	~WaveManager();

	void InitializeWave();
	void Update(float deltaTime);
	Wave* GetWave();


private:


protected:


};

#endif