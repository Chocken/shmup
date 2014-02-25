#include "GamePlayObject.h"

Vector2D GamePlayObject::CollisionCenter()
{
	return Vector2D(x + CollisionOffset.x + (collisionWidth/2), y + CollisionOffset.y + (collisionHeight/2));
}


