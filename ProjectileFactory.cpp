#include "ProjectileFactory.h"

ProjectileFactory::ProjectileFactory()
{
}

ProjectileFactory::ProjectileFactory(SDL_Surface* Sprite, GameObjectSpec spec)
{
	sprite = Sprite;
	collisionType = spec.collisionType;
	width = spec.width;
	height = spec.height;
	collisionWidth = spec.collisionWidth;
	collisionHeight = spec.collisionHeight;
	collisionOffset = spec.collisionOffset;
}

StraightProjectile* ProjectileFactory::CreateStraightProjectile(Vector2D location, Vector2D direction, float speed, int damage)
{
	StraightProjectile* projectile = new StraightProjectile(location, direction, speed, damage);
	projectile->sprite = sprite;
	projectile->CollisionOffset = collisionOffset;
	projectile->height = height;
	projectile->width = width;
	projectile->collisionHeight = collisionHeight;
	projectile->collisionWidth = collisionWidth;
	projectile->x -= projectile->Center().x - projectile->x;
	projectile->y -= projectile->Center().y - projectile->y;
	
	projectile->collisionType = collisionType;
	projectile->SetIsActive(true);	
	return projectile;
}
