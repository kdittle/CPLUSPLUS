#include "KinematicEntity.h"

KinematicEntity::KinematicEntity()
{
	mForces = Vector2f<float>(0.0f, 0.0f);

	Velocity = Vector2f<float>(0.0f, 0.0f);

	Speed = 0.0f;
}

void KinematicEntity::Update(float deltaTime)
{
	Base::Update(deltaTime);

	if(mForces._x == 0.0f)
	{
		float preVelocity = Velocity._x;
		Velocity._x -= deltaTime * Velocity._x;

		if(preVelocity != Velocity._x)
		{
			Velocity._x = 0.0f;
		}
	}
	else
	{
		Velocity._x += mForces._x * deltaTime;

		if(mForces._x != Velocity._x)
		{
			Velocity._x += deltaTime * mForces._x;

			if(mForces._x == Velocity._x)
			{
				Velocity._x = 0.0f;
			}
		}
	}

	if (mForces._y == 0.0f)
	{
		float preVelocity = Velocity._y;
		Velocity._y -= deltaTime * Velocity._y;

		if(preVelocity != Velocity._y)
		{
			Velocity._y = 0.0f;
		}
	}
	else
	{
		Velocity._y += mForces._y * deltaTime;

		if(mForces._y != Velocity._y)
		{
			Velocity._y += deltaTime * mForces._y;

			if(mForces._y == Velocity._y)
			{
				Velocity._y = 0.0f;
			}
		}
	}

	Base::shiftBoundingBox();

}

void KinematicEntity::ApplyForce(const Vector2f<float>& force)
{
	mForces = mForces + force;
}