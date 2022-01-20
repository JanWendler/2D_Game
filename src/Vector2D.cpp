//
// Created by Jan on 20/01/2022.
//

#include "Vector2D.h"
Vector2D::Vector2D()
	: x(0), y(0)
{
}
Vector2D::Vector2D(float x, float y)
	: x(x), y(y)
{
}
Vector2D& Vector2D::add(const Vector2D& vec)
{
	this->x += vec.x;
	this->y += vec.y;
	return *this;
}
Vector2D& Vector2D::operator+=(const Vector2D& vec)
{
	this->x += vec.x;
	this->y += vec.y;
	return *this;
}
Vector2D& Vector2D::operator-=(const Vector2D& vec)
{
	this->x -= vec.x;
	this->y -= vec.y;
	return *this;
}
Vector2D& Vector2D::operator*=(const Vector2D& vec)
{
	this->x *= vec.x;
	this->y *= vec.y;
	return *this;
}
Vector2D& Vector2D::operator/=(const Vector2D& vec)
{
	this->x /= vec.x;
	this->y /= vec.y;
	return *this;
	;
}
Vector2D& operator+(Vector2D& v1, const Vector2D& v2)
{
	return v1 += v2;
}
Vector2D& operator-(Vector2D& v1, const Vector2D& v2)
{
	return v1 -= v2;
}
Vector2D& operator*(Vector2D& v1, const Vector2D& v2)
{
	return v1 *= v2;
}
Vector2D& operator/(Vector2D& v1, const Vector2D& v2)
{
	return v1 /= v2;
}
std::ostream& operator<<(std::ostream& ostream, const Vector2D& vec)
{
	ostream << "(" << vec.x << "," << vec.y << ")";
	return ostream;
}
