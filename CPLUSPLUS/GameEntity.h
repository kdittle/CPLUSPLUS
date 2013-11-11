#ifndef GAMEENTITY_H
#define GAMEENTITY_H

#include "Headers.h"
#include "Vector2f.h"

class GameEntity
{
public:
	SDL_Texture* mTexture;
	Vector2f Location;

	GameEntity();
	~GameEntity();

	void Destory();
	void Update(float deltaTime);

	void free();
	bool LoadFromFile(const std::string filePath, SDL_Renderer* renderer);
	void Render(Vector2f position, SDL_Renderer* renderer, SDL_Rect* clip = NULL, float angle = 0.0f, SDL_Point* center = NULL,
		SDL_RendererFlip = SDL_FLIP_NONE);

	int getWidth();
	int getHeight();

private:

	int mWidth;
	int mHeight;

};

#endif