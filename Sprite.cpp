#include "Sprite.h"
#include "SDL/SDL_image.h"
#include <string>

Sprite::Sprite()
{
}

SDL_Surface* Sprite::Load(char File[], bool alpha)
{
	SDL_Surface* temp = NULL;
	SDL_Surface* optimized = NULL;			
	
	if((temp = IMG_Load(File)) == NULL)
	{		
		return NULL;
	}	
	
	if(alpha == true)
	{
		optimized = SDL_DisplayFormatAlpha(temp);		
	}
	else 
	{
		optimized = SDL_DisplayFormat(temp);		
	}
	
	SDL_FreeSurface(temp);

	if(optimized == NULL) printf("sprite not loaded\n");
	
	return optimized;
}

bool Sprite::Draw(SDL_Surface* dest, SDL_Surface* src, int x, int y)
{
	if(dest == NULL || src == NULL)
	{
		return false;
	}
	
	SDL_Rect destR;
	
	destR.x = x;
	destR.y = y;
	
	SDL_BlitSurface(src, NULL, dest, &destR);
	
	return true;
}

bool Sprite::Draw(SDL_Surface* dest, SDL_Surface* src, int x, int y, int alpha)
{
	if(dest == NULL || src == NULL)
	{
		return false;
	}
	
	SDL_Rect destR;
	
	destR.x = x;
	destR.y = y;	
	
	SDL_SetAlpha(src, SDL_SRCALPHA, alpha);	
	 
	SDL_BlitSurface(src, NULL, dest, &destR);
	
	return true;
}

bool Sprite::Draw(SDL_Surface* dest, SDL_Surface* src, int x, int y, int sheetX, int sheetY, int width, int height)
{
	
	if(dest == NULL || src == NULL)
	{		
		return false;
	}
	
	SDL_Rect destR;
	
	destR.x = x;
	destR.y = y;
	
	SDL_Rect srcR;
	
	srcR.x = sheetX;
	srcR.y = sheetY;	
	srcR.w = width;
	srcR.h = height;
	
	SDL_BlitSurface(src, &srcR, dest, &destR);	
	
	return true;
}
	

