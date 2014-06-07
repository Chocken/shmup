#include "BasicEnemy.h"
#include "GameObjects.h"
#include "Settings.h"
#include "PlayState.h"
#include <iostream>
#include <stdlib.h>

BasicEnemy::BasicEnemy()
{
	life = 100;
	fired = false;
	sheetVector = Vector2D(0,0);
	isRed = false;
	dying = false;
	explosionCount = 0;
	boss = false;
}
BasicEnemy::~BasicEnemy()
{
	delete behaviour;
}

void BasicEnemy::Update(Uint32 deltaTicks)
{
	if(y > Settings::ScreenHeight)
	{
		isActive = false;
	}		
	
	behaviour->Update(deltaTicks);
	
	if(isRed){ sheetVector.x = width; }
	else { sheetVector.x = 0; }

	if(flashTimer.get_ticks() > 10) {isRed = false; flashTimer.stop();}	
}

void BasicEnemy::Draw(SDL_Surface* surface)
{
	if (Sprite::Draw(surface, sprite, x, y, sheetVector.x,sheetVector.y,width,height) == false)
	{
		printf("enemy not drawn successfully\n");
	}
}

void BasicEnemy::TakeDamage(int damage)
{
	life -= damage;
}

void BasicEnemy::SetLocation(Vector2D Location)
{
	x = Location.x;
	y = Location.y;	
}

void BasicEnemy::SetLocationByCenter(Vector2D Location)
{
	x = Location.x + width/2;
	y = Location.y + height/2;
}

void BasicEnemy::OnProjectileHit()
{
	isRed = !isRed;
	flashTimer.start();
	if(life <= 0)
	{
		if(explosionFactory.width < (width * 2))
		{
			int explosionArea = explosionFactory.width * explosionFactory.height;
			int enemyArea = collisionWidth * collisionHeight;
			for(int i=0; i<(enemyArea/explosionArea*4); i++)
			{			
				int randWidth = (std::rand() % (int)((collisionWidth))) - ((int)(collisionWidth)/2);
				int randHeight = (std::rand() % (int)((collisionHeight))) - ((int)(collisionHeight)/2);
				Explosion* explosion = explosionFactory.CreateExplosion(explosionSprite, Center() + Vector2D(randWidth,randHeight));				
				GameObjects::Instance()->explosions.push_back(explosion);
			}			
				
		}
		else
		{
			Explosion* explosion = explosionFactory.CreateExplosion(explosionSprite, Center());
			GameObjects::Instance()->explosions.push_back(explosion);			
		}
		if(Mix_PlayChannel( -1, explosionSound, 0 )== -1)
			{
				printf("sound not played\n");
			}
		isActive = false;

		if(boss)
		{
			PlayState::Instance()->bossDestroyed = true;
		}	
	}
}


