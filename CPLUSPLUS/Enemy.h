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

	Player rPlayer;
	Vector2f<float> playerLocation;

	Enemy();

	void SetSpriteClips();
	void Update(float deltaTime);
	void Draw();
	void SetBoundingBox();
	float GetHealth();

private:
	float m_health;

};
#endif