#include "GameObjectFactory.h"
#include "Background.h"
#include "Sprite.h"
#include "Obstacle.h"
#include "SineBehaviour.h"
#include "VerticalLineBehaviour.h"
#include "StraightWeapon.h"
#include "SplineBehaviour.h"
#include "BossBehaviourOne.h"
#include "GameObjects.h"
#include "LazerWeapon.h"
#include "SpreadWeapon.h"
#include "SpreadWeapon2.h"
#include "rapidxml.hpp"
#include "rapidxml_utils.hpp"
#include <fstream>
#include <sstream>
#include <memory>
using namespace rapidxml;



void GameObjectFactory::Init(std::string assetsfile, std::string enemyDataFile)
{	
	Mix_Chunk* smallExplosion = Mix_LoadWAV("explosion.wav");	
	soundMap["smallExplosion"] = smallExplosion;
	GetEnemySpec("leveldata/" + enemyDataFile);
	GetAssets("leveldata/" + assetsfile);
	std::map<float,std::vector<std::string>>::iterator iter=enemyDataMap.begin();
}

void GameObjectFactory::Clean()
{	
	std::map<std::string,SDL_Surface*>::iterator spriteIter=spriteMap.begin();
	while (spriteIter != spriteMap.end())
	{
		SDL_FreeSurface(spriteIter->second);		
		++spriteIter;
	}

	std::map<std::string,Mix_Chunk*>::iterator soundIter=soundMap.begin();
	while (soundIter != soundMap.end())
	{
		Mix_FreeChunk(soundIter->second);		
		++soundIter;
	}
}

Background GameObjectFactory::CreateBackground()
{
	Background background;
	background.sprite = spriteMap["background"];
	background.Init();
	background.SetIsActive(true);
	return background;
}

PlayerShip GameObjectFactory::CreatePlayerShip()
{
	PlayerShip playerShip;
	playerShip.sprite = spriteMap["playerShip"];
	playerShip.Init();
	playerShip.SetIsActive(true);
	playerShip.projectileSprite = spriteMap["projectile1"];
	playerShip.explosionSprite = spriteMap["explosions"];
	playerShip.explosionFactory.Init(9,90,90);	
	return playerShip;
}

Explosion* GameObjectFactory::CreateExplosion(Vector2D centerLocation)
{
	Explosion* explosion = new Explosion(centerLocation, 90,90);
	explosion->sprite = spriteMap["explosions"];
	explosion->frames = 9;
	explosion->SetIsActive(true);		
	return explosion;
}


Enemy* GameObjectFactory::CreateEnemy(std::vector<std::string> rawSpec)
{

	BasicEnemySpec spec = specFactory.CreateEnemySpecFromVect(rawSpec);

	BasicEnemy* enemy = new BasicEnemy();
	enemy->sprite = spriteMap[rawSpec[0]];
	enemy->explosionSound = soundMap[rawSpec[1]];
	enemy->width = spec.gameObjectSpec.width;
	enemy->height = spec.gameObjectSpec.height;
	enemy->collisionWidth = spec.gameObjectSpec.collisionWidth;
	enemy->collisionHeight = spec.gameObjectSpec.collisionHeight;
	enemy->CollisionOffset = spec.gameObjectSpec.collisionOffset;
	enemy->SetIsActive(true);
	enemy->collisionType = spec.gameObjectSpec.collisionType;
	enemy->explosionSprite = spriteMap[rawSpec[15]];
	enemy->explosionFactory.Init(spec.explFactoryFrames,spec.explFactoryWidth, spec.explFactoryHeight);
	enemy->SetLocation(spec.startingLocation);
	enemy->life = atof(rawSpec[14].c_str());
	
	if(rawSpec[16] == "spline")
	{
		enemy->behaviour = new SplineBehaviour(
			enemy, 
			Vector2D(atof(rawSpec[17].c_str()),atof(rawSpec[18].c_str())),
			Vector2D(atof(rawSpec[19].c_str()),atof(rawSpec[20].c_str())),
			Vector2D(atof(rawSpec[21].c_str()),atof(rawSpec[22].c_str())),
			Vector2D(atof(rawSpec[23].c_str()),atof(rawSpec[24].c_str())),
			atof(rawSpec[25].c_str())
		);
	}
	else if(rawSpec[16] == "sine")
	{
			enemy->behaviour = new SineBehaviour(
				enemy,
				atof(rawSpec[17].c_str()),
				atof(rawSpec[18].c_str()),
				atof(rawSpec[19].c_str())
			);
	}
	else if(rawSpec[16] == "straight")
	{
			enemy->behaviour = new VerticalLineBehaviour(atof(rawSpec[17].c_str()),enemy);
	}
	else if (rawSpec[16] == "boss1")
	{
		enemy->behaviour = new BossBehaviourOne(enemy);
		enemy->weapons.push_back(CreateWeapon(STRAIGHT,GameObjects::Instance()->enemyProjectiles));
		enemy->weapons.push_back(CreateWeapon(SPREAD,GameObjects::Instance()->enemyProjectiles));		
	}
	return enemy;
}

std::shared_ptr<IWeapon> GameObjectFactory::CreateWeapon(WeaponType weaponType,boost::ptr_list<Projectile>& projectiles)
{
	GameObjectSpec projectileSpec;	
	std::shared_ptr<IWeapon> weapon;
	switch (weaponType)
	{		
		case STRAIGHT:			
			projectileSpec = specFactory.CreateStraightProjectileSpec();	
			weapon =  std::shared_ptr<IWeapon>(new StraightWeapon(spriteMap["projectile"],projectileSpec,projectiles));			
			break;
		case LAZER:		
			projectileSpec = specFactory.CreateLazerProjectileSpec();	
			weapon = std::shared_ptr<IWeapon>(new LazerWeapon(spriteMap["lazer"],projectileSpec,projectiles));
			break;
		case LAZER2:		
			projectileSpec = specFactory.CreateLazer2ProjectileSpec();
			weapon = std::shared_ptr<IWeapon>(new LazerWeapon(spriteMap["lazer2"],projectileSpec,projectiles));
			break;
		case SPREAD:
			projectileSpec = specFactory.CreateSpreadProjectileSpec();
			weapon = std::shared_ptr<IWeapon>(new SpreadWeapon(spriteMap["purpleBullet"],projectileSpec,projectiles));
			break;
		case SPREAD2:			 
			projectileSpec = specFactory.CreateSpreadProjectileSpec();	
			weapon = std::shared_ptr<IWeapon>(new SpreadWeapon2(spriteMap["purpleBullet"],projectileSpec,projectiles));
			break;			
	}

return weapon;
}

std::shared_ptr<IWeapon> GameObjectFactory::CreatePlayerWeapon(WeaponType weaponType)
{
	return CreateWeapon(weaponType,GameObjects::Instance()->projectiles);
}

StraightProjectile* GameObjectFactory::CreateStraightProjectile(Vector2D location, Vector2D direction, float speed)
{
	printf("creating projectile\n");
	StraightProjectile* projectile = new StraightProjectile(location, direction, speed, 10);
	projectile->sprite = spriteMap["projectile1"];
	projectile->CollisionOffset = Vector2D(3,2);
	projectile->collisionHeight = 10;
	projectile->collisionWidth = 10;
	projectile->collisionType = CIRC;
	projectile->SetIsActive(true);
	return projectile;
}

void GameObjectFactory::Update(float scrollDistance)
{
	std::map<float,std::vector<std::string>>::iterator iter=enemyDataMap.begin();
	while (iter != enemyDataMap.end())
	{			
			if (scrollDistance > iter->first)
			{				
				GameObjects::Instance()->enemies.push_back(CreateEnemy(iter->second));
				enemyDataMap.erase(iter->first);				
			}
			++iter;		
	}
}


void GameObjectFactory::GetEnemySpec(std::string fileName)
{
	std::ifstream myfile(fileName);
	std::string line;
	std::vector<std::string> rawSpec;
	std::string time;
  if (myfile.is_open())
  {
  	while ( getline (myfile,line) )
  	{
			int start = line.find(' ');
			time = line.substr(0,start+1);
			std::string data = line.substr(start+1);
	 		rawSpec = split(data,' ');
			enemyDataMap[atof(time.c_str())] = rawSpec;				
   	}
   	myfile.close();
  }
}

void GameObjectFactory::GetAssets(std::string fileName)
{
	std::ifstream myfile(fileName);
	
	file<> file(const_cast<char *>(fileName.c_str()));
	xml_document<> doc;
	doc.parse<0>(file.data());
	xml_node<> *pRoot = doc.first_node();
	
	for(xml_node<> *pSubNode=pRoot->first_node("texture"); pSubNode; pSubNode=pSubNode->next_sibling())	
	{	
		xml_attribute<> *nameAttr = pSubNode->first_attribute("name");		
		xml_attribute<> *imageAttr = pSubNode->first_attribute("imagefile");	
		xml_attribute<> *transparentAttr = pSubNode->first_attribute("transparent");		

		SDL_Surface* surface = Sprite::Load(const_cast<char *>(imageAttr->value()), atoi(transparentAttr->value()));
		spriteMap[nameAttr->value()] = surface;
	}
}

std::vector<std::string> GameObjectFactory::split(std::string input, char delim)
{	
	std::vector<std::string> output1;	
	if(input.find_first_of(delim) == -1)
	{
		output1.push_back(input);		
		return output1;
	}
	output1.push_back(input.substr(0,input.find_first_of(delim)));
	std::vector<std::string> output2 = split(input.substr(input.find_first_of(delim)+1),delim);
	
	std::vector<std::string> output;
	output.reserve( output1.size() + output2.size() );
	output.insert( output.end(), output1.begin(), output1.end() );
	output.insert( output.end(), output2.begin(), output2.end() );
	
	return output;
}

