#ifndef INPUTHANDLER_H
#define INPUTHANDLER_H

#include "Headers.h"

class InputHandler
{
public:

	int KeyboardInput();
	void Update();

private:
	const Uint8* keyState;
	SDL_Event event;

protected:

};

#endif