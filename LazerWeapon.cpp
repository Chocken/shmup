#include "LazerWeapon.h"

LazerWeapon::LazerWeapon()
{
}

LazerWeapon::LazerWeapon(SDL_Surface* sprite, GameObjectSpec spec,boost::ptr_list<Projectile>& ProjectileDest)
{
	projectileFactory = ProjectileFactory(sprite, spec);
	projectileDest = &ProjectileDest;
	damage = 50;
	fireRate = 200;
	firing = false;
	speed = 800;
}

void LazerWeapon::Fire(Vector2D location, Vector2D target)
{
	location.y -= 20;
	StraightProjectile* projectile = projectileFactory.CreateStraightProjectile(location, target, speed, damage);
	projectile->destroyOnCollision = false;
	projectileDest->push_back(projectile);	
}


void LazerWeapon::Update(Vector2D location,Vector2D target)
{
	if(firing)
	{
		if(shotTimer.get_ticks() >= fireRate)
		{								
			Fire(location, target);
			shotTimer.start();
		}
	}
}
