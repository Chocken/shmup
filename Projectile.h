#ifndef PROJECTILE_H
#define PROJECTILE_H

#include "DrawableObject.h"
#include "Vector2D.h"
#include "Enemy.h"

class Projectile : public GamePlayObject
{
	public:		
		virtual void OnCollision(Enemy *enemy) = 0;	
		int damage;	
		bool destroyOnCollision;
	protected:
		Vector2D direction;
		int velocity;
		
};

#endif
