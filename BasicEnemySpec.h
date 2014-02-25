#ifndef BASIC_ENEMY_SPEC_H
#define BASIC_ENEMY_SPEC_H
#include "GameObjectSpec.h"
#include "Behaviour.h"

class BasicEnemySpec
{
	public:
		GameObjectSpec gameObjectSpec;		
		Vector2D startingLocation;
		int explFactoryWidth;
		int explFactoryHeight;
		int explFactoryFrames;
};

#endif
