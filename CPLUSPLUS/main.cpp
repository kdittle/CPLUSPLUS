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
	waveManager->InitializeWave();

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

		//Update player and enemy
		player->Update(deltaTime);
		waveManager->Update(deltaTime);

		//Determine if player is casting
		if (player->cast)
		{
			//if player is casting, update the mana bar
			player->UpdateManaRec(0.08f);

			////Check for collision between enemy and player while player is casting
			//if (player->fireshield.checkCollision(player->GetBoundingBox(), )
			//{

			//}
		}

		//Check if player isn't casting.
		if (!player->cast)
		{
			if (player->GetMana() != player->GetMaxMana() && player->GetMana() <= player->GetMaxMana())
				player->UpdateManaRec(-.03f);

			////If player isn't casting and  there is a collision, move player to lower right corner
			//if (collisionHandler.Check_Box_Collision(player->GetBoundingBox(),))
			//{
			//	player->Location = Vector2f<float>(725.0f, 480.0f);
			//	player->UpdateHealthRec(2.0f);
			//}
		}
		

		//Present renderer to show sprites
		SDL_RenderPresent(SDLEntity.GetRenderer());

	}


	return 0;
}