#ifndef GAME_OBJECT_FACTORY_H
#define GAME_OBJECT_FACTORY_H

#include <map>
#include "SDL/SDL.h"
#include "SDL/SDL_mixer.h"
#include "Sprite.h"
#include "Background.h"
#include "PlayerShip.h"
#include "BlackScreen.h"
#include "Explosion.h"
#include "Vector2D.h"
#include "StraightProjectile.h"
#include "Enemy.h"
#include "BasicEnemy.h"
#include "WeaponEnemy.h"
#include "WeaponType.h"
#include "GameObjectSpec.h"
#include "SpecFactory.h"
#include <vector>
#include <memory>
#include <string>

class GameObjectFactory
{
	public:
		void Init(std::string assetsfile, std::string enemyDataFile);
		void QueueExplosion(Vector2D location);				
		Background CreateBackground();
		PlayerShip CreatePlayerShip();
		Explosion* CreateExplosion(Vector2D centerLocation);
		StraightProjectile* CreateStraightProjectile(Vector2D location, Vector2D direction, float speed);
		BasicEnemy* CreateEnemy();		
	
		std::shared_ptr<IWeapon> CreatePlayerWeapon(WeaponType weaponType);
		Enemy* CreateEnemy(std::vector<std::string> rawSpec);		
		void Update(float scrollDistance);
		void Clean();

	private:			
		SpecFactory specFactory;
		std::vector<std::string> split(std::string input, char delim);
		std::map<std::string,SDL_Surface*> spriteMap;
		std::map<std::string,Mix_Chunk*> soundMap;
		std::map<float,std::vector<std::string>> enemyDataMap;
		std::shared_ptr<IWeapon> CreateWeapon(WeaponType weaponType,boost::ptr_list<Projectile>& projectiles);	
		void GetEnemySpec(std::string fileName);
		void GetAssets(std::string fileName);
		
};

#endif
