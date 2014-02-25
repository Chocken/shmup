#ifndef _IBOUNDING_SHAPE_H
#define _IBOUNDING_SHAPE_H

class IBoundingShape
{
	public:
		virtual bool Collided(BoundingBox otherBox) = 0; 
};
#endif
