#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Vector2D.h"

class Rectangle
{
	public:
		Rectangle();
		Rectangle(Vector2D TopLeft,Vector2D TopRight,Vector2D BottomLeft,Vector2D BottomRight);
		Rectangle(Vector2D TopLeft, int Width, int Height);		
		void SetLocationFromCenter(Vector2D Center);
		void SetLocationFromTopLeft(Vector2D TopRight);
		void SetLocationFromCenter(Vector2D Center, int Height, int Width);

		int width;
		int height;	
		Vector2D topLeft;
		Vector2D topRight;
		Vector2D bottomLeft;
		Vector2D bottomRight;
		Vector2D center;	
};

#endif
