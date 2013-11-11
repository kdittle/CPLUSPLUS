#ifndef LTEXTURE_H
#define LTEXTURE_H

#include "Headers.h"

class LTexture
{
public:
	LTexture();
	~LTexture();

	bool LoadFromFile(std::string filePath);

	void free();

	int getWidth();
	int getHeight();

private:
	SDL_Texture* lTexture;

	int mWidth;
	int mHeight;

};


#endif