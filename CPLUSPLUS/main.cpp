#include "Vector2f.h"
#include "Player.h"

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

	mWindow = SDL_CreateWindow("CPLUSPLUS", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
		WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_OPENGL);

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
	
	player.LoadFromFile("Thing.png", mRenderer);

	bool run = true;

	while(run)
	{
		SDL_Event event;

		SDL_PumpEvents();

		while(SDL_PollEvent(&event))
		{
			switch(event.type)
			{
			case(SDL_QUIT) :
				run = false;
				break;

			case(SDL_KEYDOWN) :
				{

					if(event.key.keysym.sym == SDLK_ESCAPE)
						run = false;

					break;
				}
			}

			player.Update(deltaTime);

			SDL_SetRenderDrawColor(mRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
			SDL_RenderClear(mRenderer);

			player.Render(player.Location, mRenderer);

			SDL_RenderPresent(mRenderer);
		}
	}


	return 0;
}