#include "Player.h"
#include "WaveManager.h"
#include "CollisionDetection.h"

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

		//Update player
		player->Update(deltaTime);
		waveManager->Update(deltaTime);

		//Determine if player is casting
		if (player->cast)
	 	 {
			//if player is casting, update the mana bar
			player->UpdateManaRec(0.02f);

			for (waveManager->list_it = waveManager->Enemies.begin(); waveManager->list_it != waveManager->Enemies.end(); waveManager->list_it++)
			{
				//Check for collision between enemy and player while player is casting
				if (player->fireshield.checkCollision(player->GetBoundingBox(), waveManager->list_it->GetBoundingBox()))
				{
					waveManager->list_it->Location = Vector2f<float>(100.0f, 100.0f);
				}
			}
			
		}

		//Check if player isn't casting.
		if (!player->cast)
		{
			if (player->GetMana() != player->GetMaxMana() && player->GetMana() <= player->GetMaxMana())
				player->UpdateManaRec(-.03f);

			//If player isn't casting and  there is a collision
			for (waveManager->list_it = waveManager->Enemies.begin(); waveManager->list_it != waveManager->Enemies.end(); waveManager->list_it++)
			{
				//Check for collision between enemy and player while player is casting
				if (player->fireshield.checkCollision(player->GetBoundingBox(), waveManager->list_it->GetBoundingBox()))
				{
					player->Location = Vector2f<float>(SDLEntity.GetWindowWidth() / 2, SDLEntity.GetWindowHeight() / 2);
				}
				
			}
		}

		//std::cout << waveManager->Wave.size() << std::endl;

		//Present renderer to show sprites
		SDL_RenderPresent(SDLEntity.GetRenderer());

	}


	return 0;
}