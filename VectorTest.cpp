#include <iostream>
#include "Vector2D.h"
int main( int argc, char* args[] )
{
	Vector2D v1(2,1);
	Vector2D v2(3,1);
	Vector2D v3 = v1 * v2;
	std::cout << v3.x << " " << v3.y << std::endl;
		
	return 0;
}
