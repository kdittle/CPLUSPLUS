/*

Spell is the base class for all spells

*/

#ifndef SPELL_H
#define SPELL_H

#include "Headers.h"
#include "GameEntity.h"
#include "KinematicEntity.h"
#include "CollisionDetection.h"

class Spell : public KinematicEntity
{
	typedef KinematicEntity Base;

public:
	float Speed;							//Speed for projectile spells
	CollisionDetection collisionHandler;	//Collision handler for spells

	Spell();

	void Update(float deltaTime);								//Update
	void SetBoundingBox(Vector2f<float> position);				//Set boxes for collision
	bool checkCollision(SDL_Rect player, SDL_Rect enemy);		//Check collision

private:

};

#endif