#ifndef PROJECTILE_H
#define PROJECTILE_H

#include "Headers.h"
#include "GameEntity.h"

class Projectile : public GameEntity
{
	typedef GameEntity Base;

public:
	float Speed;
	SDL_Renderer* projRenderer;
	static const int FIRE_FRAMES = 3;
	SDL_Rect SpriteClips[FIRE_FRAMES];

	Projectile();

	void SetProjectileRenderer(SDL_Renderer* renderer);
	void SetSpriteClips();
	void Update(float deltaTime);
	void Draw(SDL_Renderer* renderer);

	int frame;

private:

};

#endif