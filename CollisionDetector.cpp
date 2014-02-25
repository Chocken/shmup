#include "CollisionDetector.h"
#include "Rectangle.h"
#include "Circle.h"
#include "Vector2D.h"
#include "Sprite.h"
#include <iostream>

bool CollisionDetector::DetectCollision(GamePlayObject* obj1, GamePlayObject* obj2)
{
	Vector2D obj1Center = obj1->CollisionCenter();
	Vector2D obj2Center = obj2->CollisionCenter();

	if (obj1->collisionType == CIRC && obj2->collisionType == CIRC)
	{		
		Circle circle1 = Circle(obj1Center, obj1->collisionWidth/2);
		Circle circle2 = Circle(obj2Center, obj2->collisionWidth/2);
		return DetectCollision(circle1, circle2);
	}

	if (obj1->collisionType == RECT && obj2->collisionType == RECT)
	{
		Rectangle rect1;	
		Rectangle rect2;
		rect1.SetLocationFromCenter(obj1Center, obj1->collisionHeight,obj1->collisionWidth);
		rect2.SetLocationFromCenter(obj2Center, obj2->collisionHeight,obj2->collisionWidth);
		return DetectCollision(rect1, rect2);
	}
	
	if(obj1->collisionType == RECT && obj2->collisionType == CIRC)
	{
		Circle circle = Circle(obj2Center, obj2->collisionWidth/2);
		Rectangle rect;
		rect.SetLocationFromCenter(obj1Center, obj1->collisionHeight,obj1->collisionWidth);		
		return DetectCollision(circle,rect);
	}
	
	if(obj1->collisionType == CIRC && obj2->collisionType == RECT)
	{
		
		Circle circle = Circle(obj1Center, obj1->collisionWidth/2);
		Rectangle rect;
		rect.SetLocationFromCenter(obj2Center, obj2->collisionHeight,obj2->collisionWidth);		
		return DetectCollision(circle,rect);
	}
	
	return false;
}

bool CollisionDetector::DetectCollision(Rectangle rectA, Rectangle rectB)
{
	if(rectA.bottomLeft.y <= rectB.topLeft.y)
	{
		return false;
	}

	if(rectA.topLeft.y >= rectB.bottomLeft.y)
	{
		return false;
	}
	
	if(rectA.topRight.x <= rectB.topLeft.x)
	{
		return false;
	}
	
	if(rectA.topLeft.x >= rectB.topRight.x)
	{
		return false;
	}

	return true;
}

bool CollisionDetector::DetectCollision(Circle circleA, Circle circleB)
{
	if(Vector2D::Distance(circleA.center,circleB.center) <= (circleA.r + circleB.r))
	{
		return true;
	}

	return false;
}

bool CollisionDetector::DetectCollision(Circle circle, Rectangle rect)
{
	int cX, cY; 

	if(circle.center.x < rect.topLeft.x)
	{
		cX = rect.bottomLeft.x;		
	}
	else if (circle.center.x > rect.topRight.x)
	{
		
		cX = rect.bottomRight.x;
	}
	else
	{
		cX = circle.center.x;
	}

	if(circle.center.y < rect.topLeft.y)
	{		
		cY = rect.topLeft.y; 		
	}
	else if(circle.center.y > rect.bottomLeft.y)
	{
		cY = rect.bottomLeft.y;			
	}
	else
	{		
		cY = circle.center.y;
	}	
	
	if(Vector2D::Distance(circle.center, Vector2D(cX,cY)) < circle.r)
	{
		return true;
	}
	
	return false;
}


