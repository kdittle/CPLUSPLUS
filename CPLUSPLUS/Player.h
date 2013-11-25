#ifndef PLAYER_H
#define PLAYER_H

#include "Headers.h"
#include "KinematicEntity.h"
#include "Spell.h"

class Player : public KinematicEntity
{
	float mMoveSpeed;

	typedef KinematicEntity Base;

public:
	static const int WALKING_FRAMES = 4;
	SDL_Rect SpriteClips[WALKING_FRAMES];
	Spell fireShield;

	SDL_Renderer* pRenderer;

	Player();
	
	void SetPlayerRenderer(SDL_Renderer* renderer);
	void SetSpriteClips();
	void Update(float deltaTime);
	void Draw();
	void LoadSpells();

	int frame;
	bool isPlaying;

	bool left, right, up, down, cast;

private:
	float playWidth;
	float playHeight;

};


#endif