#include "KinematicEntity.h"

KinematicEntity::KinematicEntity()
{
	mForces = Vector2f(0.0f, 0.0f);

	Velocity = Vector2f(0.0f, 0.0f);

	Speed = 0.0f;
}

void KinematicEntity::Update(float deltaTime)
{
	Base::Update(deltaTime);

	if(mForces.x == 0.0f)
	{
		float preVelocity = Velocity.x;
		Velocity.x -= deltaTime * Velocity.x;

		if(preVelocity != Velocity.x)
		{
			Velocity.x = 0.0f;
		}
	}
	else
	{
		Velocity.x += mForces.x * deltaTime;

		if(mForces.x != Velocity.x)
		{
			Velocity.x += deltaTime * mForces.x;

			if(mForces.x == Velocity.x)
			{
				Velocity.x = 0.0f;
			}
		}
	}

	if (mForces.y == 0.0f)
	{
		float preVelocity = Velocity.y;
		Velocity.y -= deltaTime * Velocity.y;

		if(preVelocity != Velocity.y)
		{
			Velocity.y = 0.0f;
		}
	}
	else
	{
		Velocity.y += mForces.y * deltaTime;

		if(mForces.y != Velocity.y)
		{
			Velocity.y += deltaTime * mForces.y;

			if(mForces.y == Velocity.y)
			{
				Velocity.y = 0.0f;
			}
		}
	}

	Base::shiftBoundingBox();

}

void KinematicEntity::ApplyForce(const Vector2f& force)
{
	mForces.add(force);
}