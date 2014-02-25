#ifndef STRAIGHT_PROJECTILE_H
#define STRAIGHT_PROJECTILE_H

#include "Vector2D.h"
#include "GamePlayObject.h"
#include "SDL/SDL.h"
#include "Projectile.h"
#include "Enemy.h"

class StraightProjectile : public Projectile
{
	public:
		StraightProjectile(Vector2D FiringPoint, Vector2D target, int speed, int weaponDamage);
		void Update(Uint32 deltaTicks);
		void Draw(SDL_Surface* surface);
		virtual void OnCollision(Enemy *enemy);	

};

#endif
