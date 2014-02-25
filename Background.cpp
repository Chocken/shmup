#include <iostream>
#include "Background.h"
#include "Settings.h"

float Background::DistanceScrolled()
{
	return distanceScrolled;
}

void Background::Update(Uint32 deltaTicks)
{
	y += 350 * ( deltaTicks / 1000.f );	
	distanceScrolled += 350 * ( deltaTicks / 1000.f );
	if( y >= sprite->h )
  {
  	y = 0;
  }
	
}

void Background::Init()
{
	x = 0;
	y = 0;
	width = Settings::ScreenWidth;
	height = Settings::ScreenHeight;
}

void Background::Draw(SDL_Surface* surface)
{
	if(Sprite::Draw(surface, sprite, x,y) == false || Sprite::Draw(surface, sprite, x,y - sprite->h) == false)
	{
		printf("background draw failed\n");
	}
}

void Background::Clean()
{
	SDL_FreeSurface(sprite);
}
