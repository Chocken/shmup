#include "SpecFactory.h"
#include "Behaviour.h"

GameObjectSpec SpecFactory::CreateStraightProjectileSpec()
{
	GameObjectSpec projectileSpec;	
	projectileSpec.collisionType = CIRC;
	projectileSpec.width = 4;
	projectileSpec.height = 4;
	projectileSpec.collisionWidth = 4;
	projectileSpec.collisionHeight = 4;
	projectileSpec.collisionOffset = Vector2D(2,2);
	return projectileSpec;
}

GameObjectSpec SpecFactory::CreateSpreadProjectileSpec()
{
	GameObjectSpec projectileSpec;	
	projectileSpec.collisionType = CIRC;
	projectileSpec.width = 4;
	projectileSpec.height = 4;
	projectileSpec.collisionWidth = 4;
	projectileSpec.collisionHeight = 4;
	projectileSpec.collisionOffset = Vector2D(2,2);
	return projectileSpec;
}

GameObjectSpec SpecFactory::CreateLazerProjectileSpec()
{
	GameObjectSpec projectileSpec;	
	projectileSpec.collisionType = RECT;
	projectileSpec.width = 8;
	projectileSpec.height = 65;
	projectileSpec.collisionWidth = 8;
	projectileSpec.collisionHeight = 65;
	projectileSpec.collisionOffset = Vector2D(0,0);
	return projectileSpec;
}

GameObjectSpec SpecFactory::CreateLazer2ProjectileSpec()
{
	GameObjectSpec projectileSpec;
	projectileSpec.collisionType = RECT;
	projectileSpec.width = 12;
	projectileSpec.height = 65;
	projectileSpec.collisionWidth = 12;
	projectileSpec.collisionHeight = 65;
	projectileSpec.collisionOffset = Vector2D(6,35);
	return projectileSpec;
}

