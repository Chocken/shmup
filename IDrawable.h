#ifndef IDRAWABLE_H
#define IDRAWABLE_H

#include "SDL/SDL.h"

class IDrawable
{
	public:
		virtual void Draw(SDL_Surface* surface) = 0;							
};

#endif
