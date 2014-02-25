#ifndef I_WEAPON_H
#define I_WEAPON_H

#include "Vector2D.h"
#include "Timer.h"
#include "Projectile.h"
#include "ProjectileFactory.h"
#include <boost/ptr_container/ptr_list.hpp>

class IWeapon
{
	public:
		virtual void Fire(Vector2D location,Vector2D target) = 0;
		virtual void Update(Vector2D location, Vector2D direction) = 0;
		bool firing;
		Timer shotTimer;
		int fireRate;
		int damage;

	protected:
		ProjectileFactory projectileFactory;
		boost::ptr_list<Projectile>* projectileDest;
		int speed;
};

#endif

