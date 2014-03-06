/*

Spell is the base class for all spells

*/

#ifndef SPELL_H
#define SPELL_H

#include "Headers.h"
#include "GameEntity.h"
#include "CollisionDetection.h"

class Spell : public GameEntity
{
	typedef GameEntity Base;

public:
	float Speed;							//Speed for projectile spells
	static const int FIRE_FRAMES = 2;		//Frame for spells
	SDL_Rect SpriteClips[FIRE_FRAMES];		//Clips for animation
	CollisionDetection collisionHandler;	//Collision handler for spells

	Spell();

	void SetSpriteClips();										//Sprite clips for animation
	void Update(float deltaTime, Vector2f<float> position);		//Update
	void Draw(Vector2f<float> position);						//Render
	void SetBoundingBox(Vector2f<float> position);				//Set boxes for collision
	bool checkCollision(SDL_Rect player, SDL_Rect enemy);		//Check collision

	int frame;

private:

};

#endif