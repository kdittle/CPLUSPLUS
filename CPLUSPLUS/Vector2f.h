#ifndef VECTOR2F_H
#define VECTOR2F_H


template <class TYPE>
class Vector2f
{
public:
	TYPE _x, _y;

	Vector2f();
	Vector2f(TYPE x, TYPE y);
	~Vector2f();

	friend Vector2f operator+(const Vector2f& v1, const Vector2f& v2);
	friend Vector2f operator-(const Vector2f& v1, const Vector2f& v2);
	friend Vector2f operator/(const Vector2f& v1, TYPE& num);
	void negate();
	void negate_x();
	void negate_y();
	float magnitutde();
	void normalize(Vector2f& v);

};

#endif