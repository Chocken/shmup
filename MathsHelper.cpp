#include "MathsHelper.h"
#include "Vector2D.h"
#include <math.h>

Vector2D MathsHelper::CatmullRom(Vector2D p0, Vector2D p1, Vector2D p2, Vector2D p3, float t)
{
	float t2 = t * t;
    	float t3 = t2 * t;

	Vector2D ret;

    	ret.x = 0.5f * ((2.0f * p1.x) + 
	(-p0.x + p2.x) * t +
    	(2.0f * p0.x - 5.0f * p1.x + 4 * p2.x - p3.x) * t2 +
    	(-p0.x + 3.0f * p1.x - 3.0f * p2.x + p3.x) * t3);
	
	ret.y = 0.5f * ((2.0f * p1.y) +
    	(-p0.y + p2.y) * t +
    	(2.0f * p0.y - 5.0f * p1.y + 4 * p2.y - p3.y) * t2 +
    	(-p0.y + 3.0f * p1.y - 3.0f * p2.y + p3.y) * t3);

	return ret;
}

Vector2D MathsHelper::Rotate(Vector2D vect, float radians)
{
	return Vector2D((vect.x*cos(radians)) - (vect.y*sin(radians)), (vect.x*sin(radians)) + (vect.y * cos(radians)));
}
