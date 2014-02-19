#ifndef VECTOR2F_H
#define VECTOR2F_H


template <class TYPE>
class Vector2f
{
public:
	TYPE _x, _y;

	Vector2f<TYPE>();
	Vector2f<TYPE>(TYPE x, TYPE y);
	~Vector2f<TYPE>();

	friend Vector2f<TYPE> operator+(const Vector2f<TYPE>& v1, const Vector2f<TYPE>& v2);
	friend Vector2f<TYPE> operator-(const Vector2f<TYPE>& v1, const Vector2f<TYPE>& v2);
	friend Vector2f<TYPE> operator/(const Vector2f<TYPE>& v1, TYPE& num);
	void negate();
	void negate_x();
	void negate_y();
	float magnitutde();
	void normalize();

};

template <class TYPE>
Vector2f<TYPE>::Vector2f()
{
	_x = 0;
	_y = 0;
}

template <class TYPE>
Vector2f<TYPE>::~Vector2f()
{

}

template <class TYPE>
Vector2f<TYPE>::Vector2f(TYPE x, TYPE y)
{
	_x = x;
	_y = y;
}

template <class TYPE>
Vector2f<TYPE> operator+(const Vector2f<TYPE>& v1, const Vector2f<TYPE>& v2)
{
	return Vector2f(v1._x + v2._x, v1._y + v2._y);
}

template <class TYPE>
Vector2f<TYPE> operator-(const Vector2f<TYPE>& v1, const Vector2f<TYPE>& v2)
{
	return Vector2f(v1._x - v2._x, v1._y - v2._y);
}

template <class TYPE>
Vector2f<TYPE> operator/(const Vector2f<TYPE>& v1, TYPE& num)
{
	return Vector2f(v1._x / num, v1._y / num);
}

template <class TYPE>
void Vector2f<TYPE>::negate()
{
	_x = _x * -1;
	_y = _y * -1;
}

template <class TYPE>
void Vector2f<TYPE>::negate_x()
{
	_x = _x * -1;
}

template <class TYPE>
void Vector2f<TYPE>::negate_y()
{
	_y = _y * -1;
}

template <class TYPE>
float Vector2f<TYPE>::magnitutde()
{
	return std::sqrt(_x*_x + _y*_y);
}

template <class TYPE>
void Vector2f<TYPE>::normalize()
{
	float m = magnitutde();

	if (m != 0)
	{
		_x = _x / m;
		_y = _y / m;
	}
}

#endif