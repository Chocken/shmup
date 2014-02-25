#include "SpreadWeapon2.h"
#include "MathsHelper.h"

SpreadWeapon2::SpreadWeapon2(SDL_Surface* sprite, GameObjectSpec spec,boost::ptr_list<Projectile>& ProjectileDest) : SpreadWeapon(sprite, spec, ProjectileDest)
{
}

void SpreadWeapon2::Fire(Vector2D location, Vector2D target)
{	
	StraightProjectile* projectile = projectileFactory.CreateStraightProjectile(location, target, speed, damage);
	StraightProjectile* projectileLeft1 = projectileFactory.CreateStraightProjectile(location, MathsHelper::Rotate(target,0.1), speed, damage);
	StraightProjectile* projectileRight1 = projectileFactory.CreateStraightProjectile(location, MathsHelper::Rotate(target,-0.1), speed, damage);
	StraightProjectile* projectileLeft2 = projectileFactory.CreateStraightProjectile(location, MathsHelper::Rotate(target,0.2), speed, damage);
	StraightProjectile* projectileRight2 = projectileFactory.CreateStraightProjectile(location, MathsHelper::Rotate(target,-0.2), speed, damage);
	projectileDest->push_back(projectile);
	projectileDest->push_back(projectileLeft1);
	projectileDest->push_back(projectileRight1);
	projectileDest->push_back(projectileLeft2);
	projectileDest->push_back(projectileRight2);	
}
