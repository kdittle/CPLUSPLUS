#ifndef WAVEMANAGER_H
#define WAVEMANAGER_H

#include "Headers.h"
#include "Wave.h"

class WaveManager
{

public:

	static WaveManager* Instance();		//WaveManager singleton

	bool waveStarting, waveRunning;		//Booleans for determining wave status
	Wave wave;							//Here's the wave

	WaveManager();						//Constructor
	~WaveManager();						//Deconstructor

	void InitializeWave();				//Set up the wave
	void Update(float deltaTime);		//Update Wave
	Wave* GetWave();					//Return the wave


private:


protected:


};

#endif