#include "SpreadWeapon.h"
#include "MathsHelper.h"

SpreadWeapon::SpreadWeapon()
{
}

SpreadWeapon::SpreadWeapon(SDL_Surface* sprite, GameObjectSpec spec,boost::ptr_list<Projectile>& ProjectileDest)
{
	projectileFactory = ProjectileFactory(sprite, spec);
	projectileDest = &ProjectileDest;
	damage = 50;
	fireRate = 300;
	firing = false;
	speed = 800;
}

void SpreadWeapon::Fire(Vector2D location, Vector2D target)
{	
	StraightProjectile* projectile = projectileFactory.CreateStraightProjectile(location, target, speed, damage);
	StraightProjectile* projectileLeft = projectileFactory.CreateStraightProjectile(location, MathsHelper::Rotate(target,0.15), speed, damage);
	StraightProjectile* projectileRight = projectileFactory.CreateStraightProjectile(location, MathsHelper::Rotate(target,-0.15), speed, damage);
	projectileDest->push_back(projectile);
	projectileDest->push_back(projectileLeft);
	projectileDest->push_back(projectileRight);	
}


void SpreadWeapon::Update(Vector2D location,Vector2D target)
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
