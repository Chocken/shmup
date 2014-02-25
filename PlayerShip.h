#ifndef PLAYER_SHIP_H
#define PLAYER_SHIP_H

#include "SDL/SDL.h"
#include "DrawableObject.h"
#include "Explosion.h"
#include "IUpdateable.h"
#include "GamePlayObject.h"
#include "Timer.h"
#include "StraightProjectile.h"
#include "StraightWeapon.h"
#include "IWeapon.h"
#include <memory>

class PlayerShip: public GamePlayObject
{
	public:
		PlayerShip();	
		void Update(Uint32 deltaTicks);
		void Draw(SDL_Surface* surface);
		void HandleEvents(SDL_Event event);
		void Init();		
		void GetHit();
		StraightProjectile* projectile;		
		SDL_Surface* projectileSprite;
		std::shared_ptr<IWeapon> weapon;
		SDL_Surface* explosionSprite;
		bool isRecentlyHit();
		void OnPause();
		ExplosionFactory explosionFactory;  		
				
	private:
		int frame;
		int velocity;
		int xVel;
		int yVel;
		int up, down, left, right;
		bool drawing;
		bool recentlyHit;		
		Timer hitTimer;
		Timer blinkTimer;
		Timer weaponTimer;
		ProjectileFactory projectileFactory;		
		bool firing;
		int shotCount;				
};

#endif

