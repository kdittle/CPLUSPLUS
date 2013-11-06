#include "Level.h"
#include "Vector2f.h"

#ifdef main
# undef main
#endif

const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 600;
const int SCREEN_FPS = 60;

int main()
{

	Vector2f location = Vector2f(25.0f, (float)(WINDOW_HEIGHT - 35));
	Vector2f xVelocity = Vector2f(2.0f, 0.0f);
	Vector2f yVelocity = Vector2f(0.0f, 2.0f);

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
			location.subtract(xVelocity);
			std::cout << location.x << " " << location.y << std::endl;
		}
		if(right)
		{
			location.add(xVelocity);
			std::cout << location.x << " " << location.y << std::endl;
		}
		if(up)
		{
			location.subtract(yVelocity);
			std::cout << location.x << " " << location.y << std::endl;
		}
		if(down)
		{
			location.add(yVelocity);
			std::cout << location.x << " " << location.y << std::endl;
		}


		//Update

		//Clamp to X
		if(location.x >= 775)
			location.x = 775;
		if(location.x <= 25)
			location.x = 25;

		//Clamp to Y
		if(location.y >= 575)
			location.y = 575;
		if(location.y <= 25)
			location.y = 25;


		//SDL Update (Swap Screen)
	}

	return 0;
}