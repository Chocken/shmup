#ifndef PROJECTILE_FACTORY_H
#define PROJECTILE_FACTORY_H

#include "StraightProjectile.h"
#include "SDL/SDL.h"
#include "Vector2D.h"
#include "GameObjectSpec.h"
#include "CollisionType.h"

class ProjectileFactory
{
	public:
		ProjectileFactory();
		ProjectileFactory(SDL_Surface* sprite, GameObjectSpec spec);
		StraightProjectile* CreateStraightProjectile(Vector2D location, Vector2D direction, float speed, int damage);

	private:
		CollisionType collisionType;
		SDL_Surface* sprite;
		float width, height, collisionWidth, collisionHeight;
		Vector2D collisionOffset;
};

#endif
