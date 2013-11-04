#ifndef LTEXTURE_H
#define LTEXTURE_H

#include "OpenGLHeaders.h"

class LTexture
{
public:
	LTexture();
	~LTexture();

	bool LoadFromFile(std::string filePath);

	void free();
	void Render(Vector2f position, SDL_Rect* clip = NULL, float angle = 0.0f, SDL_Point* center = NULL, SDL_RendererFlip = SDL_FLIP_NONE);

	int GetWidth();
	int getHeight();

private:
	SDL_Texture* mTexture;

	int mWidth;
	int mHeight;

};


#endif