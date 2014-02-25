#ifndef STRAIGHT_WEAPON_H
#define STRAIGHT_WEAPON_H

#include "StraightProjectile.h"
#include "ProjectileFactory.h"
#include "GameObjectSpec.h"
#include "IWeapon.h"
#include "Timer.h"

class StraightWeapon : public IWeapon
{
	public:
		StraightWeapon();
		StraightWeapon(SDL_Surface* sprite,GameObjectSpec spec,boost::ptr_list<Projectile>& ProjectileDest);		
		void Fire(Vector2D location, Vector2D direction);
		void Update(Vector2D location, Vector2D direction);
		int fireRate;
		int damage;
			
		
	private:
		int burstShots;
		int shotCount;
		int longFireRate;
		int shortFireRate;			
};

#endif
