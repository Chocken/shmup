#ifndef COLLISIONDETECTOR_H
#define COLLISIONDETECTOR_H

#include "GamePlayObject.h"
#include "DrawableObject.h"
#include "Rectangle.h"
#include "Circle.h"


class CollisionDetector
{
	public:
		bool DetectCollision(GamePlayObject* obj1, GamePlayObject* obj2);			
		bool DetectCollision(Rectangle rectA, Rectangle rectB);
		bool DetectCollision(Circle circleA, Circle circleB);
		bool DetectCollision(Circle circle, Rectangle rect);			
};

#endif
