#include "Player.h"
#include "Enemy.h"
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
	player->LoadFromFile("WizardSpriteSheet2.png");
	player->SetSpriteClips();
	player->SetBoundingBox();

	//Set up enemy, load sprite sheet, set clips, and set boxes
	Enemy enemy;
	enemy.LoadFromFile("EvilWizardSpriteSheet.png");
	enemy.SetSpriteClips();
	enemy.SetBoundingBox();

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
		enemy.Update(deltaTime);

		//Determine if player is casting
		if (player->cast)
		{
			//if player is casting, draw the shield at the player's location
			player->fireShield.Update(deltaTime, player->Location);

			//Check for collision between enemy and player while player is casting
			if (player->fireShield.checkCollision(player->GetBoundingBox(), enemy.GetBoundingBox()))
			{
				//If player is casting and there is a collision, move enemy to upper left corner
				enemy.Location = Vector2f<float>(0.0f, 0.0f);
			}
		}

		//Check if player isn't casting.
		if (!player->cast)
		{
			//If player isn't casting and  there is a collision, move player to lower right corner
			if (collisionHandler.Check_Box_Collision(player->GetBoundingBox(), enemy.GetBoundingBox()))
			{
				player->Location = Vector2f<float>(725.0f, 480.0f);
			}
		}

		//Present renderer to show sprites
		SDL_RenderPresent(SDLEntity.GetRenderer());

	}


	return 0;
}