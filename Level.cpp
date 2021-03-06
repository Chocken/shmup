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
	objFactory = GameObjectFactory();		
	objFactory.Init("assets"+boost::lexical_cast<std::string>(levelno)+".xml","enemies"+boost::lexical_cast<std::string>(levelno)+".xml");
	background = objFactory.CreateBackground();
	PlayerShip playerShip = objFactory.CreatePlayerShip();
	GameObjects::Instance()->playerShip = playerShip;
	GameObjects::Instance()->playerShip.weapon = objFactory.CreatePlayerWeapon(SPREAD2);
	SDL_Color textColor = { 255, 255, 255 };
	lives = TextRenderer(const_cast<char *>("manaspc.ttf"),15, textColor);
	score = TextRenderer(const_cast<char *>("manaspc.ttf"),15, textColor);
	storedLives = GameObjects::Instance()->PlayerLives;
	storedScore = GameObjects::Instance()->PlayerScore;
	lives.SetText("REST: " + std::to_string(GameObjects::Instance()->PlayerLives));
	score.SetText("SCORE: " + std::to_string(GameObjects::Instance()->PlayerScore));	
	timer.start();
	explosionTimer.start();
}

void Level::Clean()
{
	lives.Free();
	score.Free();		
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
	background.Update(timer.get_ticks());

	if(GameObjects::Instance()->playerShip.isActive)
	{
		GameObjects::Instance()->playerShip.Update(timer.get_ticks());	
	}

	if(GameObjects::Instance()->PlayerLives != storedLives)
	{
		lives.Free();
		lives.SetText("REST: " + std::to_string(GameObjects::Instance()->PlayerLives));
		storedLives = GameObjects::Instance()->PlayerLives;	
	}

	if(GameObjects::Instance()->PlayerScore != storedScore)
	{
		score.Free();
		score.SetText("SCORE: " + std::to_string(GameObjects::Instance()->PlayerScore));
		storedScore = GameObjects::Instance()->PlayerScore;	
	}

	HandleCollisions(GameObjects::Instance()->enemies, GameObjects::Instance()->playerShip);
	Update(GameObjects::Instance()->enemies, timer.get_ticks());
	HandleCollisions(GameObjects::Instance()->projectiles,GameObjects::Instance()->enemies);
	Update(GameObjects::Instance()->projectiles,timer.get_ticks());
	HandleCollisions(GameObjects::Instance()->enemyProjectiles, GameObjects::Instance()->playerShip); 
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
	
	if(GameObjects::Instance()->playerShip.isActive)
	{
		GameObjects::Instance()->playerShip.Draw(game->GetScreen());
	}
	Draw(GameObjects::Instance()->explosions, game->GetScreen());

	lives.Draw(game->GetScreen(), 0, 10);
	score.Draw(game->GetScreen(), 450, 10);
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






