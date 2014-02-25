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

GameObjectSpec SpecFactory::CreateSpecFromVect(const std::vector<std::string>& data)
{
	GameObjectSpec spec;
	if (data[13] == "CIRC") {spec.collisionType = CIRC;}
	else if (data[13] == "RECT"){spec.collisionType = RECT;}
	else {printf("no collision type found\n");}

	spec.width = atof(data[2].c_str());
	spec.height = atof(data[3].c_str());
	spec.collisionWidth = atof(data[4].c_str());
	spec.collisionHeight = atof(data[5].c_str());
	spec.collisionOffset = Vector2D(atof(data[6].c_str()),atof(data[7].c_str()));

	return spec;
}

BasicEnemySpec SpecFactory::CreateEnemySpecFromVect(const std::vector<std::string>& data)
{
	BasicEnemySpec spec;
	spec.gameObjectSpec = CreateSpecFromVect(data);
	spec.explFactoryFrames = atof(data[8].c_str()),
	spec.explFactoryWidth = atof(data[9].c_str()),
	spec.explFactoryHeight = atof(data[10].c_str()),

	
	spec.startingLocation = Vector2D(atof(data[11].c_str()),atof(data[12].c_str()));

	return spec;
}
