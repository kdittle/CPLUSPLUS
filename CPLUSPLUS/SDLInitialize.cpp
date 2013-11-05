#include "SDLInitialize.h"
#include "InitGL.h"

SDL_Window* mWindow = NULL;
SDL_GLContext mainGLContext = NULL;
SDL_Renderer* mRenderer = NULL;

void Initialize_SDL()
{
	SDL_Init(SDL_INIT_VIDEO);

	mWindow = SDL_CreateWindow("CPLUSPLUS", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
		WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_OPENGL);

	mainGLContext = SDL_GL_CreateContext(mWindow);

	mRenderer = SDL_CreateRenderer(mWindow, -1, SDL_RENDERER_ACCELERATED);
}

void SDL_Update()
{
	SDL_GL_SwapWindow(mWindow);
}