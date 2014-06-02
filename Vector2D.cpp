#include "Vector2D.h"
#include <math.h>
#include <cmath>

Vector2D::Vector2D(float X, float Y)
{
	x = X;
	y = Y;
}

Vector2D::Vector2D() {x=0;y=0;}

Vector2D& Vector2D::Set(float X, float Y)
{
        x = X;
        y = Y;
        return (*this);
}

Vector2D& Vector2D::operator +=(const Vector2D& v)
{
        x += v.x;
        y += v.y;
        return (*this);
}

Vector2D& Vector2D::operator -=(const Vector2D& v)
{
        x -= v.x;
        y -= v.y;
        return (*this);
}

Vector2D& Vector2D::operator *=(float t)
{
        x *= t;
        y *= t;
        return (*this);
}

Vector2D& Vector2D::operator /=(float t)
{
        float f = 1.0F / t;
        x *= f;
        y *= f;
        return (*this);
}

Vector2D Vector2D::operator +(const Vector2D& v)const
{
	return Vector2D(*this) += v;        
}
        
Vector2D Vector2D::operator -(const Vector2D& v)const
{
        return Vector2D(*this) -= v; 
}

Vector2D Vector2D::Normalize(Vector2D vect)
{
	float mag = Magnitude(vect);
	return Vector2D((vect.x/mag),(vect.y/mag));
}

float Vector2D::Distance(Vector2D v1, Vector2D v2)
{
	return sqrt( pow( v2.x - v1.x, 2 ) + pow( v2.y - v1.y, 2 ) );
}

float Vector2D::Magnitude(Vector2D vect)
{
	return sqrt((vect.x*vect.x) + (vect.y * vect.y));
}

