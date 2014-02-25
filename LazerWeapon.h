#ifndef LAZER_WEAPON_H
#define LAZER_WEAPON_H

#include "StraightProjectile.h"
#include "ProjectileFactory.h"
#include "GameObjectSpec.h"
#include "IWeapon.h"
#include "Timer.h"

class LazerWeapon : public IWeapon
{
	public:
		LazerWeapon();
		LazerWeapon(SDL_Surface* sprite,GameObjectSpec spec,boost::ptr_list<Projectile>& ProjectileDest);		
		void Fire(Vector2D location, Vector2D direction);
		void Update(Vector2D location, Vector2D direction);			
};

#endif
