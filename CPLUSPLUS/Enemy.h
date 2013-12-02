#ifndef ENEMY_H
#define ENEMY_H

#include "Headers.h"
#include "KinematicEntity.h"
#include "Player.h"

class Enemy : public KinematicEntity
{
	typedef KinematicEntity Base;

public:
	float moveSpeed;
	bool chasing, caught;

	int frame;
	bool left, right, up, down;
	static const int WALKING_FRAMES = 4;
	SDL_Rect SpriteClips[WALKING_FRAMES];

	SDL_Renderer* eRenderer;
	Player rPlayer;
	Vector2f playerLocation;

	Enemy();

	void SetEnemyRenderer(SDL_Renderer* renderer);
	void PlayerReference(Player& player);
	void SetSpriteClips();
	void Update(float deltaTime);
	void Draw();

};
#endif