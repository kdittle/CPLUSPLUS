#ifndef GAMEENTITY_H
#define GAMEENTITY_H

#include "Headers.h"
#include "Vector2f.h"

class GameEntity
{
public:
	SDL_Texture* mTexture;
	Vector2f<float> Location;
	SDL_Rect m_BoundingBox;
	std::vector<SDL_Rect> m_ColliderBoxes;


	GameEntity();
	~GameEntity();

	void Destory();
	void Update(float deltaTime);

	void free();
	bool LoadFromFile(const std::string filePath, SDL_Renderer* renderer);
	void Render(Vector2f<float> position, SDL_Renderer* renderer, SDL_Rect* clip = NULL, float angle = 0.0f, SDL_Point* center = NULL,
		SDL_RendererFlip = SDL_FLIP_NONE);


	int getWidth();
	int getHeight();

	SDL_Rect GetBoundingBox();
	std::vector<SDL_Rect>& GetColliderBoxes();

	void shiftBoundingBox();
	void shiftColliderBoxes();

private:

	int mWidth;
	int mHeight;

};

#endif