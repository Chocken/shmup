#ifndef SPREAD_WEAPON_H
#define SPREAD_WEAPON_H

#include "StraightProjectile.h"
#include "ProjectileFactory.h"
#include "GameObjectSpec.h"
#include "IWeapon.h"
#include "Timer.h"

class SpreadWeapon : public IWeapon
{
	public:
		SpreadWeapon();
		SpreadWeapon(SDL_Surface* sprite, GameObjectSpec spec,boost::ptr_list<Projectile>& ProjectileDest);		
		virtual void Fire(Vector2D location, Vector2D direction);
		void Update(Vector2D location, Vector2D direction);			
};

#endif

