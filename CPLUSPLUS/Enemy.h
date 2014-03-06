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
	bool chasing, caught; //Determines the state of the enemy

	int frame;								//frame is the frame from the sprite sheet
	bool left, right, up, down;				//determines what direction the enemy is going
	static const int WALKING_FRAMES = 4;	//Number of frames on the sprite sheet
	SDL_Rect SpriteClips[WALKING_FRAMES];	//Clips

	//Constructor
	Enemy();

	void SetSpriteClips();			//Set up sprite clips for animation
	void Update(float deltaTime);	//Update Enemy
	void Draw();					//Render
	void SetBoundingBox();			//Set the bounding boxes for collision
	float GetHealth();				//Health isn't used yet, eventually though.

private:
	float m_health;

};
#endif