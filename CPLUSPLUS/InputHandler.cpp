#include "InputHandler.h"

int InputHandler::KeyboardInput()
{
	keyState = SDL_GetKeyboardState(NULL);

	SDL_PumpEvents();

	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT:
			return 1;
			break;

		case SDL_KEYDOWN:
		{
							if (keyState[SDL_SCANCODE_UP])
								return 2;
							if (keyState[SDL_SCANCODE_DOWN])
								return 3;
							if (keyState[SDL_SCANCODE_LEFT])
								return 4;
							if (keyState[SDL_SCANCODE_RIGHT])
								return 5;

							break;
		}

		case SDL_KEYUP:
		{
						  if (keyState[SDL_SCANCODE_UP])
							  return 2;
						  if (keyState[SDL_SCANCODE_DOWN])
							  return 3;
						  if (keyState[SDL_SCANCODE_LEFT])
							  return 4;
						  if (keyState[SDL_SCANCODE_RIGHT])
							  return 5;

						  break;
		}
		}

		return 0;
	}

}

void InputHandler::Update()
{

}