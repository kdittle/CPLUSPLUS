#ifndef PROJECTILE_H
#define PROJECTILE_H

#include "Headers.h"
#include "GameEntity.h"

class Projectile : public GameEntity
{
	typedef GameEntity Base;

public:
	float Speed;
	static const int FIRE_FRAMES = 3;
	SDL_Rect SpriteClips[FIRE_FRAMES];

	Projectile();

	void SetSpriteClips();
	void Update(float deltaTime);
	void Draw(SDL_Renderer* renderer, float deltaTime);

	int frame;

private:

};

#endif