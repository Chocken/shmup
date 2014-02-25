#ifndef COLLISIONMANAGER_H
#define COLLISIONMANAGER_H

#include "Rectangle.h"
#include "Circle.h"
#include "GamePlayObject.h"

class CollisionManager
{
	public:
		bool DetectCollision(GamePlayObject* obj1, GamePlayObject* obj2);			
		//bool DetectCollision(Rectangle rectA, Rectangle rectB);
		//bool DetectCollision(Circle circleA, Circle circleB);
		bool DetectCollision(Circle c1, Rectangle r1);
};

#endif
