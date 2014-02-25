#ifndef SHIP_PROJECTILE_MANAGER_H
#define SHIP_PROJECTILE_MANAGER_H

#include "GamePlayObject.h"
#include "Game.h"
#include <boost/ptr_container/ptr_list.hpp>

class ShipProjectileManager
{
	public:		
		void AddProjectile(GamePlayObject* object);
		void Update(Uint32 deltaTicks);
		void Draw(Game* game);

		boost::ptr_list<GamePlayObject> gamePlayObjects;
};

#endif
