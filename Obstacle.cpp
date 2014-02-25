#include "Obstacle.h"
#include <iostream>

Obstacle::Obstacle(float X)
{	
	x = X;
	y = 100;
	collisionType = CIRC;	
}

void Obstacle::Update(Uint32 deltaTicks)
{
	//y += 200 * ( deltaTicks / 1000.f );
	printf("updating obstacle\n");
	//std::cout << life << std::endl;
	life -= 1;
	if(life <= 0)
	{
		printf("isActive set to false\n");
		isActive = false;
	}
}

void Obstacle::Draw(SDL_Surface* surface)
{	
	if (Sprite::Draw(surface, sprite, x, y) == false)
	{
		printf("ship not drawn successfully\n");
	}	
};

void Obstacle::TakeDamage(int damage)
{
	life -= damage;
}
