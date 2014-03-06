/*

Custom Vector2f class for movement vectors

*/

#ifndef VECTOR2F_H
#define VECTOR2F_H

//Vector2f class is generic so it doesn't have to just be floats.
template <class TYPE>
class Vector2f
{
public:
	//x and y for vector
	TYPE _x, _y;

	//Constructors
	Vector2f<TYPE>();
	Vector2f<TYPE>(TYPE x, TYPE y);
	~Vector2f<TYPE>();

	//Operator overloadings
	//Shouldn't be here, but this is the only way they work
	friend Vector2f<TYPE> operator+(const Vector2f<TYPE>& v1, const Vector2f<TYPE>& v2)
	{
		return Vector2f(v1._x + v2._x, v1._y + v2._y);
	}

	friend Vector2f<TYPE> operator-(const Vector2f<TYPE>& v1, const Vector2f<TYPE>& v2)
	{
		return Vector2f(v1._x - v2._x, v1._y - v2._y);
	}

	friend Vector2f<TYPE> operator/(const Vector2f<TYPE>& v1, TYPE& num)
	{
		return Vector2f(v1._x / num, v1._y / num);
	}

	void negate();		//Negate x and y values of a vector
	void negate_x();	//Negate only the x value
	void negate_y();	//Negate only the y value
	float magnitude();	//determine magnitude
	void normalize();	//Normalize the vectorS

};

//Default constructor
template <class TYPE>
Vector2f<TYPE>::Vector2f()
{
	_x = 0;
	_y = 0;
}

//Deconstructor
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

//Negate both x and y value
template <class TYPE>
void Vector2f<TYPE>::negate()
{
	_x = _x * -1;
	_y = _y * -1;
}

//Negate just the x value
template <class TYPE>
void Vector2f<TYPE>::negate_x()
{
	_x = _x * -1;
}

//Negate y value
template <class TYPE>
void Vector2f<TYPE>::negate_y()
{
	_y = _y * -1;
}

//determine magnitude
template <class TYPE>
float Vector2f<TYPE>::magnitude()
{
	return std::sqrt(_x*_x + _y*_y);
}

//Normalize the vector
template <class TYPE>
void Vector2f<TYPE>::normalize()
{
	float m = magnitude();

	if (m != 0)
	{
		_x = _x / m;
		_y = _y / m;
	}
}

#endif