#include "LTexture.h"

LTexture::LTexture()
{
	lTexture = NULL;
	mWidth = 0;
	mHeight = 0;
}

LTexture::~LTexture()
{
	free();
}

bool LTexture::LoadFromFile(std::string filePath)
{

	SDL_Texture* newTexture = NULL;

	SDL_Surface* loadedSurface = IMG_Load(filePath.c_str());
	if(loadedSurface == NULL)
	{
		printf("Unable to load image %s! SDL_image Error: %s/n", filePath.c_str(), SDL_GetError());
	}
	else
	{
		SDL_SetColorKey(loadedSurface, SDL_TRUE, SDL_MapRGB(loadedSurface->format, 0xFF, 0xFF, 0xFF));

		//newTexture = SDL_CreateTextureFromSurface(renderer, loadedSurface);
		if(newTexture == NULL)
		{
			printf("Unable to create texture from %s! SDL_Error %s\n", filePath.c_str(), SDL_GetError());
		}
		else
		{
			mWidth = loadedSurface->w;
			mHeight = loadedSurface->h;
		}

		SDL_FreeSurface(loadedSurface);
	}

	lTexture = newTexture;

	return lTexture != NULL;

}

void LTexture::free()
{
	if(lTexture != NULL)
	{
		SDL_DestroyTexture(lTexture);
		lTexture = NULL;
		mWidth = 0;
		mHeight = 0;
	}
}

int LTexture::getWidth()
{
	return mWidth;
}

int LTexture::getHeight()
{
	return mHeight;
}
