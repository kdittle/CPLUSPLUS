#include "Player.h"
#include "Enemy.h"
#include "CollisionDetection.h"

#ifdef main
# undef main
#endif

int main()
{
	GameEntity SDLEntity;

	SDLEntity.InitializeSDL();

	float time, preTime, deltaTime;
	time = 0.0f;
	preTime = 0.0f;
	deltaTime = 0.0f;

	Player player;
	player.LoadFromFile("WizardSpriteSheet2.png");
	//player.SetPlayerRenderer(mRenderer);
	player.SetSpriteClips();
	player.SetBoundingBox();
	//player.ScreenRef(mScreen);
	//player.WindowRef(mWindow);

	Enemy enemy;
	enemy.LoadFromFile("EvilWizardSpriteSheet.png");
	//enemy.SetEnemyRenderer(mRenderer);
	enemy.SetSpriteClips();
	enemy.SetBoundingBox();

	CollisionDetection collisionHandler;

	while (player.isPlaying)
	{
		time = SDL_GetTicks();
		deltaTime = (time - preTime) / 1000;
		preTime = time;

		/*enemy.PlayerReference(player);*/

		SDL_SetRenderDrawColor(SDLEntity.GetRenderer(), 0xFF, 0xFF, 0xFF, 0xFF);
		SDL_RenderClear(SDLEntity.GetRenderer());

		player.Update(deltaTime);
		enemy.Update(deltaTime);

		if (player.cast)
		{
			/*player.fireShield.Update(deltaTime, player.Location);

			if (player.fireShield.checkCollision(player.GetBoundingBox(), enemy.GetBoundingBox()))
			{
			enemy.Location = Vector2f<float>(0.0f, 0.0f);
			}*/
		}

		if (!player.cast)
		{
			if (collisionHandler.Check_Box_Collision(player.GetBoundingBox(), enemy.GetBoundingBox()))
			{
				player.Location = Vector2f<float>(725.0f, 480.0f);
			}
		}

		SDL_RenderPresent(SDLEntity.GetRenderer());

	}


	return 0;
}