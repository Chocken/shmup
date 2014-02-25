#ifndef SPREAD2_WEAPON_H
#define SPREAD2_WEAPON_H

#include "SpreadWeapon.h"
#include "ProjectileFactory.h"
#include "GameObjectSpec.h"

class SpreadWeapon2 : public SpreadWeapon
{
	public:
		SpreadWeapon2(SDL_Surface* sprite, GameObjectSpec spec,boost::ptr_list<Projectile>& ProjectileDest);	
		void Fire(Vector2D location, Vector2D direction);		
};

#endif
