#ifndef _SPRITE_H_
#define _SPRITE_H_

#include "SDL/SDL.h"
#include <string>

class Sprite
{
	public:
		Sprite();
		static SDL_Surface* Load(char File[], bool alpha);
		static bool Draw(SDL_Surface* dest, SDL_Surface* src, int x, int y);
		static bool Draw(SDL_Surface* dest, SDL_Surface* src, int x, int y, int alpha);
		static bool Draw(SDL_Surface* dest, SDL_Surface* src, int x, int y, int sheetX, int sheetY, int width, int height);		
	
};

#endif
