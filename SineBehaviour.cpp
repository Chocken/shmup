#include "SineBehaviour.h"
#include <math.h>
#include <iostream>
SineBehaviour::SineBehaviour( BasicEnemy* basicEnemy,float Amplitude, float Frequency, float Speed)
{
	amplitude = Amplitude;
	frequency = Frequency;
	speed = Speed;
	enemy = basicEnemy;
}

void SineBehaviour::Update(Uint32 deltaTicks)
{
	
	numTicks += frequency * (deltaTicks/1000.f);
	enemy->x += amplitude * sin(numTicks * 0.5 * 3.1415f);
	enemy->y += speed * (deltaTicks/1000.f);	

}
