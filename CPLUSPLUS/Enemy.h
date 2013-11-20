#ifndef ENEMY_H
#define ENEMY_H

#include "Headers.h"
#include "KinematicEntity.h"

class Enemy : public KinematicEntity
{
	typedef KinematicEntity Base;

public:
	float moveSpeed;

	SDL_Renderer* enemyRenderer;

	Enemy();

	void Update(float deltaTime);
	void Draw();

};
#endif