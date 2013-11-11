#ifndef PLAYER_H
#define PLAYER_H

#include "Headers.h"
#include "KinematicEntity.h"

class Player : public KinematicEntity
{
	float mMoveSpeed;

	typedef KinematicEntity Base;

public:
	Player();

	void Update(float deltaTime);

};


#endif