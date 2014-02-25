#ifndef OBSTACLE_H
#define OBSTACLE_H

#include "GamePlayObject.h"
#include "IDamageable.h"
class Obstacle: public GamePlayObject, public IDamageable
{
	public:		
		Obstacle(float X);		
		void Update(Uint32 deltaTicks);
		void Draw(SDL_Surface* surface);
		void TakeDamage(int damage);
		int life;		
		
};
#endif 
