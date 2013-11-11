#ifndef VECTOR2F_H
#define VECTOR2F_H

class Vector2f
{
public:
	float x, y;

	Vector2f();
	Vector2f(float x_, float y_);
	~Vector2f();

	void add(Vector2f v);
	void subtract(Vector2f v);
	void negate();
	void negate_x();
	void negate_y();
	void divide(float n);
	float magnitutde();
	void normalize();

};

#endif