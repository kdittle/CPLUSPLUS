#ifndef KINEMATICENTITY_H
#define KINEMATICENTITY_H

#include "Headers.h"
#include "GameEntity.h"
#include "Vector2f.h"

class KinematicEntity : public GameEntity
{
public:
	KinematicEntity();

	Vector2f<float> Velocity;

	void Update(float deltaTime);

	void ApplyForce(const Vector2f<float>& force);

	float Speed;


private:
	typedef GameEntity Base;

	Vector2f<float> mForces;

};

#endif