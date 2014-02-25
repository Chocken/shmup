#ifndef BOUNDING_BOX_H
#define BOUNDING_BOX_H

#include "Vector2D.h"

class BoundingBox : IBoundingShape
{
	private:
		Vector2D topLeft;
		Vector2D topRight;
		Vector2D bottomLeft;
		Vector2D bottomRight;

	public:
		bool Collided(BoundingBox otherBox);
};
#endif
