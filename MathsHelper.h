#ifndef MATHS_HELPER_H
#define MATHS_HELPER_H

#include "Vector2D.h"

class MathsHelper
{
	public:
		static Vector2D CatmullRom(Vector2D p0, Vector2D p1, Vector2D p2, Vector2D p3, float t);
		static Vector2D Rotate(Vector2D vect, float radians);
};

#endif
