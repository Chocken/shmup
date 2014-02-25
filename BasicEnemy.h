#ifndef BASIC_ENEMY_H
#define BASIC_ENEMY_H

#include "GamePlayObject.h"
#include "SDL/SDL.h"
#include "SDL/SDL_mixer.h"
#include "ExplosionFactory.h"
#include "Explosion.h"
#include "IWeapon.h"
#include "Enemy.h"
#include "Vector2D.h"
#include "StraightWeapon.h"
#include "Behaviour.h"
#include <memory>

using namespace std;


class BasicEnemy: public Enemy
{
	public:
		BasicEnemy();
		~BasicEnemy();
		void Update(Uint32 deltaTicks);
		void Draw(SDL_Surface* surface);
		void TakeDamage(int damage);
		void SetLocation(Vector2D Location);
		void SetLocationByCenter(Vector2D Location);
		void OnProjectileHit();	
		int life;
		SDL_Surface* projectileSprite;
		SDL_Surface* explosionSprite;
		Mix_Chunk *explosionSound;
		Behaviour* behaviour;	
		vector<shared_ptr<IWeapon>> weapons;		
		ExplosionFactory explosionFactory;

	protected:						
		bool fired;
		bool dying;
		Vector2D sheetVector;
		Timer flashTimer;
		Timer explosionTimer;
		int explosionCount;
		bool isRed;
};
#endif
