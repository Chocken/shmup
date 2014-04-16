#include "Level.h"
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "PauseState.h"
#include "MenuState.h"
#include "Game.h"
#include "Background.h"
#include "BlackScreen.h"
#include "PlayerShip.h"
#include "GameObjects.h"
#include "WeaponType.h"
#include <string>
#include <boost/ptr_container/ptr_list.hpp>
#include <boost/lexical_cast.hpp>
#include <iostream>

GameObjects GameObjects::m_GameObjects;

void Level::Init(int levelno)
{		
	levelFinished = false;	
	objFactory.Init("assets"+boost::lexical_cast<std::string>(levelno)+".txt","enemies"+boost::lexical_cast<std::string>(levelno)+".txt");
	printf("objectfactory initialized\n");
	background = objFactory.CreateBackground();
	PlayerShip playerShip = objFactory.CreatePlayerShip();
	GameObjects::Instance()->playerShip = playerShip;
	GameObjects::Instance()->playerShip.weapon = objFactory.CreatePlayerWeapon(SPREAD);
	SDL_Color textColor = { 255, 255, 255 };
	score = TextRenderer(const_cast<char *>("manaspc.ttf"),28, textColor);
	timer.start();
	explosionTimer.start();
	printf("level initialized\n");
}

void Level::Clean()
{		
	GameObjects::Instance()->enemies.clear();
	GameObjects::Instance()->projectiles.clear();
	GameObjects::Instance()->explosions.clear();
	GameObjects::Instance()->enemyProjectiles.clear();
	objFactory.Clean();	
}

void Level::Pause()
{
	GameObjects::Instance()->playerShip.OnPause();
	timer.pause();	
}

void Level::HandleEvents(SDL_Event event, Game* game)
{

	GameObjects::Instance()->playerShip.HandleEvents(event);
	switch (event.type) 
	{			
		case SDL_KEYDOWN:
			switch(event.key.keysym.sym)
			{
				case SDLK_SPACE:			
					game->PushState(PauseState::Instance());					
					break;
					
				case SDLK_RETURN:
					levelFinished = true;															
					break;							
			}
			break;
		case SDL_JOYBUTTONDOWN: 
    			if ( event.jbutton.button == 0 ) 
    			{
        			game->PushState(PauseState::Instance());
    			}
    			break;		
	}

		
	
}

void Level::Update()
{
	HandleCollisions(GameObjects::Instance()->enemies, GameObjects::Instance()->playerShip);
	HandleCollisions(GameObjects::Instance()->enemyProjectiles, GameObjects::Instance()->playerShip); 
	HandleCollisions(GameObjects::Instance()->projectiles,GameObjects::Instance()->enemies);		

	background.Update(timer.get_ticks());
	GameObjects::Instance()->playerShip.Update(timer.get_ticks());	
	
	Update(GameObjects::Instance()->enemies, timer.get_ticks());
	Update(GameObjects::Instance()->projectiles,timer.get_ticks());
	Update(GameObjects::Instance()->enemyProjectiles,timer.get_ticks());
	Update(GameObjects::Instance()->explosions, timer.get_ticks());
	objFactory.Update(background.DistanceScrolled());
		
	timer.start();	
}

void Level::Draw(Game* game) 
{
	background.Draw(game->GetScreen());
	
	Draw(GameObjects::Instance()->enemies, game->GetScreen());	
	Draw(GameObjects::Instance()->projectiles, game->GetScreen());
	Draw(GameObjects::Instance()->enemyProjectiles, game->GetScreen());
	GameObjects::Instance()->playerShip.Draw(game->GetScreen());
	Draw(GameObjects::Instance()->explosions, game->GetScreen());	
}

void Level::Draw(boost::ptr_list<Explosion>& objects, SDL_Surface* screen)
{
	boost::ptr_list<DrawableObject>::iterator objIter = objects.begin();
	while (objIter != objects.end())
	{			
			objIter->Draw(screen);		
			++objIter;		
	}
}

void Level::Draw(boost::ptr_list<Enemy>& enemies, SDL_Surface* screen)
{
	boost::ptr_list<Enemy>::iterator enemyIter = enemies.begin();

	while (enemyIter != enemies.end())
	{			
			enemyIter->Draw(screen);		
			++enemyIter;				
	}

	
}

void Level::Draw(boost::ptr_list<Projectile>& projectiles, SDL_Surface* screen)
{
	boost::ptr_list<StraightProjectile>::iterator projectileIter = projectiles.begin();
	while (projectileIter != projectiles.end())
	{			
			projectileIter->Draw(screen);
			++projectileIter;
	}
}

void Level::Update(boost::ptr_list<Explosion>& Objects, Uint32 deltaTicks)
{
	boost::ptr_list<Explosion>::iterator objIter = Objects.begin();
	while (objIter != Objects.end())
	{
		
		if(objIter->GetIsActive() == false)
		{					
			objIter = Objects.erase(objIter);
		}
		else
		{						
			objIter->Update(deltaTicks);		
		}
		
		++objIter;
	}
}

void Level::Update(boost::ptr_list<Projectile>& projectiles, Uint32 deltaTicks)
{
	boost::ptr_list<Projectile>::iterator projectileIter = projectiles.begin();
	while (projectileIter != projectiles.end())
	{
		
		if(projectileIter->GetIsActive() == false)
		{					
			projectileIter = projectiles.erase(projectileIter);
		}
		else
		{			
			projectileIter->Update(deltaTicks);			
		}
		
		++projectileIter;
	}
}

void Level::Update(boost::ptr_list<Enemy>& enemies, Uint32 deltaTicks)
{	
	boost::ptr_list<Enemy>::iterator enemyIter = enemies.begin();

	while (enemyIter != enemies.end())
	{
		if(enemyIter->GetIsActive() == false)
		{					
			enemyIter = enemies.erase(enemyIter);
		}		
		else
		{
			enemyIter->Update(deltaTicks);	
		}
		++enemyIter;				
	}	
}

void Level::HandleCollisions(boost::ptr_list<Enemy>& gameObjects, PlayerShip& playerShip)
{	
	boost::ptr_list<Enemy>::iterator gameObjectIter = gameObjects.begin();
	while (gameObjectIter != gameObjects.end())
	{
		if(playerShip.isRecentlyHit() == false)
		{				
			if(collisionDetector.DetectCollision(&(*gameObjectIter), &(playerShip)))
			{
				playerShip.GetHit();
			}
		}
		++gameObjectIter;				
	}	
}

void Level::HandleCollisions(boost::ptr_list<Projectile>& gameObjects, PlayerShip& playerShip)
{	
	boost::ptr_list<Projectile>::iterator gameObjectIter = gameObjects.begin();
	while (gameObjectIter != gameObjects.end())
	{
		if(playerShip.isRecentlyHit() == false)
		{				
			if(collisionDetector.DetectCollision(&(*gameObjectIter), &(playerShip)))
			{
				playerShip.GetHit();
			}
		}
		++gameObjectIter;				
	}	
}


void Level::HandleCollisions(boost::ptr_list<Projectile>& projectiles,boost::ptr_list<Enemy>& enemies)
{
	boost::ptr_list<Projectile>::iterator projectileIter = projectiles.begin();

	while(projectileIter != projectiles.end())
	{
		boost::ptr_list<Enemy>::iterator enemyIter = enemies.begin();				
		while (enemyIter != enemies.end())
		{										
			if(collisionDetector.DetectCollision(&(*projectileIter), &(*enemyIter)))
			{						
				projectileIter->OnCollision(&(*enemyIter));
				enemyIter->OnProjectileHit();						
			}			
			++enemyIter;	
		}		
		++projectileIter;
	}
	
} 






