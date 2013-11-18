#include "Vector2f.h"
#include "Player.h"
#include "Projectile.h"

#ifdef main
# undef main
#endif

const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 600;
const int SCREEN_FPS = 60;

SDL_Window* mWindow = NULL;
SDL_GLContext mContext = NULL;
SDL_Renderer* mRenderer = NULL;

int main()
{

	SDL_Init(SDL_INIT_VIDEO);

	SDL_SetHint(SDL_HINT_RENDER_VSYNC, "1");
	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1");

	mWindow = SDL_CreateWindow("CPLUSPLUS", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
		WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);

	mContext = SDL_GL_CreateContext(mWindow);

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
	player.SetSpriteClips();
	player.SetPlayerRenderer(mRenderer);

	Projectile fire;
	fire.LoadFromFile("FireSpriteSheet.png", mRenderer);
	fire.SetSpriteClips();

	while (player.isPlaying)
	{

		player.Update(deltaTime);
		fire.Update(deltaTime);

		SDL_SetRenderDrawColor(mRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
		SDL_RenderClear(mRenderer);

		player.Draw();
		//fire.Draw(mRenderer, deltaTime);

		SDL_RenderPresent(mRenderer);

	}


	return 0;
}