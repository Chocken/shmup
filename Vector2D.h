#ifndef _VECTOR2D_H
#define _VECTOR2D_H

class Vector2D
{
	public:
		float x, y;
		Vector2D();		
		Vector2D(float X, float Y);
		Vector2D& Set(float X, float Y);
		Vector2D& operator += (const Vector2D& v);
		Vector2D& operator -= (const Vector2D& v);
		float operator *(const Vector2D& v) const;

		Vector2D& operator *= (float t);
		Vector2D& operator /= (float t);
		Vector2D operator +(const Vector2D& v)const;
		Vector2D operator -(const Vector2D& v)const;
		
		static Vector2D Normalize(Vector2D vect);

		static float Distance(Vector2D v1, Vector2D v2);
		static float Magnitude(Vector2D vect);		
};

#endif
