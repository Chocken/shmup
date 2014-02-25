#ifndef I_COLLIDABLE
#define I_COLLIDABLE

#include "CollisionType.h"

class ICollidable
{
	public:
		virtual CollisionType GetCollisionType() = 0
};
#endif 
