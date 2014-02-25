#ifndef LEVEL_H
#define LEVEL_H

#include "Background.h"
#include "PlayerShip.h"
#include "Timer.h"
#include "Game.h"
#include "GameObjectFactory.h"
#include "Explosion.h"
#include "SDL/SDL.h"
#include "GamePlayObject.h"
#include "CollisionDetector.h"
#include "Obstacle.h"
#include "StraightProjectile.h"
#include "Enemy.h"
#include "ExplosionFactory.h"
#include "TextRenderer.h"
#include <memory>
#include <boost/ptr_container/ptr_list.hpp>


class Level
{

	public:
		void Init(int levelno);
		void Clean();
		void HandleEvents(SDL_Event event, Game* game);
		void Update();
		void Draw(Game* game);
		void Pause();
		bool levelFinished;

	private:
		void Draw(boost::ptr_list<Explosion>& Objects, SDL_Surface* screen);
		void Draw(boost::ptr_list<Enemy>& enemies, SDL_Surface* screen);
		void Draw(boost::ptr_list<Projectile>& projectiles, SDL_Surface* screen);

		void Update(boost::ptr_list<Explosion>& Objects, Uint32 deltaTicks);
		void Update(boost::ptr_list<Enemy>& enemies, Uint32 deltaTicks);
		void Update(boost::ptr_list<Projectile>& projectiles, Uint32 deltaTicks);

		void HandleCollisions(boost::ptr_list<Enemy>& gameObjects, PlayerShip& playerShip);
		void HandleCollisions(boost::ptr_list<Projectile>& gameObjects, PlayerShip& playerShip);
		void HandleCollisions(boost::ptr_list<Projectile>& projectiles,boost::ptr_list<Enemy>& enemies);

		TextRenderer score;
		ExplosionFactory explosionFactory;
		void UpdateProjectiles();		
		GameObjectFactory objFactory;							
		Timer timer;
		Timer explosionTimer;
		Background background;		
				
		CollisionDetector collisionDetector;
};

#endif
