#include "Player.h"
#include "WaveManager.h"
#include "CollisionDetection.h"
/*

THINGS TO FIX:

Drawing of enemies: 
	Need to make all the enemies render, not stack ontop of eachother.
	Need to stagger enemies so they don't form a wall

GameState
	Should add a game state for start, win/lose


*/


#ifdef main
# undef main
#endif

int main()
{
	//SDLEntity is a game entity that will initialize SDL components
	GameEntity SDLEntity;

	//Initialize SDL
	SDLEntity.InitializeSDL();

	//Set up a timer
	//This should be moved to a class sometime
	float time, preTime, deltaTime;
	time = 0.0f;
	preTime = 0.0f;
	deltaTime = 0.0f;

	//Get the player instance and load its spirte
	//Then set clips from spritesheet and set boxes for collision
	Player* player = Player::Instance();

	//WaveManager, handles creating waves of enemies
	WaveManager* waveManager = WaveManager::Instance();

	//Create collision handler
	CollisionDetection collisionHandler;

	//Game loop!
	//Since input is handled in Player class I have to pull things from Player
	//I should make an input handler
	while (player->isPlaying)
	{

		//Timer
		time = SDL_GetTicks();
		deltaTime = (time - preTime) / 100;
		preTime = time;

		//Renderer
		SDL_SetRenderDrawColor(SDLEntity.GetRenderer(), 0xFF, 0xFF, 0xFF, 0xFF);
		SDL_RenderClear(SDLEntity.GetRenderer());

		//Update player and waveManager
		player->Update(deltaTime);
		waveManager->Update(deltaTime);

		//Determine if player is casting
		if (player->cast)
	 	 {
			//if player is casting, update the mana bar
			player->UpdateManaRec(0.02f);

			//This epic loop, in all it's glory, checks for collision by iterating though the wave
			for (waveManager->GetWave()->list_it = waveManager->GetWave()->Enemies.begin(); waveManager->GetWave()->list_it != waveManager->GetWave()->Enemies.end(); waveManager->GetWave()->list_it++)
			{

				//Check for collision between enemy and player while player is casting
				if (player->fireshield.checkCollision(player->GetBoundingBox(), waveManager->GetWave()->list_it->GetBoundingBox()))
				{
					//This needs to be changed to remove the enemy collided with
					//Currently a place holder to visually show collision is working
					waveManager->GetWave()->list_it->Location = Vector2f<float>(100.0f, 100.0f);
				}
			}
			
		}

		//Check if player isn't casting.
		if (!player->cast)
		{
			if (player->GetMana() != player->GetMaxMana() && player->GetMana() <= player->GetMaxMana())
				player->UpdateManaRec(-.03f);

			//If player isn't casting and  there is a collision
			//Here is that epic loop again.
			for (waveManager->GetWave()->list_it = waveManager->GetWave()->Enemies.begin(); waveManager->GetWave()->list_it != waveManager->GetWave()->Enemies.end(); waveManager->GetWave()->list_it++)
			{
				//Check for collision between enemy and player while player is casting
				if (player->fireshield.checkCollision(player->GetBoundingBox(), waveManager->GetWave()->list_it->GetBoundingBox()))
				{
					//Again, place holder to visually show collision is working
					//This should be changed to initiate a game over screen
					player->Location = Vector2f<float>(SDLEntity.GetWindowWidth() / 2, SDLEntity.GetWindowHeight() - 100);
				}
				
			}
		}

		//std::cout << waveManager->GetWave()->Enemies.size() << std::endl;

		//Present renderer to show sprites
		SDL_RenderPresent(SDLEntity.GetRenderer());

	}


	return 0;
}