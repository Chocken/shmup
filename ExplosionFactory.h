#ifndef EXPLOSION_FACTORY_H
#define EXPLOSION_FACTORY_H

#include "Explosion.h"
#include "SDL/SDL.h"
#include "Vector2D.h"
#include "Timer.h"

class ExplosionFactory
{
	public:
		void Init(int Frames, int Width, int Height);
		Explosion* CreateExplosion(SDL_Surface* sprite, Vector2D centerLocation);			
		Explosion CreateExpl(SDL_Surface* sprite, Vector2D centerLocation);
		SDL_Surface* sprite;
		int width;
		int height;
		int frames;
};

#endif
