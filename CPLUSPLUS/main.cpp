#include "Player.h"
#include "Enemy.h"
#include "CollisionDetection.h"

#ifdef main
# undef main
#endif

const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 600;

SDL_Window* mWindow = NULL;
SDL_Renderer* mRenderer = NULL;

int main()
{

	SDL_Init(SDL_INIT_VIDEO);

	SDL_SetHint(SDL_HINT_RENDER_VSYNC, "1");
	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1");

	mWindow = SDL_CreateWindow("CPLUSPLUS", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
		WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);

	mRenderer = SDL_CreateRenderer(mWindow, -1, SDL_RENDERER_ACCELERATED);

	float time, preTime, deltaTime;
	time = 0.0f;
	preTime = 0.0f;
	deltaTime = 0.0f;

	time = SDL_GetTicks();
	deltaTime = (time - preTime) / 1000;
	preTime = time;

	Player player;
	player.LoadFromFile("WizardSpriteSheet2.png", mRenderer);
	player.SetPlayerRenderer(mRenderer);
	player.SetSpriteClips();
	player.SetBoundingBox();

	Enemy enemy;
	enemy.LoadFromFile("EvilWizardSpriteSheet.png", mRenderer);
	enemy.SetEnemyRenderer(mRenderer);
	enemy.SetSpriteClips();
	enemy.SetBoundingBox();

	CollisionDetection collisionHandler;

	SDL_Rect fireShieldBox;

	while (player.isPlaying)
	{
		enemy.PlayerReference(player);

		SDL_SetRenderDrawColor(mRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
		SDL_RenderClear(mRenderer);

		player.Update(deltaTime);
		enemy.Update(deltaTime);

		if(player.cast)
		{
			player.fireShield.Update(deltaTime, player.Location);

			if (player.fireShield.checkCollision(player.GetBoundingBox(), enemy.GetBoundingBox()))
			{
				enemy.Location = Vector2f(0.0f, 0.0f);
			}
		}

		if (!player.cast)
		{
			if (collisionHandler.Check_Box_Collision(player.GetBoundingBox(), enemy.GetBoundingBox()))
			{
				player.Location = Vector2f(750.0f, 550.0f);
			}
		}

		SDL_RenderPresent(mRenderer);

	}


	return 0;
}