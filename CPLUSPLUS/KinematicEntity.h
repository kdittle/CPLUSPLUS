/*

KinematicEntity is for movement, it's base is GameEntity

*/

#ifndef KINEMATICENTITY_H
#define KINEMATICENTITY_H

#include "Headers.h"
#include "GameEntity.h"
#include "Vector2f.h"

class KinematicEntity : public GameEntity
{
public:
	//Constructor
	KinematicEntity();

	//Velocity Vector
	Vector2f<float> Velocity;

	//Simple update
	void Update(float deltaTime);

	//Add force to vector
	void ApplyForce(const Vector2f<float>& force);

	float Speed;


private:
	typedef GameEntity Base;

	Vector2f<float> mForces;

};

#endif