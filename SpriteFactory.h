#ifndef SPRITE_FACTORY_H
#define SPRITE_FACTORY_H

#include <map>
#include "SDL/SDL.h"
#include "Sprite.h"

class SpriteFactory
{
	public:
		void Init();
		std::map<const char*,SDL_Surface*> spriteMap;
};

#endif
