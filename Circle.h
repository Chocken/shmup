#ifndef CIRCLE_H
#define CIRCLE_H

#include "Vector2D.h"

class Circle
{
	public:
		Circle(Vector2D Center, int R);
		Vector2D center;
		int r;
};

#endif
