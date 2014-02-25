#ifndef SPEC_FACTORY_H
#define SPEC_FACTORY_H

#include "GameObjectSpec.h"
#include "BasicEnemySpec.h"
#include <string>
#include <vector>

class SpecFactory
{
	public:
		GameObjectSpec CreateStraightProjectileSpec();
		GameObjectSpec CreateSpreadProjectileSpec();
		GameObjectSpec CreateLazerProjectileSpec();
		GameObjectSpec CreateLazer2ProjectileSpec();
		GameObjectSpec CreateSpecFromVect(const std::vector<std::string>& data);
		BasicEnemySpec CreateEnemySpecFromVect(const std::vector<std::string>& data);
		
};

#endif
