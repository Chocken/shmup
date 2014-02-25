#ifndef ENEMY_H
#define ENEMY_H

#include "GamePlayObject.h"
#include "ExplosionFactory.h"
#include "Vector2D.h"
#include "Timer.h"

class Enemy : public GamePlayObject
{
	public:			
		virtual ~Enemy() = 0;				
		virtual void TakeDamage(int damage) = 0;
		virtual void OnProjectileHit() = 0;
		
};
#endif
