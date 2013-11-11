#include "Level.h"
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

	mWindow = SDL_CreateWindow("CPLUSPLUS", 0.0f, 0.0f, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_VIDEO_OPENGL);

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

	bool 
		left = false,
		right = false,
		up = false,
		down = false;

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
					std::cout << "Keydown" << std::endl;

					if(event.key.keysym.sym == SDLK_ESCAPE)
						run = false;

					break;
				}
			}

			player.Draw(mWindow);

			player.Update(deltaTime);
		}
	}



	return 0;
}