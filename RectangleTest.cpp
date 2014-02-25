#include "Rectangle.h"
#include <iostream>

int main(int argc, char*argv[])
{

	Rectangle* rectangle;
	try
	{
		Rectangle r1 = Rectangle(Vector2D(1,1),Vector2D(2,1),Vector2D(1,2),Vector2D(2,2));
		rectangle = &r1;
	}
	catch (const char* msg) {
     		std::cerr << msg << std::endl;
   	}

	Vector2D v1 = Vector2D(1,1);
	Vector2D v2 = Vector2D(1,1);

	//Rectangle r2 = *rectangle;

	int* p1;
	int p2;
	p1 = &p2;
	*p1 = 10;

	std::cout<< rectangle->width << std::endl;
	
	
	return 0;
}
