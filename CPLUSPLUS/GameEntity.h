#ifndef GAMEENTITY_H
#define GAMEENTITY_H

#include "OpenGLHeaders.h"
#include "Vector2f.h"

class GameEntity
{
public:
	Vector2f Location;
	Vector2f X_Velocity;
	Vector2f Y_Velocity;

	GameEntity();
	~GameEntity();

	void Destory();
	void Update();

	void free();
	bool LoadFromFile(const std::string filePath);
	void Render(Vector2f position, SDL_Rect* clip = NULL, float angle = 0.0f, SDL_Point* center = NULL,
		SDL_RendererFlip = SDL_FLIP_NONE);
	void Draw(SDL_Window* tragetWindow);

	int getWidth();
	int getHeight();

private:
	SDL_Texture* mTexture;

	int mWidth;
	int mHeight;

};

#endif