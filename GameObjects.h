#ifndef GAME_OBJECTS_H
#define GAME_OBJECTS_H

#include "Enemy.h"
#include "GamePlayObject.h"
#include "StraightProjectile.h"
#include "PlayerShip.h"
#include <boost/ptr_container/ptr_list.hpp>

class GameObjects
{
	public:
		static GameObjects* Instance()
		{
			return &m_GameObjects;
		}
		boost::ptr_list<Projectile> projectiles;
		boost::ptr_list<Projectile> enemyProjectiles;
		boost::ptr_list<Enemy> enemies;
		boost::ptr_list<Explosion> explosions;	

		PlayerShip playerShip;		
		
	private:
		static GameObjects m_GameObjects;
};

#endif
