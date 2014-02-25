#include "Rectangle.h"
#include <iostream>
#include <exception>

Rectangle::Rectangle()
{
}

Rectangle::Rectangle(Vector2D TopLeft,Vector2D TopRight,Vector2D BottomLeft,Vector2D BottomRight)
{
	topLeft = TopLeft;
	topRight = TopRight;
	bottomLeft = BottomLeft;
	bottomRight = BottomRight;
	
	Vector2D vectors[4] = {topLeft,topRight,bottomLeft,bottomRight};

	if(topLeft.x != bottomLeft.x || topLeft.y != topRight.y || topRight.x != bottomRight.x || bottomRight.y != bottomLeft.y)
	{
		throw "Vectors do not create Rectangle";
	}
	else
	{
		for(int i=0; i<4;i++)
		{
			for(int j=0; j<4;j++)
			{
				if(i != j)
				{
					if(vectors[i].x == vectors[j].x && vectors[i].y == vectors[j].y)
					throw "2 Vectors of the same co ordinates";
				}
			}	
		}
	}

	height = bottomLeft.y - topLeft.y;
	width = topRight.x - topLeft.x;

	center = Vector2D(TopLeft.x + width/2, TopLeft.y + height/2);			
}

Rectangle::Rectangle(Vector2D TopLeft, int Width, int Height)
{
	topLeft = TopLeft;	
	topRight.Set(TopLeft.x + Width,TopLeft.y);
	bottomLeft.Set(TopLeft.x, TopLeft.y + Height);
	bottomRight.Set(TopLeft.x + Width, TopLeft.y + Height);
	width = Width;
	height = Height;
	center = Vector2D(TopLeft.x + width/2, TopLeft.y + height/2);
}

void Rectangle::SetLocationFromCenter(Vector2D Center)
{
	topLeft = Vector2D(Center.x - width/2, Center.y - height/2);
	topRight = Vector2D(Center.x + width/2, Center.y - height/2);
	bottomLeft = Vector2D(Center.x - width/2, Center.y + height/2);
	bottomRight = Vector2D(Center.x + width/2, Center.y + height/2);
	height = bottomLeft.y - topLeft.y;
	width = topRight.x - topLeft.x;

	center = Center;
}

void Rectangle::SetLocationFromCenter(Vector2D Center, int Height, int Width)
{
	topLeft = Vector2D(Center.x - Width/2, Center.y - Height/2);
	topRight = Vector2D(Center.x + Width/2, Center.y - Height/2);
	bottomLeft = Vector2D(Center.x - Width/2, Center.y + Height/2);
	bottomRight = Vector2D(Center.x + Width/2, Center.y + Height/2);
	height = Height;
	width = Width;
	center = Center;
}

void Rectangle::SetLocationFromTopLeft(Vector2D TopLeft)
{
	topLeft = TopLeft;
	topRight = Vector2D(TopLeft.x + width, TopLeft.y);
	bottomLeft = Vector2D(TopLeft.x, TopLeft.y + height);
	bottomRight = Vector2D(TopLeft.y + width, TopLeft.y + height);

	center = Vector2D(TopLeft.x + width/2, TopLeft.y + height/2);
}
