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
#include "PlayState.h"
#include <fstream>
#include <sstream>
#include <memory>
using namespace rapidxml;

GameObjectFactory::GameObjectFactory(){}

void GameObjectFactory::Init(std::string assetsfile, std::string enemyDataFile)
{	
	Mix_Chunk* smallExplosion = Mix_LoadWAV("explosion.wav");	
	soundMap["smallExplosion"] = smallExplosion;
	GetEnemySpec("leveldata/" + enemyDataFile);
	GetAssets("leveldata/" + assetsfile);		
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

Enemy* GameObjectFactory::CreateEnemy(EnemySpec spec)
{	
	BasicEnemy* enemy = new BasicEnemy();

	enemy->sprite = spriteMap[spec.sprite];
	enemy->explosionSound = soundMap[spec.explosionSound];
	enemy->explosionSprite = spriteMap[spec.explosionSprite];

	if (spec.collisionType == "CIRC") {enemy->collisionType = CIRC;}
	else if (spec.collisionType == "RECT"){enemy->collisionType = RECT;}

	enemy->width = spec.width;
	enemy->height = spec.height;
	enemy->collisionWidth = spec.collisionWidth;
	enemy->collisionHeight = spec.collisionHeight;
	enemy->CollisionOffset = Vector2D(spec.collisionOffset.x,spec.collisionOffset.y);
	enemy->explosionFactory.Init(spec.explFactoryFrames,spec.explFactoryWidth, spec.explFactoryHeight);
	enemy->SetLocation(Vector2D(spec.startingLocation.x,spec.startingLocation.y));
	enemy->life = spec.life;
	enemy->boss = spec.boss;
	enemy->scoreValue = spec.scoreValue;

	std::vector<std::string>::iterator weaponIter = spec.weapons.begin();
	while (weaponIter != spec.weapons.end())
	{
		if(*weaponIter == "STRAIGHT")
		{
			enemy->weapons.push_back(CreateWeapon(STRAIGHT,GameObjects::Instance()->enemyProjectiles));
		}
		else if(*weaponIter == "SPREAD")
		{
			enemy->weapons.push_back(CreateWeapon(SPREAD,GameObjects::Instance()->enemyProjectiles));
		} 
		++weaponIter;
	}	
	
	if(spec.behaviour == "boss1")
	{
		enemy->behaviour = new BossBehaviourOne(enemy);		
	}
	else if(spec.behaviour == "sine")
	{		
		enemy->behaviour = new SineBehaviour(enemy,spec.amplitude,spec.frequency,spec.speed);		
	}
	else if(spec.behaviour == "spline")
	{
		enemy->behaviour = new SplineBehaviour(enemy,spec.p0,spec.p1,spec.p2,spec.p3, spec.speed);
	}
	
	enemy->SetIsActive(true);		
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

	std::map<float,EnemySpec>::iterator enemyIter=enemyData.begin();
	while(enemyIter != enemyData.end())
	{		
		if (scrollDistance > enemyIter->first)
		{		
			Enemy* enemy = CreateEnemy(enemyIter->second);
			GameObjects::Instance()->enemies.push_back(enemy);					
			enemyData.erase(enemyIter++);				
		}
		else
		{
			++enemyIter;
		}		
	}

	

}


void GameObjectFactory::GetEnemySpec(std::string fileName)
{		
	std::ifstream myfile(fileName);
	file<> file(const_cast<char *>(fileName.c_str()));
	xml_document<> doc;
	doc.parse<0>(file.data());
	xml_node<> *pRoot = doc.first_node();
	for(xml_node<> *pSubNode=pRoot->first_node("enemy"); pSubNode; pSubNode=pSubNode->next_sibling())	
	{
		xml_attribute<> *timeAttr = pSubNode->first_attribute("time");

		EnemySpec spec;		
		spec.sprite = pSubNode->first_attribute("sprite")->value();
		spec.explosionSound = pSubNode->first_attribute("explosionSound")->value();
		spec.explosionSprite = pSubNode->first_attribute("explosionSprite")->value();
		spec.collisionType = pSubNode->first_attribute("collisionType")->value();
		spec.scoreValue = atoi(pSubNode->first_attribute("scoreValue")->value());
		spec.boss = atoi(pSubNode->first_attribute("boss")->value());
		spec.width = atoi(pSubNode->first_node("width")->value());
		spec.height = atoi(pSubNode->first_node("width")->value());		
		spec.collisionWidth = atoi(pSubNode->first_node("collisionWidth")->value());
		spec.collisionHeight = atoi(pSubNode->first_node("collisionHeight")->value());
		spec.collisionOffset.x = atoi(pSubNode->first_node("collisionOffsetX")->value());
		spec.collisionOffset.y = atoi(pSubNode->first_node("collisionOffsetY")->value());
		spec.startingLocation.x = atoi(pSubNode->first_node("startingLocationX")->value());
		spec.startingLocation.y = atoi(pSubNode->first_node("startingLocationY")->value());
		spec.explFactoryWidth = atoi(pSubNode->first_node("explFactoryWidth")->value());
		spec.explFactoryHeight = atoi(pSubNode->first_node("explFactoryHeight")->value());
		spec.explFactoryFrames = atoi(pSubNode->first_node("explFactoryFrames")->value());
		spec.life = atoi(pSubNode->first_node("life")->value());
		

		xml_node<>* behaviour = pSubNode->first_node("behaviour");
		spec.behaviour = behaviour->first_attribute("name")->value();
		
		xml_node<>* weapons = pSubNode->first_node("weapons");
		
		for(xml_node<>* weapon=weapons->first_node("weapon"); weapon; weapon=weapon->next_sibling())	
		{
			spec.weapons.push_back(weapon->value());
		}

		if(spec.behaviour == "sine")
		{
			spec.amplitude = atoi(behaviour->first_node("amplitude")->value());
			spec.frequency = atoi(behaviour->first_node("frequency")->value());
			spec.speed = atoi(behaviour->first_node("speed")->value());			
		}

		else if(spec.behaviour == "spline")
		{
			
			spec.p0.x = atof(behaviour->first_node("p0")->first_attribute("x")->value());
			spec.p0.y = atof(behaviour->first_node("p0")->first_attribute("y")->value());
			spec.p1.x = atof(behaviour->first_node("p1")->first_attribute("x")->value());
			spec.p1.y = atof(behaviour->first_node("p1")->first_attribute("y")->value());
			spec.p2.x = atof(behaviour->first_node("p2")->first_attribute("x")->value());
			spec.p2.y = atof(behaviour->first_node("p2")->first_attribute("y")->value());
			spec.p3.x = atof(behaviour->first_node("p3")->first_attribute("x")->value());
			spec.p3.y = atof(behaviour->first_node("p3")->first_attribute("y")->value());
			spec.speed = atof(behaviour->first_node("speed")->value());		
		}		
		
		enemyData[atof(timeAttr->value())] = spec;

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
