#include "ExplosionFactory.h"
#include <iostream>

void ExplosionFactory::Init(int Frames, int Width, int Height)
{	
	frames = Frames;
	width = Width;
	height = Height;	
}

Explosion ExplosionFactory::CreateExpl(SDL_Surface* sprite, Vector2D centerLocation)
{
	Explosion explosion = Explosion(centerLocation, width, height);
	explosion.sprite = sprite;
	explosion.frames = frames;	
	explosion.SetIsActive(true);
	return explosion;
}

Explosion* ExplosionFactory::CreateExplosion(SDL_Surface* sprite, Vector2D centerLocation)
{
	Explosion* explosion = new Explosion(centerLocation, width, height);
	explosion->sprite = sprite;
	explosion->frames = frames;	
	explosion->SetIsActive(true);
	return explosion;
}


