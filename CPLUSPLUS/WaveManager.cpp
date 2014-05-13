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
	waveStarting = true;
	waveRunning = false;
}

WaveManager::~WaveManager()
{

}

void WaveManager::InitializeWave()
{
	wave.CreateWave(); 

	waveStarting = false;
	waveRunning = true;
}

void WaveManager::Update(float deltaTime)
{
	if (waveStarting)
		InitializeWave();

	if (waveRunning)
		wave.Update(deltaTime);
}

Wave* WaveManager::GetWave()
{
	return &wave;
}