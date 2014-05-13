#include "WaveManager.h"


//Set up the singleton Instance
WaveManager* WaveManager::Instance()
{
	static WaveManager* instance = nullptr;

	if (instance == nullptr)
		instance = new WaveManager();

	return instance;
}

//Constructor donig it's constructing
WaveManager::WaveManager()
{
	waveStarting = true;
	waveRunning = false;
}

//Deconstructor
//Not doing anything
WaveManager::~WaveManager()
{

}

//Initialize the wave
//AKA create it
void WaveManager::InitializeWave()
{
	wave.CreateWave();

	waveStarting = false;
	waveRunning = true;
}

//Wave ready? Update it!
void WaveManager::Update(float deltaTime)
{
	if (waveStarting)
		InitializeWave();

	if (waveRunning)
		wave.Update(deltaTime);
}

//Oh you need the wave?
//Get it here
Wave* WaveManager::GetWave()
{
	return &wave;
}