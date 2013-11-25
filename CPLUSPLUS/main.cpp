#include "Player.h"
#include "Enemy.h"

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
	player.LoadSpells();

	Enemy enemy;
	enemy.LoadFromFile("Wizard.png", mRenderer);
	enemy.SetEnemyRenderer(mRenderer);

	while (player.isPlaying)
	{
		
		SDL_SetRenderDrawColor(mRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
		SDL_RenderClear(mRenderer);

		player.Draw();

		player.Update(deltaTime);
		enemy.Update(deltaTime);

		if(player.cast)
			player.fireShield.Update(deltaTime, player.Location);

		SDL_RenderPresent(mRenderer);

	}


	return 0;
}