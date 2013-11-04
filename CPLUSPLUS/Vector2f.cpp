#include "Vector2f.h"
#include <cmath>

Vector2f::Vector2f()
{
	x = 0;
	y = 0;
}

Vector2f::~Vector2f()
{

}

Vector2f::Vector2f(float x_, float y_)
{
	x = x_;
	y = y_;
}

void Vector2f::add(Vector2f v)
{
	x = x + v.x;
	y = y + v.y;
}

void Vector2f::subtract(Vector2f v)
{
	x = x - v.x;
	y = y - v.y;
}

void Vector2f::negate()
{
	x = x * -1;
	y = y * -1;
}

void Vector2f::negate_x()
{
	x = x * -1;
}

void Vector2f::negate_y()
{
	y = y * -1;
}

void Vector2f::divide(float n)
{
	x = x / n;
	y = y / n;
}

float Vector2f::mag()
{
	return std::sqrt(x*x + y*y);
}

void Vector2f::normalize()
{
	float m = mag();

	if(m != 0)
	{
		divide(m);
	}
}
