#ifndef PLAYER_H
#define PLAYER_H

#include "Headers.h"
#include "KinematicEntity.h"
#include "Projectile.h"

class Player : public KinematicEntity
{
	float mMoveSpeed;

	typedef KinematicEntity Base;

public:
	static const int WALKING_FRAMES = 4;
	SDL_Rect SpriteClips[WALKING_FRAMES];
	Projectile projectile;
	std::vector<Projectile> projectileList;

	SDL_Renderer* playerRenderer;

	Player();
	
	void SetPlayerRenderer(SDL_Renderer* renderer);
	void SetSpriteClips();
	void Update(float deltaTime);
	void Draw();

	int frame;
	bool isPlaying;

	bool left, right, up, down, cast;

};


#endif