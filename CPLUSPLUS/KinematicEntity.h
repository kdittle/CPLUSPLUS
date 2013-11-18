#ifndef KINEMATICENTITY_H
#define KINEMATICENTITY_H

#include "Headers.h"
#include "GameEntity.h"
#include "Vector2f.h"

class KinematicEntity : public GameEntity
{
public:
	KinematicEntity();

	Vector2f Velocity;

	void Update(float deltaTime);

	void ApplyForce(const Vector2f& force);

	float Speed;


private:
	typedef GameEntity Base;

	Vector2f mForces;

};

#endif