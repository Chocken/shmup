#ifndef GAMEPLAY_OBJECT_H
#define GAMEPLAY_OBJECT_H

#include "DrawableObject.h"
#include "IUpdateable.h"
#include "CollisionType.h"
#include "Vector2D.h"

class GamePlayObject: public DrawableObject, public IUpdateable
{
	public:			
		CollisionType collisionType;
		Vector2D CollisionOffset;
		int collisionWidth, collisionHeight;
		Vector2D CollisionCenter();
		
};
#endif
