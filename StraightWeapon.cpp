#include "StraightWeapon.h"
#include "GameObjects.h"

StraightWeapon::StraightWeapon()
{
}

StraightWeapon::StraightWeapon(SDL_Surface* sprite,GameObjectSpec spec,boost::ptr_list<Projectile>& ProjectileDest)
{
	projectileFactory = ProjectileFactory(sprite, spec);
	projectileDest = &ProjectileDest;	
	shortFireRate = 50;
	damage = 10;
	longFireRate = 200;
	burstShots = 3;
	speed = 400;	
	firing = false;	
}

void StraightWeapon::Fire(Vector2D location, Vector2D target)
{
	StraightProjectile* projectile = projectileFactory.CreateStraightProjectile(location, target, speed, damage);	
	projectileDest->push_back(projectile);
	shotCount++;
}

void StraightWeapon::Update(Vector2D location,Vector2D target)
{
	if(firing)
	{
		if(shotTimer.get_ticks() >= fireRate)
		{								
			Fire(location, target);
			shotTimer.start();
		}
		if (shotCount == burstShots && fireRate == shortFireRate)
		{
			fireRate = longFireRate;
		}

		if(shotCount == burstShots+1 && fireRate == longFireRate)
		{
			fireRate = shortFireRate;
			shotCount = 1;
		}

	}
	else
	{
		fireRate = shortFireRate;
		shotCount = 0;
	}	
}
