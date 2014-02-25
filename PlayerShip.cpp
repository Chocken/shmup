#include "PlayerShip.h"
#include "Sprite.h"
#include "IUpdateable.h"
#include "StraightProjectile.h"
#include "Vector2D.h"
#include "Sprite.h"
#include "Settings.h"
#include "GameObjects.h"
#include "StraightWeapon.h"
#include "PlayState.h"
#include <iostream>

Uint8* Game::keystate;

PlayerShip::PlayerShip()
{
}

void PlayerShip::Init()
{
	x = 500;
	y = 500;
	xVel = 0;
	yVel = 0;
	frame = 1;
	height = 40;
	width = 40;
	collisionWidth = 30;
	collisionHeight = 30;
	CollisionOffset = Vector2D(5,10);
	velocity = 300;
	collisionType = RECT;	
	drawing = true;
	recentlyHit = false;
	firing = false;
	shotCount = 0;
}

void PlayerShip::HandleEvents(SDL_Event event)
{ 
	if( event.type == SDL_KEYDOWN )
  {       			
  	switch( event.key.keysym.sym )
  	{
			case SDLK_2:
				weapon->firing = true;
				weapon->Fire(Center(),Vector2D(0,-1));
				weapon->shotTimer.start();
				break;				
	  }
        
  }
    
  else if( event.type == SDL_KEYUP )
  {
	       
  	switch( event.key.keysym.sym )
  	{
			case SDLK_2: weapon->firing = false; break;	
    }
  }	

	yVel = 0;
	xVel = 0;
	frame = 1;

	SDL_PumpEvents();
	if ( Game::keystate[SDLK_UP] ) yVel -= velocity;
	if ( Game::keystate[SDLK_DOWN] ) yVel += velocity; 
	if ( Game::keystate[SDLK_LEFT] ) {frame = 0; xVel -= velocity;}
	if ( Game::keystate[SDLK_RIGHT] ) {frame = 2; xVel += velocity;}	
}

void PlayerShip::Update(Uint32 deltaTicks)
{	
	
	x += xVel * ( deltaTicks / 1000.f );
	y += yVel * ( deltaTicks / 1000.f );

	if (y < 0) y =0;
	if(y > Settings::ScreenHeight - height) y = Settings::ScreenHeight - height;
	if(x < 0) x = 0;
	if(x > Settings::ScreenWidth - width) x = Settings::ScreenWidth - width;	

	weapon->Update(Center(),Vector2D(0,-1));

	
	if (hitTimer.get_ticks() > 3000) 
	{		
		recentlyHit = false;

		hitTimer.stop();
	}

	if(recentlyHit)
	{	
		if (blinkTimer.get_ticks() > 100)
		{					
			drawing = !drawing;
			blinkTimer.start();
		}
		
	}
	else 
	{		
		drawing = true;
		blinkTimer.stop();
	}
	
}

void PlayerShip::Draw(SDL_Surface* surface)
{
	
	if(drawing)
	{
		if (Sprite::Draw(surface, sprite, x, y, frame * 120/3, 0, 120/3, 40) == false)
		{
			printf("ship not drawn successfully\n");
		}
	}
		
}

void PlayerShip::GetHit()
{
	Explosion* explosion = explosionFactory.CreateExplosion(explosionSprite, Center());
	GameObjects::Instance()->explosions.push_back(explosion);
	hitTimer.start();
	blinkTimer.start();
	recentlyHit = true;
	drawing = false;	
}

bool PlayerShip::isRecentlyHit()
{
	return recentlyHit;
}

void PlayerShip::OnPause()
{
	xVel = 0;
	yVel = 0;
	weapon->firing = false;
}







