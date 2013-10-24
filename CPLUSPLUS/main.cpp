#include "InitGL.h"
#include "Level.h"

#ifdef main
# undef main
#endif

int main()
{

	SDL_Init(SDL_INIT_VIDEO);

	SDL_Window* window = SDL_CreateWindow("CPLUSPLUS", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
		WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_OPENGL);

	SDL_GLContext mainGLContext = SDL_GL_CreateContext(window);

	Initialize_glDisplay();

	float moveSpeed = .1f;
	float x = 25, y = WINDOW_HEIGHT - 35;

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

					if(event.key.keysym.sym == SDLK_LEFT)
						left = true;
					if(event.key.keysym.sym == SDLK_RIGHT)
						right = true;
					if(event.key.keysym.sym == SDLK_UP)
						up = true;
					if(event.key.keysym.sym == SDLK_DOWN)
						down = true;

					break;
				}

			case(SDL_KEYUP) :
				{
					std::cout << "Keyup" << std::endl;

					if(event.key.keysym.sym == SDLK_LEFT)
						left = false;
					if(event.key.keysym.sym == SDLK_RIGHT)
						right = false;
					if(event.key.keysym.sym == SDLK_UP)
						up = false;
					if(event.key.keysym.sym == SDLK_DOWN)
						down = false;

					break;
				}

			}
		}

		//Allows input to move square
		if(left)
		{
			x -= moveSpeed;
			std::cout << x << std::endl;
		}
		if(right)
		{
			x += moveSpeed;
			std::cout << x << std::endl;
		}
		if(up)
		{
			y -= moveSpeed;
			std::cout << y << std::endl;
		}
		if(down)
		{
			y += moveSpeed;
			std::cout << y << std::endl;
		}

		Render(x, y);
		

		//Clamp to X
		if(x >= 775)
			x = 775;
		if(x <= 25)
			x = 25;

		//Clamp to Y
		if(y >= 575)
			y = 575;
		if(y <= 25)
			y = 25;


		SDL_GL_SwapWindow(window);
	}

	return 0;
}